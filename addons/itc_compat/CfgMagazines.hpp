class CfgMagazines {
    class itc_land_g155hex;
    class itc_land_m109hex: itc_land_g155hex {
        author = "Toadball";
        displayName = "M795 HE";
        ammo = "itc_land_155mm_m109";
        displayNameShort = "M795 HE";
        itc_land_charge_format = "itc_land_m109hex_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109hex_chg1: itc_land_m109hex { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109hex_chg2: itc_land_m109hex { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109hex_chg3: itc_land_m109hex { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109hex_chg4: itc_land_m109hex { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109hex_chg5: itc_land_m109hex { initSpeed = 425; itc_land_CountInAH = 0;  };

    class itc_land_g155icm;
    class itc_land_m109icm: itc_land_g155icm {
        author = "Toadball";
        displayName = "M864 ICM";
        ammo = "itc_land_155mm_inert_m109";
        itc_land_submunition = "itc_land_155mm_dpicm_helper_m109";
        displayNameShort = "M864 ICM";
        itc_land_charge_format = "itc_land_m109icm_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109icm_chg1: itc_land_m109icm { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109icm_chg2: itc_land_m109icm { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109icm_chg3: itc_land_m109icm { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109icm_chg4: itc_land_m109icm { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109icm_chg5: itc_land_m109icm { initSpeed = 425; itc_land_CountInAH = 0;  };



    class itc_land_g155smo;
    class itc_land_m109smo: itc_land_g155smo {
        author = "Toadball";
        displayName = "M825A1 SMOKE";
        displayNameShort = "M825A1 SMOKE";
        itc_land_charge_format = "itc_land_m109smo_chg%1";
        itc_land_timeModifier = -1.5;
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109smo_chg1: itc_land_m109smo { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109smo_chg2: itc_land_m109smo { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109smo_chg3: itc_land_m109smo { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109smo_chg4: itc_land_m109smo { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109smo_chg5: itc_land_m109smo { initSpeed = 425; itc_land_CountInAH = 0;  };

    class itc_land_g155ill;
    class itc_land_m109ill: itc_land_g155ill {
        author = "Toadball";
        displayName = "M485 ILLUM";
        displayNameShort = "M485 ILLUM";
        itc_land_charge_format = "itc_land_m109ill_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109ill_chg1: itc_land_m109ill { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109ill_chg2: itc_land_m109ill { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109ill_chg3: itc_land_m109ill { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109ill_chg4: itc_land_m109ill { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109ill_chg5: itc_land_m109ill { initSpeed = 425; itc_land_CountInAH = 0;  };



    class itc_land_g155mat;
    class itc_land_m109mat: itc_land_g155mat {
        author = "Toadball";
        displayName = "M718 MINE-AT";
        displayNameShort = "M718 MAT";
        itc_land_charge_format = "itc_land_m109mat_chg%1";
        itc_land_timeModifier = -1.2;
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109mat_chg1: itc_land_m109mat { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109mat_chg2: itc_land_m109mat { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109mat_chg3: itc_land_m109mat { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109mat_chg4: itc_land_m109mat { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109mat_chg5: itc_land_m109mat { initSpeed = 425; itc_land_CountInAH = 0;  };

    class itc_land_g155map;
    class itc_land_m109map: itc_land_g155map {
        author = "Toadball";
        displayName = "M731 MINE-AP";
        displayNameShort = "M731 MAP";
        itc_land_charge_format = "itc_land_m109map_chg%1";
        itc_land_timeModifier = -1.5;
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109map_chg1: itc_land_m109map { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109map_chg2: itc_land_m109map { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109map_chg3: itc_land_m109map { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109map_chg4: itc_land_m109map { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109map_chg5: itc_land_m109map { initSpeed = 425; itc_land_CountInAH = 0;  };



    class itc_land_g155pgm;
    class itc_land_m109pgm: itc_land_g155pgm {
        author = "Toadball";
        displayName = "M982 Excalibur Block I";
        ammo = "itc_land_155mm_m109";
        displayNameShort = "M982 HE PGM";
        itc_land_charge_format = "itc_land_m109pgm_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109pgm_chg1: itc_land_m109pgm { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109pgm_chg2: itc_land_m109pgm { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109pgm_chg3: itc_land_m109pgm { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109pgm_chg4: itc_land_m109pgm { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109pgm_chg5: itc_land_m109pgm { initSpeed = 425; itc_land_CountInAH = 0;  };
    
    class itc_land_m109icmpgm: itc_land_g155pgm {
        author = "Toadball";
        displayName = "M982 Excalibur Block II";
        ammo = "itc_land_155mm_inert_m109";
        itc_land_submunition = "itc_land_155mm_dpicm_helper_m109";
        displayNameShort = "M982 ICM PGM";
        itc_land_fuze = "mof35_mod1";
        itc_land_timeModifier = -2;
        itc_land_charge_format = "itc_land_m109icmpgm_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109icmpgm_chg1: itc_land_m109icmpgm { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109icmpgm_chg2: itc_land_m109icmpgm { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109icmpgm_chg3: itc_land_m109icmpgm { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109icmpgm_chg4: itc_land_m109icmpgm { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109icmpgm_chg5: itc_land_m109icmpgm { initSpeed = 425; itc_land_CountInAH = 0;  };



    class itc_land_g155lgm;
    class itc_land_m109lgm: itc_land_g155lgm {
        author = "Toadball";
        displayName = "M982 Excalibur S";
        ammo = "itc_land_155mm_m109";
        displayNameShort = "M982 LGM";
        itc_land_charge_format = "itc_land_m109lgm_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109lgm_chg1: itc_land_m109lgm { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109lgm_chg2: itc_land_m109lgm { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109lgm_chg3: itc_land_m109lgm { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109lgm_chg4: itc_land_m109lgm { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109lgm_chg5: itc_land_m109lgm { initSpeed = 425; itc_land_CountInAH = 0;  };
    
    class itc_land_m109lgmat: itc_land_g155lgm {
        author = "Toadball";
        displayName = "M712 Copperhead";
        ammo = "itc_land_155mm_m712_m109";
        displayNameShort = "M712 LGM AT";
        itc_land_charge_format = "itc_land_m109lgmat_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109lgmat_chg1: itc_land_m109lgmat { initSpeed = 92; itc_land_CountInAH = 0;  };
    class itc_land_m109lgmat_chg2: itc_land_m109lgmat { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109lgmat_chg3: itc_land_m109lgmat { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109lgmat_chg4: itc_land_m109lgmat { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109lgmat_chg5: itc_land_m109lgmat { initSpeed = 425; itc_land_CountInAH = 0;  };



    class itc_land_g155ext;
    class itc_land_m109ext: itc_land_g155ext {
        author = "Yax";
        displayName = "M982 Excalibur Block II w/ SADARM";
        displayNameShort = "M982 SADARM";
        itc_land_charge_format = "itc_land_m109ext_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109ext_chg1: itc_land_m109ext { initSpeed = 92;  itc_land_CountInAH = 0;  };
    class itc_land_m109ext_chg2: itc_land_m109ext { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109ext_chg3: itc_land_m109ext { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109ext_chg4: itc_land_m109ext { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109ext_chg5: itc_land_m109ext { initSpeed = 425; itc_land_CountInAH = 0;  };

    class itc_land_g155falat;
    class itc_land_m109fal: itc_land_g155falat {
        author = "Yax";
        displayName = "M982 Excalibur Block II w/ SADARM Laser";
        displayNameShort = "M982 LGM SADARM";
        itc_land_charge_format = "itc_land_m109fal_chg%1";
        itc_land_btabListFile = "itc_land_rhsusaf_m109\ballistics\tables\m109\list.sqf";
    };
    class itc_land_m109fal_chg1: itc_land_m109fal { initSpeed = 92;  itc_land_CountInAH = 0;  };
    class itc_land_m109fal_chg2: itc_land_m109fal { initSpeed = 170; itc_land_CountInAH = 0;  };
    class itc_land_m109fal_chg3: itc_land_m109fal { initSpeed = 255; itc_land_CountInAH = 0;  };
    class itc_land_m109fal_chg4: itc_land_m109fal { initSpeed = 340; itc_land_CountInAH = 0;  };
    class itc_land_m109fal_chg5: itc_land_m109fal { initSpeed = 425; itc_land_CountInAH = 0;  };

};