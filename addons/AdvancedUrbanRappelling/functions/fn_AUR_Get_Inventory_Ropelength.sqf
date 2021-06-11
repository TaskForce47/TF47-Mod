params ["_unit", "_rappelPoint", "_rappelDirection"];
private _unitStartPosition = [_unit, _rappelPoint, _rappelDirection] call TF47_fnc_AUR_Get_Unit_Start_Position;
private _startPositionHeight = [_unit, _unitStartPosition, _rappelPoint, _rappelDirection] call TF47_fnc_AUR_Position_GetPos_Z;
private _neededLength = _startPositionHeight + ((_startPositionHeight / 10) min 5);                 // get a length of required height plus a length of 10% or 5 meter, dependent on which value is lower
// diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (AUR_Get_Inventory_Ropelength) _unitStartPosition: ", _unitStartPosition, ", _startPositionHeight: ", _startPositionHeight, ", _neededLength: ", _neededLength];
private _unitInventoryRopes = [_unit] call TF47_fnc_AUR_Get_Unit_Inventory_Rope_Types;              // build arrays containing unit's rappelling ropes and respective lengths 
private _unitRopes = _unitInventoryRopes select 0;
private _ropeLengths = _unitInventoryRopes select 1;
private _removedRopes = [];
private _ropeLength = 0;
private ["_index", "_rope", "_length"];
while {_neededLength > 0 && ((count _unitRopes) > 0)} do {
        _index = [_ropeLengths, _neededLength] call TF47_fnc_AUR_Get_Shortest_Required_Rope_Length;// let's remove ropes somewhat intelligent
        _rope = _unitRopes select _index;
        _unit removeItem _rope;
        _removedRopes pushBack _rope;
        _length = _ropeLengths select _index;
        _neededLength = _neededLength - _length;
        _ropeLength = _ropeLength + _length;
        if (!(_rope in (items _unit))) then {
                _unitRopes deleteAt _index;
                _ropeLengths deleteAt _index;
        };
};
_unit setVariable ["AUR_Rappelling_Removed_Ropes", _removedRopes];
_ropeLength
