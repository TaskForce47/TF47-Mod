params ["_displayorcontrol", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];


if (_button == 1) then {	

	if (!gge_canting_var_toggleADSMode) then {
		call gge_canting_fnc_decantAim;
		gge_canting_var_aiming = false;
	};
	
	gge_canting_var_rmbHeld = false;
};