////////////////////////////////////////////////////////////////////
//DeRap: D:\Program Files (x86)\Steam\steamapps\common\Arma 3\!Workshop\@GGE- Captive Animations\addons\gge_captives\gge_captives\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Wed May 20 00:56:44 2020 : 'file' last modified on Wed Mar 04 12:32:02 2020
////////////////////////////////////////////////////////////////////

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
            file = "gge_captives\anim\gge_captives_anim_hvtdefault.rtm";
            looped = 1;
            speed = 1e-005;
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
            file = "gge_captives\anim\gge_captives_anim_holdhvt.rtm";
            looped = 1;
            speed = 1e-005;
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
            file = "gge_captives\anim\gge_captives_anim_holdhvtpistol.rtm";
            looped = 1;
            speed = 1e-005;
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
