////////////////////////////////////////////////////////////////////
//DeRap: D:\Program Files (x86)\Steam\steamapps\common\Arma 3\!Workshop\@GGE- Core\addons\gge_core\gge_core\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Wed May 20 00:53:33 2020 : 'file' last modified on Thu Mar 05 18:30:24 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
    class gge_core
    {
        name = "Goobin's Gameplay Enhancements: Core";
        author = "goobin";
        authors[] = {"goobin"};
        url = "https://www.youtube.com/channel/UC8DQqithuqvp8ny4B8pAy1A";
        version = "1.0.0";
        requiredAddons[] = {"A3_Functions_F","A3_Anims_F"};
        units[] = {};
        weapons[] = {};
        worlds[] = {};
    };
};
class CfgFunctions
{
    class gge_core
    {
        tag = "gge_core";
        class functions
        {
            file = "\gge_core\functions";
            class fixSplashScreen
            {
                postInit = 1;
            };
            class init
            {
                postInit = 1;
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
        gge_core_anim_clearAction[] = {"gge_core_anim_clearAction","gesture"};
    };
};
class CfgGesturesMale
{
    class default;
    class States
    {
        class gge_core_anim_clearAction: default
        {
            file = "";
            looped = 0;
            speed = 9.9;
            mask = "handsWeapon";
            canPullTrigger = 1;
            headBobMode = 2;
            canReload = 0;
            terminal = 0;
            preload = 1;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableBinocular = 0;
            enableMissile = 0;
            onLadder = 0;
            showHandGun = 0;
            showWeaponAim = 0;
            showItemInHand = 1;
            showItemInRightHand = 0;
            headBobStrength = 0.2;
            rightHandIKCurve[] = {1};
            leftHandIKCurve[] = {1};
        };
    };
};
class cfgMods
{
    author = "goobin";
    timepacked = "1581836348123";
};
