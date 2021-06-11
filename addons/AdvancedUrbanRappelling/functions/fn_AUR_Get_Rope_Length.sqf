params ["_ropes"];
private _length = 0;
private ["_rope"];
{
        _rope = _x;
        {
                if (_x select 0 == _rope) exitWith {
                        _length = _length + (_x select 1);
                };
        } forEach AUR_Rappellng_Ropes;
} forEach _ropes;
// diag_log formatText ["%1%2%3", time, "s  (AUR_Get_Rope_Length) _length: ", _length];
_length
