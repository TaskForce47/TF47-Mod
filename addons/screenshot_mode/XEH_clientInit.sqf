//XEH_clientInit.sqf
#include "script_component.hpp"

if(!hasInterface) exitWith {};

GVAR(active) = false;

[
    'Gruppe Adler',
    QGVAR(toggle),
    'Toggle Screenshot Mode',
    {
        GVAR(active) = !GVAR(active);
        [!GVAR(active)] call FUNC(toggleAll);
    },
    ''
] call CBA_fnc_addKeybind;
