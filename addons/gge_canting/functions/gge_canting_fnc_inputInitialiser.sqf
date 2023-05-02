gge_canting_fnc_mouseDown = compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_mouseDown.sqf";
gge_canting_fnc_mouseUp = compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_mouseUp.sqf";

// Add rmb input check
(findDisplay 46) displayAddEventHandler ["MouseButtonDown", "_this call gge_canting_fnc_mouseDown;"];
(findDisplay 46) displayAddEventHandler ["MouseButtonUp", "_this call gge_canting_fnc_mouseUp;"];

["GGE Canting input handler succesfully initialised!"] call gge_core_fnc_debugLog;

