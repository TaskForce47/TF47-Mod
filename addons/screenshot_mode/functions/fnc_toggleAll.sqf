#include "script_component.hpp"

params [["_newState", true]];

{
    [_newState] call _x;
} forEach [
    FUNC(toggleACENametags),
    FUNC(toggleSTHud),
    FUNC(toggleTFAR),
    FUNC(toggleVanillaHUD),
    FUNC(toggleDuiHud)
];

false;
