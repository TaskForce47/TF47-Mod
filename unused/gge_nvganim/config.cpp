////////////////////////////////////////////////////////////////////
//DeRap: D:\Program Files (x86)\Steam\steamapps\common\Arma 3\!Workshop\@GGE- NVG Animation\addons\gge_nvganim\gge_nvganim\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Wed May 20 00:59:15 2020 : 'file' last modified on Mon Mar 30 05:49:12 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
    class gge_nvganim
    {
        name = "Goobin's Gameplay Enhancements: NVG Animations";
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
        gge_nvganim_anim_nvgsdown[] = {"gge_nvganim_anim_nvgsdown","gesture"};
        gge_nvganim_anim_nvgsup[] = {"gge_nvganim_anim_nvgsup","gesture"};
    };
};
class CfgGesturesMale
{
    class default;
    class States
    {
        class gge_nvganim_anim_nvgsdown: default
        {
            file = "gge_nvganim\anim\gge_nvganim_anim_nvgsdown.rtm";
            looped = 0;
            speed = 1.5;
            mask = "gge_nvganim_mask_upperNoRightArm";
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
            leftHandIKCurve[] = {0};
        };
        class gge_nvganim_anim_nvgsup: default
        {
            file = "gge_nvganim\anim\gge_nvganim_anim_nvgsdown.rtm";
            looped = 0;
            speed = 1.5;
            mask = "gge_nvganim_mask_upperNoRightArm";
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
            leftHandIKCurve[] = {0};
        };
    };
    class BlendAnims
    {
        gge_nvganim_mask_upperNoRightArm[] = {"Weapon",0,"Pelvis",0,"Spine",0,"Spine1",0,"Spine2",1,"Spine3",1,"Camera",0,"launcher",0,"weapon",0,"launcher",0,"neck",1,"neck1",0,"head",0,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"RightShoulder",0,"RightArm",0,"RightArmRoll",0,"RightForeArm",0,"RightForeArmRoll",0,"RightHand",0,"LeftUpLeg",0,"LeftUpLegRoll",0,"LeftLeg",0,"LeftLegRoll",0,"LeftFoot",0,"LeftToeBase",0,"RightUpLeg",0,"RightUpLegRoll",0,"RightLeg",0,"RightLegRoll",0,"RightFoot",0,"RightToeBase",0,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHankka3ing",1,"LeftHankka3ing1",1,"LeftHankka3ing2",1,"LeftHankka3ing3",1,"LeftHandThumb",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightHandIndex1",0,"RightHandIndex2",0,"RightHandIndex3",0,"RightHandMiddle1",0,"RightHandMiddle2",0,"RightHandMiddle3",0,"RightHandPinky1",0,"RightHandPinky2",0,"RightHandPinky3",0,"RightHankka3ing",0,"RightHankka3ing1",0,"RightHankka3ing2",0,"RightHankka3ing3",0,"RightHandThumb",0,"RightHandThumb1",0,"RightHandThumb2",0,"RightHandThumb3",0};
    };
};
class cfgMods
{
    author = "goobin";
    timepacked = "1581836348123";
};