#define _ARMA_

class CfgPatches
{
	class gge_captives
	{
		name = "Goobin's Gameplay Enhancements: Captives";
		author = "goobin";
		authors[] = {"goobin"};
		url = "https://www.youtube.com/channel/UC8DQqithuqvp8ny4B8pAy1A";
		version = "1.0.0";
		requiredAddons[] = {"A3_Functions_F","A3_Anims_F","ace_captives"};
		units[] = {};
		weapons[] = {};
		worlds[] = {};
	};
};
class CfgMovesBasic
{
	class default;
	class DefaultDie;
	class ManActions
	{
		gge_captives_anim_hvtdefault[] = {"gge_captives_anim_hvtdefault","gesture"};
		gge_captives_anim_holdhvt[] = {"gge_captives_anim_holdhvt","gesture"};
		gge_captives_anim_holdhvtpistol[] = {"gge_captives_anim_holdhvtpistol","gesture"};
	};
};
class CfgGesturesMale
{
	class default;
	class States
	{
		class gge_captives_anim_hvtdefault: default
		{
			file = "z\TF47\addons\gge_captives\anim\gge_captives_anim_hvtdefault.rtm";
			looped = 1;
			speed = 1e-05;
			mask = "handsWeapon";
			disableWeapons = 1;
			disableWeaponsLong = 1;
			weaponLowered = 0;
			showWeaponAim = 0;
			showHandGun = 0;
			canPullTrigger = 0;
			canReload = 0;
			terminal = 0;
			limitGunMovement = 0;
			preload = 1;
			headBobMode = 1;
			headBobStrength = 0.001;
			interpolateTo[] = {};
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
		};
		class gge_captives_anim_holdhvt: default
		{
			file = "z\TF47\addons\gge_captives\anim\gge_captives_anim_holdhvt.rtm";
			looped = 1;
			speed = 1e-05;
			mask = "handsWeapon";
			disableWeapons = 1;
			disableWeaponsLong = 1;
			weaponLowered = 0;
			showWeaponAim = 0;
			showHandGun = 0;
			canPullTrigger = 0;
			canReload = 0;
			terminal = 0;
			limitGunMovement = "true";
			turnSpeed = 0.1;
			limitFast = 2;
			preload = 1;
			headBobMode = 1;
			headBobStrength = 0.001;
			interpolateTo[] = {};
			leftHandIKCurve[] = {0};
		};
		class gge_captives_anim_holdhvtpistol: default
		{
			file = "z\TF47\addons\gge_captives\anim\gge_captives_anim_holdhvtpistol.rtm";
			looped = 1;
			speed = 1e-05;
			mask = "handsWeapon";
			disableWeapons = 1;
			disableWeaponsLong = 1;
			weaponLowered = 0;
			showWeaponAim = 0;
			showHandGun = 0;
			canPullTrigger = 0;
			canReload = 0;
			terminal = 0;
			limitGunMovement = "true";
			turnSpeed = 0.1;
			limitFast = 2;
			preload = 1;
			headBobMode = 1;
			headBobStrength = 0.001;
			interpolateTo[] = {};
			leftHandIKCurve[] = {0};
		};
	};
};
class cfgMods
{
	author = "goobin";
	timepacked = "1581836348123";
};
