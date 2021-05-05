#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F","rhsusf_c_weapons"};
        author = "TF47 -Sonic-";
        VERSION_CONFIG;
    };
};

class CfgAmmo {
    //base class
    class SmokeShellBlue;
    class SmokeShellGreen;
    class SmokeShellOrange;
    class SmokeShellPurple;
    class SmokeShellRed;
    class SmokeShellYellow;
    class FlareBase;

    class SmokeShell{
           simulation = "shotSmoke";
           deflectionSlowDown = 0.18;
       };
    // Vanilla Smoke
    class G_40mm_Smoke: SmokeShell {
        simulation = "shotSmoke";
        deflectionSlowDown = 0.18;
    };

    // Vanilla Flare
       class F_40mm_White: FlareBase {
           intensity = 2000000;
       };
       class F_40mm_Yellow: F_40mm_White {};
       class F_40mm_Red: F_40mm_White {};
       class F_40mm_Green: F_40mm_White {};

    // RHS smoke grenades
    class rhs_40mm_smoke_green: SmokeShellGreen {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown =  0.18;
    };

    class rhs_40mm_smoke_red: SmokeShellRed {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown =  0.18;
    };

    class rhs_40mm_smoke_white: SmokeShell {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown =  0.18;
    };

    class rhs_40mm_smoke_yellow: SmokeShellYellow {
        simulation = "shotSmoke";
        deflecting = 10;
        deflectionSlowDown =  0.18;
    };
};