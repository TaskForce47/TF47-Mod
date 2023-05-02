_reloading = gge_core_var_isReloading;
_holdingCaptive = missionNamespace getVariable ["gge_captives_var_isEscorting", false];
_primaryEquipped = (primaryWeapon player) == (currentWeapon player);

_canPlayDecantAimAnimation = !_reloading && !_holdingCaptive && _primaryEquipped;



if (_canPlayDecantAimAnimation && gge_canting_var_cantMode) then {
	if (gge_canting_var_cantingAim) then {
		["gge_core_anim_clearAction", false, true] call gge_core_fnc_playGesture;
		if (gge_canting_var_disableLaser) then {
			player action ["IRLaserOff", player];
		};
		if (gge_canting_var_enableGunLight) then {
			player action ["GunLightOff", player];
		};
	};
};

gge_canting_var_cantingAim = false;



