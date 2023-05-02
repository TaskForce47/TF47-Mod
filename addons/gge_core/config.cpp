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
class CfgFunctions
{
    class TF47
    {
		class COMPONENT
        {
			file="z\TF47\addons\gge_core\functions";
			class gge_core_fixSplashScreen
			{
				postInit=1;
			};
			class gge_core_init
			{
				postInit=1;
			};
			class gge_core_coreFunctions{};
			class gge_core_initADSChangedChecker{};
			class gge_core_initGschs{};
			class gge_core_initNVGChangedChecker{};
			class gge_core_initReloadChecker{};
			class gge_core_initSprintChangedChecker{};
			class gge_core_initStagedAnimationSystem{};
			class gge_core_initStanceChangedChecker{};
			class gge_core_initState{};
			class gge_core_initWeaponChangedChecker{};
			class gge_core_moduleLoader{};
		};
	};
};

class CfgMovesBasic
{
	class default;
	class DefaultDie;
	class ManActions
	{
		gge_core_anim_clearAction[]=
		{
			"gge_core_anim_clearAction",
			"gesture"
		};
	};
};
class CfgGesturesMale
{
	class default;
	class States
	{
		class gge_core_anim_clearAction: default
		{
			file="";
			looped=0;
			speed=9.8999996;
			mask="handsWeapon";
			canPullTrigger=1;
			headBobMode=2;
			canReload=0;
			terminal=0;
			preload=1;
			disableWeapons=0;
			disableWeaponsLong=0;
			enableBinocular=0;
			enableMissile=0;
			onLadder=0;
			showHandGun=0;
			showWeaponAim=0;
			showItemInHand=1;
			showItemInRightHand=0;
			headBobStrength=0.2;
			rightHandIKCurve[]={1};
			leftHandIKCurve[]={1};
		};
	};
};

#include "CfgEventHandlers.hpp"