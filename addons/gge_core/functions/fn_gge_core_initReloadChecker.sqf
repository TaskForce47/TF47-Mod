gge_core_fnc_checkForReloadKeyDown = {
    
    _compatibleMags = [currentWeapon player] call CBA_fnc_compatibleMagazines;
    _hasMag = ({ _x in _compatibleMags; }count (magazines player)) > 0;

    _canReload = _hasMag && (vehicle player == player);

    if (((inputAction "reloadMagazine") > 0) && _canReload) then {
        gge_core_var_isReloading = true;
    };

    
    
    
    //hint str gge_core_var_isReloading;
    
    
    if (gge_core_var_weaponChanged) then {gge_core_var_isReloading = false;};
    
};

player addEventHandler ["Reloaded", {
    params ["_unit", "_weapon", "_muzzle", "_newMagazine", "_oldMagazine"];

    gge_core_var_isReloading = false;
    gge_core_var_finishedReload = true;
}];


if (gge_core_var_debugMode) then {systemChat "GGE Reload Check System Initialised...";};

// Return the function to be added to the main loop
[gge_core_fnc_checkForReloadKeyDown]