#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Functions_F","A3_Anims_F","cba_main"};
        author = "Goobin, edit by Rampage";
        VERSION_CONFIG;
    };
};
class CfgFunctions{

    class TF47
    {
		class COMPONENT
        {
			file = "z\TF47\addons\gge_canting\functions";
			class gge_canting_animationHandler{};
			class gge_canting_cantAim{};
			class gge_canting_decantAim{};
			class gge_canting_initCantedAiming{};
			class gge_canting_inputInitialiser{};
			class gge_canting_mouseDown{};
			class gge_canting_mouseUp{};
		};
    };
};
class CfgMovesBasic
{
	class default;
	class DefaultDie;
	class ManActions
	{
		gge_canting_anim_cantedaim[] = {"gge_canting_anim_cantedaim","gesture"};
	};
};
class CfgGesturesMale
{
	class default;
	class States
	{
		class gge_canting_anim_cantedaim: default
		{
			file = "z\TF47\addons\gge_canting\anim\gge_canting_anim_cantedaim.rtm";
			looped = 1;
			speed = 1e-05;
			mask = "handsWeapon";
			canPullTrigger = 1;
			headBobMode = 0;
			canReload = 1;
			terminal = 0;
			preload = 1;
			disableWeapons = 0;
			disableWeaponsLong = 1;
			enableBinocular = 0;
			enableMissile = 0;
			onLadder = 0;
			showHandGun = 0;
			showWeaponAim = 1;
			showItemInHand = 1;
			showItemInRightHand = 0;
			rightHandIKCurve[] = {1};
			leftHandIKCurve[] = {1};
		};
	};
};