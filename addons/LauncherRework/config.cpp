#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F","rhsusf_c_weapons","rhsusf_main","ace_interaction","A3_Weapons_F_Tank_Launchers_MRAWS","UK3CB_BAF_Weapons_Ammo"};
        author = "TF47 Desty";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "ACE_Arsenal_Stats.hpp"