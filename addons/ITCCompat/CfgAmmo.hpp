class CfgAmmo {
    class itc_land_155mm;
    class itc_land_155mm_m109: itc_land_155mm {
        model = "\A3\Weapons_F\Ammo\shell.p3d";
        caliber = 40;
        whistleOnFire = 1;
        whistleDist = 500;
        hit = 450;
        indirectHit = 200;
        indirectHitRange = 30;
    };
    
    class itc_land_155mm_inert_m109: itc_land_155mm_m109 {
        indirectHitRange = 1;
        indirectHit = 100;
        explosionEffects = "";
        ace_frag_enabled = 0;
        explosive = 0;
        CraterEffects = "NoCrater";
        ace_rearm_caliber = 155;
    };
    
    class itc_land_155mm_helper: itc_land_155mm_m109 {
        explosionTime = 0.0001;
    };
    
    class itc_land_155mm_dpicm_helper;
    class itc_land_155mm_dpicm_helper_m109: itc_land_155mm_dpicm_helper {
        submunitionConeType[] = {"poissondisc",100};
        submunitionAmmo[] = {
            "rhs_ammo_sub_blu97",0.3,
            "rhs_ammo_m85_submunition",0.6,
            "rhs_ammo_uxo_ao1_2_deploy",0.1
        };
    };
    
    class itc_land_155mm_dpicm_pgm_helper_m109: itc_land_155mm_dpicm_helper {
        submunitionConeType[] = {"poissondisc",100};
        submunitionAmmo[] = {
            "rhs_ammo_sub_blu97",0.3,
            "rhs_ammo_m85_submunition",0.6,
            "rhs_ammo_uxo_ao1_2_deploy",0.1
        };
    };
    
    class Mine_155mm_AMOS_range;
    class itc_land_155mm_fascam_ap_helper: Mine_155mm_AMOS_range {
        triggerTime = 0.05;
    };
    
    class AT_Mine_155mm_AMOS_range;
    class itc_land_155mm_fascam_at_helper: AT_Mine_155mm_AMOS_range {
        triggerTime = 0.05;
    };
    
    class itc_land_155mm_m712_m109: itc_land_155mm_m109 {
        model = "\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
        hit = 2000;
    };
};
