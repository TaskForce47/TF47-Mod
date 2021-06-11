params ["_unit", "_maxLength"];
private _ropeLength = ([_unit] call TF47_fnc_AUR_Get_Unit_Height_Above_Ground) + ((([_unit] call TF47_fnc_AUR_Get_Unit_Height_Above_Ground) / 10) min 5);        // get a length of required height plus a length of 10% or 5 meter, dependent on which value is lower
// diag_log formatText ["%1%2%3%4%5", time, "s  (AUR_Get_Needed_Ropelength) _ropeLength: ", _ropeLength];
if (_ropeLength > _maxLength) then {_ropeLength = _maxLength};
_ropeLength
