#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main"};
        author = "TF47 Desty";
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
			class fixSplashScreen
			{
				postInit=1;
			};
			class init
			{
				postInit=1;
			};
			class coreFunctions{};
			class initADSChangedChecker{};
			class initGschs{};
			class initNVGChangedChecker{};
			class initReloadChecker{};
			class initSprintChangedChecker{};
			class initStagedAnimationSystem{};
			class initStanceChangedChecker{};
			class initState{};
			class initWeaponChangedChecker{};
			class moduleLoader{};
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