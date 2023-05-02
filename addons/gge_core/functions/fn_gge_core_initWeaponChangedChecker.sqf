gge_core_fnc_checkForWeaponChange = {

	// Reset weapon changed state on this frame as it has been used for all other functions by this point
	if (gge_core_var_weaponChanged) then {
		gge_core_var_weaponChanged = false;
	};
	
	gge_core_var_weaponChanged = (currentWeapon player) != gge_core_var_lastFrameWeapon;
	
	
	// reset last frame weapon holder
	gge_core_var_lastFrameWeapon = currentWeapon player;
	
	

};

if (gge_core_var_debugMode) then {systemChat "GGE Weapon Change Detection System Initialised...";};

// Return the function to be added to the main loop
[gge_core_fnc_checkForWeaponChange]