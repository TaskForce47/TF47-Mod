params ["_unit"];
private _rope = false;
{if (_x select 0 in (items _unit)) exitWith {_rope = true}} forEach AUR_Rappellng_Ropes;
_rope
