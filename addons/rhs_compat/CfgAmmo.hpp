class CfgAmmo {
    //UK3CB Jav Fix
    class ACE_Javelin_FGM148;
    class UK3CB_M_Javelin_AT: ACE_Javelin_FGM148 {
        submunitionAmmo = "rhs_ammo_M_fgm148_AT_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        warheadName = "TandemHEAT";
    };

    class ammo_Penetrator_base;
    class UK3CB_ammo_Penetrator_Javelin: ammo_Penetrator_base {
        warheadName = "TandemHEAT";
    };
    
    //Smoke Fix
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