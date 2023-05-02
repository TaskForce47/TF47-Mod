#include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class gge_core
	{
		name="Goobin's Gameplay Enhancements: Core";
		author="goobin";
		authors[]=
		{
			"goobin"
		};
		url="https://www.youtube.com/channel/UC8DQqithuqvp8ny4B8pAy1A";
		version="1.0.0";
		requiredAddons[]=
		{
			"A3_Functions_F",
			"A3_Anims_F"
		};
		units[]={};
		weapons[]={};
		worlds[]={};
	};
};
class CfgFunctions
{
	class gge_core
	{
		tag="gge_core";
		class functions
		{
			file="\gge_core\functions";
			class fixSplashScreen
			{
				postInit=1;
			};
			class init
			{
				postInit=1;
			};
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
class cfgMods
{
	author="goobin";
	timepacked="1581836348123";
};
