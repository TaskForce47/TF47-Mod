#include "script_component.hpp"

if (!hasInterface) exitWith {};

[
    "Dismount Where You Look", "dwyl_dismount", "Dismount",
    TF47_dwyl_fnc_exit,
    {},
    [48, [false, true, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // V

[
    "Dismount Where You Look", "TF47_dwyl_showExits", "Show Exits (Hold)",
    TF47_dwyl_fnc_showExits,
    {
        [{dwyl_exit_pfh_running = false;}] call CBA_fnc_execNextFrame;
    }, [0, [false, false, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // Unbound

[
    "Dismount Where You Look", "TF47_dwyl_showAndDismount", "Show Exits And Dismount On Release",
    TF47_dwyl_fnc_showExits,
    TF47_dwyl_fnc_exit,
    [0, [false, false, false]], false                  //, 0, true
] call CBA_fnc_addKeybind; // Unbound
