params ["_unit", "_addRopes"];
// diag_log formatText ["%1%2%3", time, "s  (AUR_Inventory_Add_Ropes) _addRopes: ", _addRopes];
if (count _addRopes == 0) exitWith {};
private _unitContainers = [(backpackContainer _unit), (vestContainer _unit), (uniformContainer _unit)];
{
        private _ropeToAdd = _x;
        {
                if (_x canAdd _ropeToAdd) exitWith {
                        _x addItemCargoGlobal [_ropeToAdd, 1];
                        _ropeToAdd = "";
                };
        } forEach _unitContainers;
        if (_ropeToAdd == "") then {_addRopes set [_forEachIndex, nil]};
} forEach _addRopes;        
private _rest = _addRopes arrayIntersect _addRopes;
if (count _rest == 0) exitWith {};                
private _str = "No room for all ropes in inventory, surplus laid on ground.";
if (isLocalized "STR_AUR_SOME_ROPES") then {_str = format[localize "STR_AUR_SOME_ROPES"]};
if (_unit == player) then {
        hint _str;
} else {
        _unit groupChat _str;        
};
private _ropePile = "groundWeaponHolder" createVehicle(getPosASL _unit);
_ropePile setPosASL (getPosASL _unit);
{
        _ropePile addItemCargoGlobal [_x, 1];
} forEach _rest;
