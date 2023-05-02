gge_canting_fnc_mouseDown = compile preprocessFileLineNumbers "z\TF47\addons\gge_canting\functions\fn_gge_canting_mouseDown.sqf";
gge_canting_fnc_mouseUp = compile preprocessFileLineNumbers "z\TF47\addons\gge_canting\functions\fn_gge_canting_mouseUp.sqf";

// Add rmb input check
(findDisplay 46) displayAddEventHandler ["MouseButtonDown", "_this call gge_canting_fnc_mouseDown;"];
(findDisplay 46) displayAddEventHandler ["MouseButtonUp", "_this call gge_canting_fnc_mouseUp;"];

["GGE Canting input handler succesfully initialised!"] call gge_core_fnc_debugLog;

