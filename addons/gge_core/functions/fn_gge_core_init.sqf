if (isDedicated) exitWith {};


gge_core_var_debugMode = false;


gge_core_fnc_debugLog = {
    params ["_message"];
    if (gge_core_var_debugMode) then {systemChat _message;};
};



// Initialise global variables
[] call compile preprocessFileLineNumbers "z\TF47\addons\gge_core\functions\fn_gge_core_initState.sqf";

// Initialise common functions
[] call compile preprocessFileLineNumbers "z\TF47\addons\gge_core\functions\fn_gge_core_coreFunctions.sqf";

// Initialise GSAS
[] call compile preprocessFileLineNumbers "z\TF47\addons\gge_core\functions\fn_gge_core_initStagedAnimationSystem.sqf";

// Initialise State Change Handler System
//_gschsInitFunctions = ([true] call compile preprocessFileLineNumbers "gge_core\functions\gschs\gschs_fnc_init.sqf");


// Core components have been loaded succesfully
["GGE Core components and systems succesfully initialised!"] call gge_core_fnc_debugLog;


// Initialise modules and store main loop functions in global variable to be accessed by main loop function
gge_core_var_mainLoopFunctions = call compile preprocessFileLineNumbers "z\TF47\addons\gge_core\functions\fn_gge_core_moduleLoader.sqf";

// Append gschs perFrame functions to main loop execution order
//gge_core_var_mainLoopFunctions append [_gschsInitFunctions select 0];

// Append reset vars function to end of execution order
(gge_core_var_mainLoopFunctions select 0) append [gge_core_fnc_perFrameResetVars];

// Stores functions to be executed in unscheduled UI space (Draw3D event)
// Initialise as UI loop functions returned from gschs
//gge_core_var_UILoopFunctions = _gschsInitFunctions select 1;

// Initialise main logic loop
gge_core_fnc_mainLoop = {

    // Call each of the functions provided to the main loop by modules
    {
        call _x;
    } foreach (gge_core_var_mainLoopFunctions select 0);

};

gge_core_fnc_mainLoop_UISpace = {
    {
        call _x;
    } foreach (gge_core_var_mainLoopFunctions select 1);
};



// call UI main loop each frame
addMissionEventHandler ["Draw3D", {
    [] call gge_core_fnc_mainLoop_UISpace;
}];

// call main loop on each frame
_handle = [gge_core_fnc_mainLoop, 0] call CBA_fnc_addPerFrameHandler;