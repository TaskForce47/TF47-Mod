gge_core_fnc_checkForStanceChange = {

	// Reset stance changed state on this frame as it has been used for all other functions by this point
	if (gge_core_var_stanceChanged) then {
		gge_core_var_stanceChanged = false;
	};
	
	_stanceChanged = !((stance player) isEqualTo (gge_core_var_lastFrameStance));
	gge_core_var_stanceChanged = _stanceChanged && (vehicle player == player);
	
	// reset last frame stance
	if (gge_core_var_stanceChanged && (vehicle player == player)) then {gge_core_var_lastFrameStance = stance player;};
	
	

};

["GGE Stance Change Detection System Initialised..."] call gge_core_fnc_debugLog;

// Return the function to be added to the main loop
[gge_core_fnc_checkForStanceChange]