// get the shortest rope, that is required for the needed length 
params ["_ropeLengths", "_neededLength"];
private _index = (count _ropeLengths) - 1;
{
        if (_x >= _neededLength) exitWith {_index = _forEachIndex};
} forEach _ropeLengths;        
_index
