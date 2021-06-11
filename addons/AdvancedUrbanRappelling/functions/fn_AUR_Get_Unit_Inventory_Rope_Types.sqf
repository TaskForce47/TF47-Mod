// returns the types of ropes of unit's inventory and according lengths
params ["_unit"];
private _unitRopes = [];
private _ropeLengths = [];
{
private _rope = _x select 0;
private _length = _x select 1;
if (({_x == _rope} count items _unit) > 0) then {
        _unitRopes pushBack _rope;
        _ropeLengths pushBack _length;
};
} forEach AUR_Rappellng_Ropes;        
private _unitInventoryRopes = [_unitRopes, _ropeLengths];
// diag_log formatText ["%1%2%3%4%5", time, "s  (AUR_Get_Unit_Inventory_Rope_Types) _unitInventoryRopes: ", _unitInventoryRopes];
_unitInventoryRopes
