class CfgAmmo {
    //UK3CB Jav Fix
    class rhs_ammo_M_fgm148_AT_penetrator;
    class tf47_ammo_Penetrator_Javelin: rhs_ammo_M_fgm148_AT_penetrator {
        warheadName = "TandemHEAT";
        maxSpeed = 1000;
        caliber = 75;
        
    };
    
    class ACE_Javelin_FGM148;
    class UK3CB_M_Javelin_AT: ACE_Javelin_FGM148 {
        submunitionAmmo = "tf47_ammo_Penetrator_Javelin";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.1};
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        warheadName = "TandemHEAT";
    };

};