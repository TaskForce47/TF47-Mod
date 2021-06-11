params ["_player"];
private _rappelItems = (_player nearObjects 1.5) select {_x getVariable ["AUR_Rappel_Rope_Free", false]};
private _item = _rappelItems select 0;
private _stats = _item getVariable ["AUR_Rappel_Item_Stats", []];
if (count _stats == 0) exitWith {deleteVehicle _item};
private _partner = _stats select 0;
private _freeRope = _stats select 1;
private _rappelPoint = _stats select 2;
private _rappelDirection = _stats select 3;
// private _ropeLength = _stats select 4;
private _usedRopes = _stats select 4;
_player setVariable ["AUR_Rappelling_Removed_Ropes", _usedRopes];
private _ropeLength = [_usedRopes] call TF47_fnc_AUR_Get_Rope_Length;
private _unitPreRappelPosition = _stats select 5;
deleteVehicle _item;
deleteVehicle _partner;
ropeDestroy _freeRope;
_player setVariable ["AUR_Rappel_Attach", true];

if (abs(((getPosASL _player select 2) - (_rappelPoint select 2))) > 3) then {
        [_player, _rappelPoint, _rappelDirection, _ropeLength, _unitPreRappelPosition] call TF47_fnc_AUR_Rappel;                                                                                // player start point is at lower end
} else {
        [_player, _rappelPoint, _rappelDirection, _ropeLength] call TF47_fnc_AUR_Rappel;                                                                                                                                // player start point is at upper end
};
