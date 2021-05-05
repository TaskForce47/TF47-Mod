// Load list of module init function locations
// The modules initialised should return a list of functions (with no arguments) to be called in the main loop.


_modules = [
    ["gge_core", "gge_core\functions\gge_core_fnc_initReloadChecker.sqf"],
    ["gge_core", "gge_core\functions\gge_core_fnc_initWeaponChangedChecker.sqf"],
    ["gge_core", "gge_core\functions\gge_core_fnc_initSprintChangedChecker.sqf"],
    ["gge_core", "gge_core\functions\gge_core_fnc_initStanceChangedChecker.sqf"],
    ["gge_core", "gge_core\functions\gge_core_fnc_initADSChangedChecker.sqf"],
    ["gge_core", "gge_core\functions\gge_core_fnc_initNVGChangedChecker.sqf"],
    ["gge_nvganim", "\gge_nvganim\functions\gge_nvganim_fnc_init.sqf"],
    ["gge_captives", "\gge_captives\functions\gge_captives_fnc_init.sqf"],
    ["gge_canting", "\gge_canting\functions\gge_canting_fnc_initCantedAiming.sqf"]
];


if (gge_core_var_debugMode) then {systemChat "Module Loader Initialised...";};


_moduleCount = 0;

_returnedFunctions = [];
{

    _line = (_x select 1);
    _modulePathSplit = (_line splitString "\");
    _moduleInitFunctionName =  _modulePathSplit select ((count _modulePathSplit)-1);

    // If the module init function exists, call it. Otherwise print an error
    _modulePatchName = (_x select 0);
    if (isClass (configFile>>"CfgPatches">>_modulePatchName)) then {
        _ret = [] call compile preprocessFileLineNumbers _line; 
        
        if (!(isNil "_ret") && (typeName _ret == "ARRAY")) then {
            _returnedFunctions append _ret;
            _moduleCount = _moduleCount + 1;
            ['Module Init Function "' + _moduleInitFunctionName + '" Called...'] call gge_core_fnc_debugLog;
        } else {
            ['WARNING: No Main Loop functions returned from Module Init Function "' + _moduleInitFunctionName + '"'] call gge_core_fnc_debugLog;
        };
    } else {
        ['WARNING: Module Init Function "' + _moduleInitFunctionName + '" not found!'] call gge_core_fnc_debugLog;
    };
    
} foreach _modules;


["Module Loading Tasks Completed. " + (str _moduleCount) + " Modules Succesfully Loaded."] call gge_core_fnc_debugLog;

// Return all of the functions from loaded modules that need to be added to the main loop
_returnedFunctions