////////////////////////////////////////////////////////////////////
//DeRap: D:\Program Files (x86)\Steam\steamapps\common\Arma 3\!Workshop\@GGE- Weapon Canting\addons\gge_canting\gge_canting\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Wed May 20 01:01:50 2020 : 'file' last modified on Sun Mar 29 18:31:02 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
    class gge_canting
    {
        name = "Goobin's Gameplay Enhancements: Canted Aiming System";
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
            file = "gge_canting\anim\gge_canting_anim_cantedaim.rtm";
            looped = 1;
            speed = 1e-005;
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
class cfgMods
{
    author = "goobin";
    timepacked = "1581836348123";
};
