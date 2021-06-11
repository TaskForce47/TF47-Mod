params ["_player"];
private _rappelItems = (_player nearObjects 1.5) select {_x getVariable ["AUR_Rappel_Rope_Free", false]};
private _item = _rappelItems select 0;
private _stats = _item getVariable ["AUR_Rappel_Item_Stats", []];
if (count _stats == 0) exitWith {deleteVehicle _item};
private _partner = _stats select 0;
private _freeRope = _stats select 1;
// private _ropeLength = _stats select 4;
private _usedRopes = _stats select 4;
// diag_log formatText ["%1%2%3", time, "s  (AUR_Detach_Rope_Action) _usedRopes: ", _usedRopes];
deleteVehicle _item;
deleteVehicle _partner;
ropeDestroy _freeRope;
// private _inventoryRopes = [_ropeLength] call TF47_fnc_AUR_Detach_Get_Inventory_Ropes; // this needs refactoring! Rope types and lengths should be rather stored in anchor or rope end weight, instead of being calculated by rope length
// [_player, _inventoryRopes] call TF47_fnc_AUR_Inventory_Add_Ropes;
[_player, _usedRopes] call TF47_fnc_AUR_Inventory_Add_Ropes;
