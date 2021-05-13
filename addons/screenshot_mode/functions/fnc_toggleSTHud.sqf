#include "script_component.hpp"

params [["_newState", true]];

private _stHudEnabled = !(isNil "STHud_UIMode");
if (!_stHudEnabled) exitWith {};

if (_newState) then {
    STHud_UIMode = GVAR(stUIMode);
} else {
    GVAR(stUIMode) = STHud_UIMode;
    STHud_UIMode = 0;
};
