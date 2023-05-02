/*
_handleSprintChange = {
	_sprinting = _this select 0;
	
		
	if (_sprinting) then {
		if (gge_canting_var_cantingAim) then {
			call gge_canting_fnc_decantAim;
		};
	} else {
		if (gge_canting_var_aiming or gge_canting_var_rmbHeld) then {
			call gge_canting_fnc_cantAim;
		};
	};
};
["gge_core_var_isSprinting", _handleSprintChange, false] call gschs_fnc_addStateChangeHandler;



_handleReloadChange = {
	_reloading = _this select 0;
	if (!_reloading && (gge_canting_var_aiming or gge_canting_var_rmbHeld) && !gge_core_var_isSprinting) then {
		call gge_canting_fnc_cantAim;
	}; 
};
["gge_core_var_isReloading", _handleReloadChange, false] call gschs_fnc_addStateChangeHandler;
*/

// ^  GSCHS implementation not completely functional

if (gge_core_var_sprintChanged && gge_core_var_isSprinting) then {hint "Just started sprinting";};

_disableDueToSprint = (gge_core_var_sprintChanged && gge_core_var_isSprinting && gge_canting_var_cantingAim);

_recantWeapon = (
				gge_core_var_finishedReload or
				gge_core_var_sprintChanged
				) && (gge_canting_var_aiming or gge_canting_var_rmbHeld);
				
_decantWeapon = (
				gge_core_var_sprintChanged
				) && !(gge_canting_var_aiming or gge_canting_var_rmbHeld);
								
if (_recantWeapon) then {
	call gge_canting_fnc_cantAim;
};

if (_decantWeapon or _disableDueToSprint) then {
	call gge_canting_fnc_decantAim;
};
