/*
*   Author: Tirpitz
*
* Parameters: 
*               player (object), 
*               player position, (position, array), 
*               rappelpoint (anchor to use as rappelling point) (object), 
*               rappel Direction (direction player is facing todo: detect correct direction using edge detection???) (vector, array), 
*               rope or rope Length, (available for rappel, not including the top rope length) (object or number),
*               starting on ground (bool)
* Variable description:
*                       _anchor: object that live rappelling rope is attached to. (can)          
*                       _anchor2: object free end (bottom) of rappelling rope is attached to.   (static_aa)                  
*                       _dummyAnchor: object rope from rappelling anchor to the useable anchor is attached (static_aa)   
*TODO: track all ropes ensure ropes are destroyed correctly.
*TODO: Check endpoint and anchor offsets and locations.
* maybe use some 

addMissionEventHandler ["Draw3D", {
drawIcon3D ["targetIcon.paa", [1,1,1,1], ASLToAGL getPosASL cursorTarget, 1, 1, 45, "Target", 1, 0.05, "TahomaB"];
}];
*
*/

#include "TF47_AUR_MACROS.h" //nur solang wie ben�tigt

params ["_unit", "_rappelPoint", "_rappelDirection", "_ropeLength", "_unitPreRappelPosition"];

//////////////////////////////////
//Debug
//systemChat format ["Function: Rappel, Params: %1", _this];
//hint format ["Player: %1 \nPre_rappel_position: %2, \nRappelPoint: %3 \n RappelDirection: %4,\n RopeLength: %5.", str _player,str _playerPreRappelPosition,str _rappelPoint, str _rappelDirection, str _ropeLength];
//////////////////////////////////

_unit setVariable ["AUR_Is_Rappelling", true, true];
private _unitStartPosition = getPosASL _unit;
if (isNil {_unitPreRappelPosition}) then {
        _unitPreRappelPosition = getPosASL _unit;
        _unitStartPosition = [_unit, _rappelPoint, _rappelDirection] call TF47_fnc_AUR_Get_Unit_Start_Position;
        _unit setPosWorld _unitStartPosition;
};
private _anchor = createVehicle ["Land_Can_V2_F", _unit, [], 0, "CAN_COLLIDE"];                                                                                                                        // create anchor for rope (at rappel point)
hideObject _anchor;
_anchor enableSimulation false;
_anchor allowDamage false;
[[_anchor], "AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
private _vehicle = "RoadCone_L_F";
if (isClass(configfile >> "CfgPatches" >> "ace_main")) then {_vehicle = "RoadCone_L_F"};                                                                                
// for remove the RRS effect (Random Rocket Spawn effect)
// _rappelDevice setVehicleAmmo 0;
// markooff[PGM] & Lupus the canine[PGM]
private _rappelDevice = createVehicle [_vehicle, _unit, [], 0, "CAN_COLLIDE"];                                                                                                                        // create rappel device (attached to player)
hideObject _rappelDevice;
_rappelDevice setPosWorld _unitStartPosition;
_rappelDevice allowDamage false;
[[_rappelDevice], "AUR_Hide_Object_Global"] call TF47_fnc_AUR_RemoteExecServer;
[[_unit, _rappelDevice, _anchor], "AUR_Play_Rappelling_Sounds_Global"] call TF47_fnc_AUR_RemoteExecServer;
        
private _heightDifference =  abs((_unitStartPosition select 2) - (_rappelPoint select 2));
private _topRopeStartLength = 1;
private _bottomRopeStartLength = _ropeLength - 1;
private _ropeBottom = ropeCreate [_rappelDevice, [-0.15, 0, 0], _bottomRopeStartLength];                                                                                                                                // upper start position
if (( _unit getVariable ["AUR_Rappel_Attach", false]) && _heightDifference > 3) then {
        ropeDestroy _ropeBottom;
        _topRopeStartLength = _heightDifference - 1;                                                                                                                                                                                                // if starting at lower position, first rope should be height difference between lower position and upper rappelling point, minus 1 meter; to prevent having very long ropes between climber and upper rappelling point.
        _bottomRopeStartLength = (_ropeLength - _topRopeStartLength) max 2;
        _ropeBottom = ropeCreate [_rappelDevice, [-0.15, 0, 0], _bottomRopeStartLength];                                                                                                                                        // lower start position
};
_ropeBottom allowDamage false;
private _ropeTop = ropeCreate [_rappelDevice, [0, 0.15, 0], _anchor, [0, 0, 0], _topRopeStartLength];                                                                                        // upper start position
_ropeTop allowDamage false;                
_anchor setPosWorld _rappelPoint;
// _anchor setVariable ["AUR_Rappel_Rope_Free", false];                                                                                                                                                                        // set anchor busy; only useful in case of persistent ropes; only one climber allowed per rope
_anchor setVariable ["AUR_Rappel_Rope_Free", false, true];                                                                                                                                                                // set anchor busy; only useful in case of persistent ropes; only one climber allowed per rope

_unit setVariable ["AUR_Rappel_Rope_Top", _ropeTop];
_unit setVariable ["AUR_Rappel_Rope_Bottom", _ropeBottom];
_unit setVariable ["AUR_Rappel_Rope_Length", _ropeLength];


_animationsHandle = [_unit] spawn TF47_fnc_AUR_Enable_Rappelling_Animation;

// make player face the wall he's rappelling on
_unit setVectorDir (_rappelDirection vectorMultiply -1);

private _gravityAccelerationVec = [0, 0, -9.8];
private _velocityVec = [0, 0, 0];
private _lastTime = diag_tickTime;
private _lastPosition = AGLtoASL (_rappelDevice modelToWorldVisual [0, 0, 0]);

//Setup Keys for Rappeling
private _decendRopeKeyDownHandler = -1;
private _ropeKeyUpHandler = -1;
if (_unit == player) then {        
        _decendRopeKeyDownHandler = (findDisplay 46) displayAddEventHandler ["KeyDown", {
                if (_this select 1 in (actionKeys "MoveBack")) then {
                        private _ropeLength = player getVariable ["AUR_Rappel_Rope_Length", 100];
                        private _topRope = player getVariable ["AUR_Rappel_Rope_Top", nil];
                        if (!isNil "_topRope") then {
                                if ((ropeLength _topRope) + 1 < _ropeLength) then {
                                        private _sinkRate = AUR_ADVANCED_RAPPELING_VELOCITY * 2;
                                        if (_sinkRate > 6) then {_sinkRate = 6};
                                        ropeUnwind [_topRope, _sinkRate, ((ropeLength _topRope) + (AUR_ADVANCED_RAPPELING_VELOCITY / 10)) min _ropeLength];
                                        private _bottomRope = player getVariable ["AUR_Rappel_Rope_Bottom", nil];
                                        if (!isNil "_bottomRope") then {
                                                ropeUnwind [_bottomRope, _sinkRate, ((ropeLength _bottomRope) - (AUR_ADVANCED_RAPPELING_VELOCITY / 10)) max 0];
                                        };
                                };
                        };
                };
                if (_this select 1 in (actionKeys "MoveForward")) then {
                        private _ropeLength = player getVariable ["AUR_Rappel_Rope_Length", 100];
                        private _topRope = player getVariable ["AUR_Rappel_Rope_Top", nil];
                        if (!isNil "_topRope") then {
                                private _climbVelocity = AUR_ADVANCED_RAPPELING_VELOCITY / 10;
                                if (_climbVelocity > 0.2) then {_climbVelocity = 0.2};
                                private _climbRate = AUR_ADVANCED_RAPPELING_VELOCITY;
                                if (_climbRate > 2) then {_climbRate = 2};
                                ropeUnwind [_topRope, _climbRate, ((ropeLength _topRope) - _climbVelocity) min _ropeLength];
                                private _bottomRope = player getVariable ["AUR_Rappel_Rope_Bottom", nil];
                                if (!isNil "_bottomRope") then {
                                        ropeUnwind [ _bottomRope, _climbRate, ((ropeLength _bottomRope) + _climbVelocity) max 0];
                                };
                        };
                };
                if (_this select 1 in (actionKeys "Turbo") && player getVariable ["AUR_JUMP_PRESSED_START", 0] == 0) then {
                        player setVariable ["AUR_JUMP_PRESSED_START", diag_tickTime];
                };
                if (_this select 1 in (actionKeys "TurnRight")) then {
                        player setVariable ["AUR_RIGHT_DOWN", true];
                };
                if (_this select 1 in (actionKeys "TurnLeft")) then {
                        player setVariable ["AUR_LEFT_DOWN", true];
                };
        }];
        _ropeKeyUpHandler = (findDisplay 46) displayAddEventHandler ["KeyUp", {
                if (_this select 1 in (actionKeys "Turbo")) then {
                        player setVariable ["AUR_JUMP_PRESSED", true];
                        player setVariable ["AUR_JUMP_PRESSED_TIME", diag_tickTime - (player getVariable ["AUR_JUMP_PRESSED_START", diag_tickTime])];
                        player setVariable ["AUR_JUMP_PRESSED_START", 0];        
                };
                if (_this select 1 in (actionKeys "TurnRight")) then {
                        player setVariable ["AUR_RIGHT_DOWN", false];
                };
                if (_this select 1 in (actionKeys "TurnLeft")) then {
                        player setVariable ["AUR_LEFT_DOWN", false];
                };
        }];
} else {
        [_unit] spawn {
                params ["_unit"];
                sleep 1;
                private _ropeLength = _unit getVariable ["AUR_Rappel_Rope_Length", 100];                                                                                                        // get rope length of rope in unit's inventory
                private _topRope = _unit getVariable ["AUR_Rappel_Rope_Top", nil];
                private _bottomRope = _unit getVariable ["AUR_Rappel_Rope_Bottom", nil];
                private _randomSpeedFactor = ((random 10) - 5) / 10;                                                                                                                                                // + / - 0.5 m / s random speed add
                private _sinkRate = AUR_ADVANCED_RAPPELING_VELOCITY * 2;                                                                                                                                        // set sink rate in meter per second dependent on CBA slider setting
                if (_sinkRate > 6) then {_sinkRate = 6};                                                                                                                                                                        // do not allow super human velocities
                _sinkRate = _sinkRate + _randomSpeedFactor;
                while {!isNil "_topRope" && (ropeLength _topRope) + 3 < _ropeLength && (ropeLength _bottomRope) > 3 && (getPosATL _unit select 2) > 2} do {                                        // rappel down AI unit, until rope end or less than 3 m above bottom
                        ropeUnwind [_topRope, _sinkRate, ((ropeLength _topRope) + (AUR_ADVANCED_RAPPELING_VELOCITY / 10)) min _ropeLength];
                        if (!isNil "_bottomRope") then {
                                ropeUnwind [_bottomRope, _sinkRate, ((ropeLength _bottomRope) - (AUR_ADVANCED_RAPPELING_VELOCITY / 10)) max 0];
                        };
                        sleep 0.04;
                        if (lifeState _unit != "HEALTHY" && lifeState _unit != "INJURED") exitWith {};        
                };
                if ((position _unit select 2) < 3) exitWith {_unit setVariable ["AUR_Detach_Rope", true]};                        // detach AI unit from rope, if it's height above the surface is 3 m or less, then leave spawn loop
                sleep 3;
                private _str = format ["Rope too short. Got only %1 m", _ropeLength];
                if (isLocalized "STR_ROPE_TOO_SHORT") then {_str = format[localize "STR_ROPE_TOO_SHORT", _ropeLength]};
                _unit groupChat _str;                                                                                                                        // AI omplains about rope too short
                sleep 3;
                while {!isNil "_topRope"} do {                                                                                                                                                                                                // after a short pause, AI unit will climb back up
                        private _climbVelocity = AUR_ADVANCED_RAPPELING_VELOCITY / 10;
                        if (_climbVelocity > 0.2) then {_climbVelocity = 0.2};
                        private _climbRate = AUR_ADVANCED_RAPPELING_VELOCITY;
                        if (_climbRate > 2) then {_climbRate = 2};
                        ropeUnwind [_topRope, _climbRate, ((ropeLength _topRope) - _climbVelocity) min _ropeLength];
                        if (!isNil "_bottomRope") then {
                                ropeUnwind [_bottomRope, _climbRate, ((ropeLength _bottomRope) + _climbVelocity) max 0];
                        };
                        if ((ropeLength _topRope) <= 1) exitWith {
                                sleep 1;
                                _unit setVariable ["AUR_Climb_To_Top", true];                                                                                                                                                // set true, once AI reaches top, then leave spawn loop
                        };
                        sleep 0.04;
                        if (lifeState _unit != "HEALTHY" && lifeState _unit != "INJURED") exitWith {};        
                };
        };
};

private _walkingOnWallForce = [0, 0, 0];
private _lastAiJumpTime = diag_tickTime;
private _underWater = 0;
        
while {
        alive _unit && 
        vehicle _unit == _unit && 
        ropeLength _ropeBottom > 0.5 && 
        !(_unit getVariable ["AUR_Climb_To_Top", false]) && 
        !(_unit getVariable ["AUR_Detach_Rope", false])
        // !(_unit getVariable ["AUR_Detach_Rope", false]) &&
        // lifeState _unit != "INCAPACITATED";
} do {
        private _currentTime = diag_tickTime;
        private _timeSinceLastUpdate = _currentTime - _lastTime;
        _lastTime = _currentTime;
        if (_timeSinceLastUpdate > 1) then {
                _timeSinceLastUpdate = 0;
        };

        private _environmentWindVelocity = wind;
        private _unitWindVelocity = _velocityVec vectorMultiply -1;
        private _totalWindVelocity = _environmentWindVelocity vectorAdd _unitWindVelocity;
        private _totalWindForce = _totalWindVelocity vectorMultiply (9.8 / 53);

        private _accelerationVec = _gravityAccelerationVec vectorAdd _totalWindForce vectorAdd _walkingOnWallForce;
        _velocityVec = _velocityVec vectorAdd (_accelerationVec vectorMultiply _timeSinceLastUpdate);
        private _newPosition = _lastPosition vectorAdd (_velocityVec vectorMultiply _timeSinceLastUpdate);

        if (_newPosition distance _rappelPoint > ((ropeLength _ropeTop) + 1)) then {
                _newPosition = (_rappelPoint) vectorAdd ((vectorNormalized ((_rappelPoint) vectorFromTo _newPosition)) vectorMultiply ((ropeLength _ropeTop) + 1));
                private _surfaceVector = (vectorNormalized (_newPosition vectorFromTo (_rappelPoint)));
                _velocityVec = _velocityVec vectorAdd ((_surfaceVector vectorMultiply (_velocityVec vectorDotProduct _surfaceVector)) vectorMultiply -1);
        };

        private _radius = 0.85;
        private _intersectionTests = 10;
        for "_i" from 0 to _intersectionTests do {
                private _axis1 = cos ((360 / _intersectionTests) * _i);
                private _axis2 = sin ((360 / _intersectionTests) * _i);
                {
                        private _directionUnitVector = vectorNormalized _x;
                        private _intersectStartASL = _newPosition;
                        private _intersectEndASL = _newPosition vectorAdd (_directionUnitVector vectorMultiply _radius);
                        private _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 10, "FIRE", "NONE"];
                        {
                                _x params ["_intersectionPositionASL", "_surfaceNormal", "_intersectionObject"];
                                private _objectFileName = str _intersectionObject;
                                if ((_objectFileName find "rope") == -1 && not (_intersectionObject isKindOf "RopeSegment") && (_objectFileName find " t_") == -1 && (_objectFileName find " b_") == -1) then {
                                        if (_newPosition distance _intersectionPositionASL < 1) then {
                                                _newPosition = _intersectionPositionASL vectorAdd ((vectorNormalized (_intersectEndASL vectorFromTo _intersectStartASL)) vectorMultiply (_radius));
                                        };
                                        _velocityVec = _velocityVec vectorAdd (( _surfaceNormal vectorMultiply (_velocityVec vectorDotProduct _surfaceNormal)) vectorMultiply -1);
                                };
                        } forEach _surfaces;
                } forEach [[_axis1, _axis2, 0], [_axis1, 0, _axis2], [0, _axis1, _axis2]];
        };

        private _jumpPressed = _unit getVariable ["AUR_JUMP_PRESSED", false];
        private _jumpPressedTime = _unit getVariable ["AUR_JUMP_PRESSED_TIME", 0];
        private _leftDown = _unit getVariable ["AUR_LEFT_DOWN", false];
        private _rightDown = _unit getVariable ["AUR_RIGHT_DOWN", false];

        if (_unit != player) then {                        // Simulate AI jumping off wall randomly
                if (diag_tickTime - _lastAiJumpTime > (random 30) max 5) then {
                        _jumpPressed = true;
                        _jumpPressedTime = 0;
                        _lastAiJumpTime = diag_tickTime;
                };
        };

        if (_jumpPressed || _leftDown || _rightDown) then {
                _intersectStartASL = _newPosition;
                _intersectEndASL = _intersectStartASL vectorAdd (vectorDir _unit vectorMultiply (_radius + 0.3));
                _surfaces = lineIntersectsSurfaces [_intersectStartASL, _intersectEndASL, _unit, objNull, true, 10, "GEOM", "NONE"];        // Get the surface normal of the surface the player is hanging against
                _isAgainstSurface = false;
                {
                        _x params ["_intersectionPositionASL", "_surfaceNormal", "_intersectionObject"];
                        _objectFileName = str _intersectionObject;
                        if((_objectFileName find "rope") == -1 && not (_intersectionObject isKindOf "RopeSegment") && (_objectFileName find " t_") == -1 && (_objectFileName find " b_") == -1 ) exitWith {
                                _isAgainstSurface = true;
                        };
                } forEach _surfaces;

                if (_isAgainstSurface) then {
                        if (_jumpPressed) then {
                                _jumpForce = ((( 1.5 min _jumpPressedTime ) / 1.5) * 4.5) max 2.5;
                                _velocityVec = _velocityVec vectorAdd (vectorDir _unit vectorMultiply (_jumpForce * -1));
                                _unit setVariable ["AUR_JUMP_PRESSED", false];
                        };
                        if (_rightDown) then {
                                _walkingOnWallForce = (vectorNormalized ((vectorDir _unit) vectorCrossProduct [0, 0, 1])) vectorMultiply 1;
                        };
                        if (_leftDown) then {
                                _walkingOnWallForce = (vectorNormalized ((vectorDir _unit) vectorCrossProduct [0, 0, -1])) vectorMultiply 1;
                        };
                        if (_rightDown && _leftDown) then {
                                _walkingOnWallForce = [0, 0, 0];
                        }
                } else {
                        _unit setVariable ["AUR_JUMP_PRESSED", false];
                };
        } else {
                _walkingOnWallForce = [0, 0, 0];
        };

        _rappelDevice setPosWorld (_newPosition vectorAdd (_velocityVec vectorMultiply 0.1));
        _rappelDevice setVectorDir (vectorDir _unit); 
        _unit setPosWorld (_newPosition vectorAdd [0, 0, -0.6]);
        _unit setVelocity [0, 0, 0];

        _lastPosition = _newPosition;
        _topRope = _unit getVariable ["AUR_Rappel_Rope_Top", nil];
        
        if (!isNil "_topRope" && AUR_ADVANCED_RAPPELING_ITEMS_NEEDED != 0 && (_ropeLength < ((ropeLength _topRope) -5))) then {
                _unit setVariable ["AUR_Detach_Rope", true];
        };
        
        if (eyePos _unit select 2 < -0.5) exitWith {};                                                                                                                                                                                                                // no underwater rappelling
        if (_unit != player && ropeLength _ropeTop > 3 && ropeLength _ropeTop > (((getPosASL _anchor select 2) - (getPosASL _unit select 2)) + 2)) exitWith {};        // no endless unwinding at the bottom, when rope is very long (bugs sometimes, only for AI ATM)
        // if (lifeState _unit == "INCAPACITATED") exitWith {};                                                                                                                                                                                                // detach, if unit was incapacitated
        if (lifeState _unit != "HEALTHY" && lifeState _unit != "INJURED") exitWith {};                                                                                                                                                // detach, if unit is in any other state than healthy or injured
        
        sleep 0.01;
};

if (ropeLength _ropeBottom > 1 && alive _unit && vehicle _unit == _unit && not (_unit getVariable ["AUR_Climb_To_Top", false])) then {                
        _unitStartASLIntersect = getPosASL _unit;
        _unitEndASLIntersect = [_unitStartASLIntersect select 0, _unitStartASLIntersect select 1, (_unitStartASLIntersect select 2) - 5];
        _surfaces = lineIntersectsSurfaces [_unitStartASLIntersect, _unitEndASLIntersect, _unit, objNull, true, 10];
        _intersectionASL = [];
        {
                scopeName "surfaceLoop";
                _intersectionObject = _x select 2;
                _objectFileName = str _intersectionObject;
                if ((_objectFileName find " t_") == -1 && (_objectFileName find " b_") == -1) then {
                        _intersectionASL = _x select 0;
                        breakOut "surfaceLoop";
                };
        } forEach _surfaces;
        
        if (count _intersectionASL != 0) then {
                _unit allowDamage false;
                _unit setPosASL _intersectionASL;
        };                

        if (_unit getVariable ["AUR_Detach_Rope", false]) then {
                if (count _intersectionASL == 0) then {
                        _unit allowDamage true;                // Player detached from rope. Don't prevent damage if we didn't find a position on the ground
                };        
        };
};

private _endsRope2 = ropeEndPosition _ropeBottom;
ropeDestroy _ropeTop;
ropeDestroy _ropeBottom;
deleteVehicle _rappelDevice;
if (AUR_ADVANCED_RAPPELING_ROPES_HANDLING != 2) then {deleteVehicle _anchor};
if (_unit getVariable ["AUR_Climb_To_Top", false]) then {
        _unit allowDamage false;
        _unit setPosASL _unitPreRappelPosition;
};

if (AUR_ADVANCED_RAPPELING_ITEMS_NEEDED != 0) then {
        private _usedRopes =  _unit getVariable ["AUR_Rappelling_Removed_Ropes", []];
        if (AUR_ADVANCED_RAPPELING_ROPES_HANDLING == 2) exitWith {                                                                                                                                                                                        // let's try to leave a persistent rope hanging
                private _bottomRopeEndWeight = createVehicle ["AUR_RopeSmallWeight", (getPosASL _unit), [], 0, "CAN_COLLIDE"];                                                                        // create bottom rope end weight (begin of rope, has to be a TRANSPORT physics object, see https://community.bistudio.com/wiki/ropeCreate/transport)                                                                                                                                                                                                // hide object
                _bottomRopeEndWeight allowDamage false;                                                                                                                                                                                                                        // do not allow damage
                _anchor setPosWorld _unitStartPosition;                                                                                                                                                                                                                        // briefly set anchor where unit started; for the free rope to fall nicely to the ground instead of entangling at upper rappelling position 
                private _bottomRopeEndPosition = _endsRope2 select 1;
                _bottomRopeEndPosition set [2, ((_bottomRopeEndPosition select 2) max 0) + 1];
                _bottomRopeEndWeight setPos _bottomRopeEndPosition;
                private _PersistantRope = ropeCreate [_bottomRopeEndWeight, [0, 0, 0], _anchor, [0, 0, 0], _ropeLength];                                                                                // now, create the rope from the on the ground lying device up to the anchor, which is stil attached to the original rappelling position. Thus the illusion of a free hanging rope is created.
                _PersistantRope allowDamage false;                                                                                                                                                                                                                                // do not allow damage to rope
                sleep 0.3;
                _anchor setPosWorld _rappelPoint;                                                                                                                                                                                                                                // after rope was created and fell nicely, reset anchor to it's original position
                // _anchor setVariable ["AUR_Rappel_Rope_Free", true];                                                                                                                                                                                                // set anchor free in case of persistent ropes; only one climber allowed per rope
                // _anchor setVariable ["AUR_Rappel_Item_Stats", [_bottomRopeEndWeight, _PersistantRope, _rappelPoint, _rappelDirection, _ropeLength, _unitPreRappelPosition]];        // memory anchor relevant 'stats'
                // _bottomRopeEndWeight setVariable ["AUR_Rappel_Rope_Free", true];                                                                                                                                                                                                // set rappel device busy in case of persistent ropes; only one climber allowed per rope
                // _bottomRopeEndWeight setVariable ["AUR_Rappel_Item_Stats", [_anchor, _PersistantRope, _rappelPoint, _rappelDirection, _ropeLength, _unitPreRappelPosition]];        // memory rappel device relevant 'stats'                                        
                _anchor setVariable ["AUR_Rappel_Rope_Free", true, true];                                                                                                                                                                                                // set anchor free in case of persistent ropes; only one climber allowed per rope
                // _anchor setVariable ["AUR_Rappel_Item_Stats", [_bottomRopeEndWeight, _PersistantRope, _rappelPoint, _rappelDirection, _ropeLength, _unitPreRappelPosition], true];        // memory anchor relevant 'stats'
                _anchor setVariable ["AUR_Rappel_Item_Stats", [_bottomRopeEndWeight, _PersistantRope, _rappelPoint, _rappelDirection, _usedRopes, _unitPreRappelPosition], true];        // memory anchor relevant 'stats'
                _bottomRopeEndWeight setVariable ["AUR_Rappel_Rope_Free", true, true];                                                                                                                                                                                                // set rappel device busy in case of persistent ropes; only one climber allowed per rope
                // _bottomRopeEndWeight setVariable ["AUR_Rappel_Item_Stats", [_anchor, _PersistantRope, _rappelPoint, _rappelDirection, _ropeLength, _unitPreRappelPosition], true];        // memory rappel device relevant 'stats'                                        
                _bottomRopeEndWeight setVariable ["AUR_Rappel_Item_Stats", [_anchor, _PersistantRope, _rappelPoint, _rappelDirection, _usedRopes, _unitPreRappelPosition], true];        // memory rappel device relevant 'stats'                                        
                // diag_log formatText ["%1%2%3", time, "s  (AUR_Rappel) _usedRopes: ", _usedRopes];
        };

        // private _usedRopes =  _unit getVariable ["AUR_Rappelling_Removed_Ropes", []];
        if (count _usedRopes == 0 ) exitWith {};
        
        if (AUR_ADVANCED_RAPPELING_ROPES_HANDLING == 0) then {                                                                                                                                                                                                // If CBA setting 'Ropes Handling After Rappelling' says 'Always Keep In Inventory', once rappelling unit arrives at the bottom, add used ropes to units inventory        
                [_unit, _usedRopes] call TF47_fnc_AUR_Inventory_Add_Ropes;
        };
        if (AUR_ADVANCED_RAPPELING_ROPES_HANDLING == 1) then {                                                                                                                                                                                                // If CBA setting 'Ropes Handling After Rappelling' says 'Leave Ropes At Start', once rappelling unit arrives at the bottom, and pile up those used at upper starting point
                _topRope = _unit getVariable ["AUR_Rappel_Rope_Top", nil];
                if (!isNil "_topRope" && !(_unit getVariable ["AUR_Rappel_Attach", false])) then {
                        if (_unit getVariable ["AUR_Climb_To_Top", false]) then {
                                [_unit, _usedRopes] call TF47_fnc_AUR_Inventory_Add_Ropes;
                        } else {
                                private _ropePile = "groundWeaponHolder" createVehicle _unitPreRappelPosition;
                                _ropePile setPosASL _unitPreRappelPosition;
                                {
                                        _ropePile addItemCargoGlobal [_x, 1];
                                } forEach _usedRopes;                
                        };
                };
        };
};

_unit setVariable ["AUR_Is_Rappelling", nil, true];
_unit setVariable ["AUR_Rappel_Rope_Top", nil];
_unit setVariable ["AUR_Rappel_Rope_Bottom", nil];
_unit setVariable ["AUR_Rappel_Rope_Length", nil];
_unit setVariable ["AUR_Climb_To_Top", nil];
_unit setVariable ["AUR_Detach_Rope", nil];
_unit setVariable ["AUR_Animation_Move", nil, true];
_unit setVariable ["AUR_Rappel_Attach", nil];
_unit setVariable ["AUR_Rappelling_Removed_Ropes", nil];

if (_decendRopeKeyDownHandler != -1) then {                        
        (findDisplay 46) displayRemoveEventHandler ["KeyDown", _decendRopeKeyDownHandler];
};

sleep 1;
_unit allowDamage true;