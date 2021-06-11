/*
Description:
Finds the nearest rappel point within 1.5m of the specified player.

Parameter(s):
_this select 0: OBJECT - The rappelling unit
_this select 1: STRING - Search type - "FAST_EXISTS_CHECK" or "POSITION". If FAST_EXISTS_CHECK, this function
        does a quicker search for rappel points and return 1 if a possible rappel point is found, otherwise 0.
        If POSITION, the function will return the rappel position and direction in an array, or empty array if
        no position is found.
        
Returns: 
Number or Array (see above)
*/
params ["_unit", ["_searchType", "FAST_EXISTS_CHECK"]];
private _unitPosition = getPosASL _unit;
private _intersectionRadius = 1.5;
private _intersectionDistance = 4;
private _intersectionTests = 40;
if (_searchType == "FAST_EXISTS_CHECK") then {_intersectionTests = 8};
private _lastIntersectStartASL = [];
private _lastIntersectionIntersected = false;
private _edges = [];
private _edge = [];
private _fastExistsEdgeFound = false;                
private ["_Xcoord", "_Ycoord", "_directionUnitVector", "_intersectStartASL", "_intersectEndASL", "_surfaces"];
for "_i" from 0 to _intersectionTests do {                                                                   // Search for nearby edges
        _Xcoord = cos ((360 / _intersectionTests) * _i);
        _Ycoord = sin ((360 / _intersectionTests) * _i);
        _directionUnitVector = vectorNormalized [_Xcoord, _Ycoord, 0];
        _intersectStartASL = _unitPosition vectorAdd (_directionUnitVector vectorMultiply _intersectionRadius) vectorAdd [0, 0, 1.5];
        //_m1 = createVehicle ["Sign_Sphere25cm_F", ASLToATL _intersectStartASL , [], 0, "CAN_COLLIDE"];
        _intersectEndASL = _intersectStartASL vectorAdd [0, 0, -5];
        //_m2 = createVehicle ["Sign_Sphere25cm_F", ASLToATL _intersectEndASL , [], 0, "CAN_COLLIDE"];
        _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 1];
        if (_searchType == "FAST_EXISTS_CHECK") then {
                if (count _surfaces == 0) exitWith {_fastExistsEdgeFound = true};
        } else {
                if (count _surfaces > 0) then {
                        if (!_lastIntersectionIntersected && _i != 0) then {
                                // Moved from edge to no edge (edge end)
                                _edge pushBack _lastIntersectStartASL;
                                _edges pushBack _edge;
                        };
                        _lastIntersectionIntersected = true;
                } else {
                        if (_lastIntersectionIntersected && _i != 0) then {
                                // Moved from no edge to edge (edge start)
                                _edge = [_intersectStartASL];
                                if (_i == _intersectionTests) then {
                                        _edges pushBack _edge;
                                };
                        };
                        _lastIntersectionIntersected = false;
                };
                _lastIntersectStartASL = _intersectStartASL;
        };
};

if (_searchType == "FAST_EXISTS_CHECK") exitWith {_fastExistsEdgeFound};

private ["_firstEdge", "_edgeDistance"];
if (count _edge == 1) then {                                                                              // If edges found, return nearest edge
        _firstEdge = _edges deleteAt 0;
        _edges deleteAt (count _edges - 1);
        _edges pushBack (_edge + _firstEdge);
};

private _largestEdgeDistance = 0;
private _largestEdge = [];
{
        _edgeDistance = (_x select 0) distance (_x select 1);
        if (_edgeDistance > _largestEdgeDistance) then {
                _largestEdgeDistance = _edgeDistance;
                _largestEdge = _x;
        };
} forEach _edges;

if (count _largestEdge > 0) then {
        private _edgeStart = (_largestEdge select 0);
        _edgeStart set [2, getPosASL _unit select 2];
        private _edgeEnd = (_largestEdge select 1);
        _edgeEnd set [2, getPosASL _unit select 2];
        private _edgeMiddle = _edgeStart vectorAdd ((_edgeEnd vectorDiff _edgeStart) vectorMultiply 0.5);
        private _edgeDirection = vectorNormalized ((_edgeStart vectorFromTo _edgeEnd) vectorCrossProduct [0, 0, 1]);
        
        // Check to see if there's a surface we can attach the rope to (so it doesn't hang in the air)
        _unitPositionASL = getPosASL _unit;
        private _intersectStartASL = _unitPositionASL vectorAdd ((_unitPositionASL vectorFromTo _edgeStart) vectorMultiply (_intersectionRadius));
        _intersectEndASL = _intersectStartASL vectorAdd ((_intersectStartASL vectorFromTo _unitPositionASL) vectorMultiply (_intersectionRadius * 2)) vectorAdd [0, 0, -0.5];
        _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 1, "FIRE", "NONE"];
        if (count _surfaces > 0) then {
                _edgeStart = (_surfaces select 0) select 0;
        };
        
        _intersectStartASL = _unitPositionASL vectorAdd ((_unitPositionASL vectorFromTo _edgeEnd) vectorMultiply (_intersectionRadius));
        _intersectEndASL = _intersectStartASL vectorAdd ((_intersectStartASL vectorFromTo _unitPositionASL) vectorMultiply (_intersectionRadius * 2)) vectorAdd [0, 0, -0.5];
        _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 1, "FIRE", "NONE"];
        if (count _surfaces > 0) then {
                _edgeEnd = (_surfaces select 0) select 0;
        };
        
        _intersectStartASL = _unitPositionASL vectorAdd ((_unitPositionASL vectorFromTo _edgeMiddle) vectorMultiply (_intersectionRadius));
        _intersectEndASL = _intersectStartASL vectorAdd ((_intersectStartASL vectorFromTo _unitPositionASL) vectorMultiply (_intersectionRadius * 2)) vectorAdd [0, 0, -0.5];
        _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 1, "FIRE", "NONE"];
        if (count _surfaces > 0) then {
                _edgeMiddle = (_surfaces select 0) select 0;
        };
        
        // Check to make sure there's an opening for rappelling (to stop people from rappelling through a wall)
        _intersectStartASL = _unitPosition vectorAdd [0, 0, 1.5];
        _intersectEndASL = _intersectStartASL vectorAdd (_edgeDirection vectorMultiply 4);
        _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 1, "FIRE", "NONE"];
        if (count _surfaces > 0) exitWith {[]};

        [_edgeMiddle, _edgeDirection, [_edgeStart, _edgeEnd, _edgeMiddle]];
} else {
        [];
};
