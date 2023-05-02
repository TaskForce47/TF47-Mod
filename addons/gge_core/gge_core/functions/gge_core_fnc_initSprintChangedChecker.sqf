gge_core_fnc_checkForSprintChange = {

	// Reset NVG changed state on this frame as it has been used for all other functions by this point
	if (gge_core_var_sprintChanged) then {
		gge_core_var_sprintChanged = false;
	};
	
	gge_core_var_isSprinting = ("amovpercmevasraswrfldf" in (animationState player));
	
	_sprintChanged = ("amovpercmevasraswrfldf" in gge_core_var_lastFrameAnimationState) && !gge_core_var_isSprinting;
	gge_core_var_sprintChanged = _sprintChanged && (vehicle player == player);
	
	// reset last frame animation state
	gge_core_var_lastFrameAnimationState = animationState player;
	

};

["GGE Sprint State Change Detection System Initialised..."] call gge_core_fnc_debugLog;

// Return the function to be added to the main loop
[gge_core_fnc_checkForSprintChange]