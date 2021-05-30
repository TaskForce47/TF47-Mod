//XEH_clientInit.sqf
#include "script_component.hpp"

if(!hasInterface) exitWith {};

GVAR(active) = false;

[
    localize "STR_TF47_Screenshot_Mode",
    QGVAR(toggle),
    localize "STR_TF47_Screenshot_Mode_Toggle",
    {
        GVAR(active) = !GVAR(active);
        [!GVAR(active)] call FUNC(toggleAll);
    },
    ''
] call CBA_fnc_addKeybind;
