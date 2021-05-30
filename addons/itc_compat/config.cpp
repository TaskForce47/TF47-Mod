#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"rhsusf_main", "rhsusf_c_troops", "A3_Armor_F_Slammer", "rhsusf_c_heavyweapons","rhsusf_c_m109","itc_land_veh_sights","itc_land_sphammohandler","itc_land_rhsusaf_m109"};
        author = "TF47 Dev Team";
        authors[] = {"TF47 -Sonic-","TF47 Desty"};
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgITCLandBalistics.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
