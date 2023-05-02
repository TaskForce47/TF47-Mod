// Load list of module init function locations
// The modules initialised should return a list of functions (with no arguments) to be called in the main loop.


_modules = [
    ["gge_core", "z\TF47\addons\gge_core\functions\fn_gge_core_initReloadChecker.sqf"],
    ["gge_core", "z\TF47\addons\gge_core\functions\fn_gge_core_initWeaponChangedChecker.sqf"],
    ["gge_core", "z\TF47\addons\gge_core\functions\fn_gge_core_initSprintChangedChecker.sqf"],
    ["gge_core", "z\TF47\addons\gge_core\functions\fn_gge_core_initStanceChangedChecker.sqf"],
    ["gge_core", "z\TF47\addons\gge_core\functions\fn_gge_core_initADSChangedChecker.sqf"],
    ["gge_core", "z\TF47\addons\gge_core\functions\fn_gge_core_initNVGChangedChecker.sqf"],
    ["gge_nvganim", "z\TF47\addons\gge_nvganim\functions\fn_gge_nvganim_init.sqf"],
    ["gge_captives", "z\TF47\addons\gge_captives\functions\fn_gge_captives_init.sqf"],
    ["gge_canting", "z\TF47\addons\gge_canting\functions\fn_gge_canting_initCantedAiming.sqf"],
    ["gge_swap", "z\TF47\addons\gge_swap\functions\fn_gge_swap_init.sqf", true]
];

if (gge_core_var_debugMode) then {systemChat "Module Loader Initialised...";};


_moduleCount = 0;

_returnedFunctions = [];
_returnedUIFunctions = [];
{

    _line = (_x select 1);
    _modulePathSplit = (_line splitString "\");
    _moduleInitFunctionName =  _modulePathSplit select ((count _modulePathSplit)-1);

    _isUISpace = false;
    if (count _x > 2) then {
        _isUISpace = _x select 2;
    };
    
    // If the module init function exists, call it. Otherwise print an error
    _modulePatchName = (_x select 0);
    if (isClass (configFile>>"CfgFunctions">>"TF47">>_modulePatchName)) then {
        _ret = [] call compile preprocessFileLineNumbers _line; 
        
        if (!(isNil "_ret") && (typeName _ret == "ARRAY")) then {
            if (_isUISpace) then {
                _returnedUIFunctions append _ret;
            } else {
                _returnedFunctions append _ret;
            };
            _moduleCount = _moduleCount + 1;
            ['Module Init Function "' + _moduleInitFunctionName + '" Called...'] call gge_core_fnc_debugLog;
        } else {
            ['WARNING: No Main Loop functions returned from Module Init Function "' + _moduleInitFunctionName + '"'] call gge_core_fnc_debugLog;
        };
    } else {
        ['WARNING: Class Module "' + _modulePatchName + '" not found!'] call gge_core_fnc_debugLog;
        ['Tried to call Module Init Function "' + _moduleInitFunctionName + '"!!!'] call gge_core_fnc_debugLog;
        ['WARNING: Module Init Function "' + _moduleInitFunctionName + '" not found!'] call gge_core_fnc_debugLog;
    };
    
} foreach _modules;


["Module Loading Tasks Completed. " + (str _moduleCount) + " Modules Succesfully Loaded."] call gge_core_fnc_debugLog;

// Return all of the functions from loaded modules that need to be added to the main loop
[_returnedFunctions, _returnedUIFunctions]