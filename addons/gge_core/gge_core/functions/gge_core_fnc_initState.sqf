gge_core_var_initStateInitialised = false;
gge_core_var_gestureJustPlayed = false;
gge_core_var_isReloading = false;
gge_core_var_isSprinting = false;
gge_core_var_finishedReload = false;
gge_core_var_sprintChanged = false;
gge_core_var_weaponChanged = false;
gge_core_var_stanceChanged = false;
gge_core_var_NVGChanged = false;
gge_core_var_ADSChanged = false;


gge_core_var_lastFrameWeapon = currentWeapon player;
gge_core_var_lastFrameStance = stance player;
gge_core_var_lastFrameAnimationState = animationState player;
gge_core_var_lastFrameVisionMode = currentVisionMode player;
gge_core_var_lastFrameCameraView = cameraView;





gge_core_fnc_perFrameResetVars = {
	gge_core_var_gestureJustPlayed = false;
	gge_core_var_finishedReload = false;
};



gge_core_var_initStateInitialised = true;
["GGE Core global variables initialised..."] call gge_core_fnc_debugLog;
