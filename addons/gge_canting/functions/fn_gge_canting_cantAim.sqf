
_reloading = gge_core_var_isReloading;
_sprinting = gge_core_var_isSprinting;
_canADS = (getNumber (configfile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "enableOptics")) > 0;
_holdingCaptive = missionNamespace getVariable ["gge_captives_var_isEscorting", false];
_primaryEquipped = (primaryWeapon player) == (currentWeapon player);
_notInVehicle = (vehicle player) == player;
_notProne = !(stance player == "PRONE");
_isUnconscious = player getVariable ["ACE_isUnconscious", false];

_canPlayCantingAnim = (
	!_reloading && 
	!_sprinting &&
	!_holdingCaptive && 
	_canADS && 
	_primaryEquipped && 
	_notInVehicle && 
	_notProne &&
	!_isUnconscious);

if (_canPlayCantingAnim && gge_canting_var_cantMode) then {
	_fireMode = (weaponState player) select 2;
	
	
	gge_canting_var_cantingAim = true;
	["gge_canting_anim_cantedaim", false, true] call gge_core_fnc_playGesture;
	player action ["IRLaserOn", player];
	if (gge_canting_var_enableGunLight) then {
		player action ["GunLightOn", player];
	};
	
	// Using KK's fire mode switch fix
	_weapon = currentWeapon player;
	_ammo = player ammo _weapon;
	player setAmmo [_weapon, 0];
	player forceWeaponFire [_weapon, _fireMode];
	player setAmmo [_weapon, _ammo];
	
};