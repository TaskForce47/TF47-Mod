/*
was macht es?
war auskommentiert...
*/
params ["_ropeLength"];
private _inventoryRopes = [];
private ["_closest", "_rope", "_curRopeLength"];
while {_ropeLength > 5} do {
        _closest = -1;
        _rope = "none";
        {
                _curRopeLength = _x select 1;
                if (abs(_ropeLength - _closest) > abs(_curRopeLength - _ropeLength)) then {
                        _closest = _curRopeLength;
                        _rope = _x select 0;
                };
                if (abs(_ropeLength - _closest) == 0) exitWith {};
        } forEach AUR_Rappellng_Ropes;
        _ropeLength = _ropeLength - _closest;
        if (_rope != "none") then {_inventoryRopes pushBack _rope};
};
_inventoryRopes
