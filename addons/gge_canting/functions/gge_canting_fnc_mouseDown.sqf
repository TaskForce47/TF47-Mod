params ["_displayorcontrol", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];

if (_button == 1) then {
	
	if (gge_canting_var_toggleADSMode && gge_canting_var_cantingAim) then {
		gge_canting_var_aiming = false;
		call gge_canting_fnc_decantAim;
		
	} else {
	
		
		if (gge_canting_var_cantMode) then {
			call gge_canting_fnc_cantAim;
		} else {
			call gge_canting_fnc_handleADS;
		};
		
		gge_canting_var_aiming = true;
		
		gge_canting_var_rmbHeld = true;
	};
	
	
};