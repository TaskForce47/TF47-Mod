gge_core_fnc_checkForNVGChange = {

	// Reset NVG changed state on this frame as it has been used for all other functions by this point
	if (gge_core_var_NVGChanged) then {
		gge_core_var_NVGChanged = false;
	};
	
	_visionModeChanged = !((currentVisionMode player) isEqualTo gge_core_var_lastFrameVisionMode);
	gge_core_var_NVGChanged = _visionModeChanged && (vehicle player == player);
	
	// reset last frame vision mode
	if (gge_core_var_NVGChanged) then {gge_core_var_lastFrameVisionMode = (currentVisionMode player);};
	

};

["GGE NVG State Change Detection System Initialised..."] call gge_core_fnc_debugLog;

// Return the function to be added to the main loop
[gge_core_fnc_checkForNVGChange]