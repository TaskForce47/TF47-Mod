class CfgMagazines {
    
    class 12Rnd_PG_missiles ;
    
    // Kilo - tandem shaped charge HEAT (anti-tank)
    class TF47_6Rnd_ACE_Hellfire_AGM114K: 12Rnd_PG_missiles  { // Old style vehicle magazine
        count = 6;
        ammo = "TF47_ACE_Hellfire_AGM114K";
        displayName = "AGM-114K [TF47]";
        displayNameShort = "AGM-114K";
        descriptionShort = "AGM-114K";
    };

    // 1.70 pylon magazines:
    class TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K: TF47_6Rnd_ACE_Hellfire_AGM114K { // Bare missile
        displayName = "1x AGM-114K [TF47]";
        count = 1;
        mass = 70;
        pylonWeapon = "tf47_ace_hellfire_launcher";
        hardpoints[] = {"SCALPEL_1RND"};
        model = "\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_m_agm114_1x";
    };
    class TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K: TF47_6Rnd_ACE_Hellfire_AGM114K { // 1x Launcher Support Rack
        displayName = "1x AGM-114K [TF47]";
        count = 1;
        mass = 85;
        pylonWeapon = "tf47_ace_hellfire_launcher";
        hardpoints[] = {"B_MISSILE_PYLON", "SCALPEL_1RND_EJECTOR", "B_ASRRAM_EJECTOR", "UNI_SCALPEL", "CUP_NATO_HELO_SMALL", "CUP_NATO_HELO_LARGE", "RHS_HP_MELB"};
        model = "\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_m_agm114_1x";
    };
    class TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K: TF47_6Rnd_ACE_Hellfire_AGM114K { // 2x Launcher Support Rack
        displayName = "2x AGM-114K [TF47]";
        count = 2;
        mass = 250;
        pylonWeapon = "tf47_ace_hellfire_launcher";
        hardpoints[] = {"B_MISSILE_PYLON", "UNI_SCALPEL", "CUP_NATO_HELO_LARGE","RHS_HP_MELB", "RHS_HP_LONGBOW_RACK", "B_MISSILE_AGM114P_2", "B_MISSILE_AGM114R"};
        model = "\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_m_agm114_2x";
        mirrorMissilesIndexes[] = {2, 1};
    };
    class TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K: TF47_6Rnd_ACE_Hellfire_AGM114K { // 3x Launcher Support Rack
        displayName = "3x AGM-114K [TF47]";
        count = 3;
        mass = 250;
        pylonWeapon = "tf47_ace_hellfire_launcher";
        hardpoints[] = {"B_MISSILE_PYLON", "UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_LONGBOW_RACK"};
        model = "\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_m_agm114_4x";
        mirrorMissilesIndexes[] = {2, 1, 3};
    };
    class TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K: TF47_6Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
        displayName = "4x AGM-114K [TF47]";
        count = 4;
        mass = 340;
        pylonWeapon = "tf47_ace_hellfire_launcher";
        hardpoints[] = {"UNI_SCALPEL", "CUP_NATO_HELO_LARGE", "RHS_HP_HELLFIRE_RACK", "RHS_HP_LONGBOW_RACK"};
        model = "\rhsusf\addons\rhsusf_airweapons\proxypylon\rhsusf_pylon_m_agm114_4x";
        mirrorMissilesIndexes[] = {2, 1, 4, 3};
    };

    // November - Metal augmented charge (Thermobaric) (Enclosures, ships, urban targets, air defense units)
    class TF47_6Rnd_ACE_Hellfire_AGM114N: TF47_6Rnd_ACE_Hellfire_AGM114K { // Old style vehicle magazine
        count = 6;
        ammo = "TF47_ACE_Hellfire_AGM114N";
        displayName = "AGM-114N [TF47]";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
    };

    // 1.70 pylon magazines:
    class TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114N: TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K { // Bare missile
        displayName = "1x AGM-114N [TF47]";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        ammo = "TF47_ACE_Hellfire_AGM114N";
        pylonWeapon = "tf47_ace_hellfire_launcher_N";
    };
    class TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114N: TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K { // 1x Launcher Support Rack
        displayName = "1x AGM-114N [TF47]";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        ammo = "TF47_ACE_Hellfire_AGM114N";
        pylonWeapon = "tf47_ace_hellfire_launcher_N";
    };
    class TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114N: TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K { // 2x Launcher Support Rack
        displayName = "2x AGM-114N [TF47]";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        ammo = "TF47_ACE_Hellfire_AGM114N";
        pylonWeapon = "tf47_ace_hellfire_launcher_N";
    };
    class TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114N: TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K { // 3x Launcher Support Rack
        displayName = "3x AGM-114N [TF47]";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        ammo = "TF47_ACE_Hellfire_AGM114N";
        pylonWeapon = "tf47_ace_hellfire_launcher_N";
    };
    class TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114N: TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
        displayName = "4x AGM-114N [TF47]";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        ammo = "TF47_ACE_Hellfire_AGM114N";
        pylonWeapon = "tf47_ace_hellfire_launcher_N";
    };
    
    // Mike - FRAG/BLAST
    class TF47_6Rnd_ACE_Hellfire_AGM114M: TF47_6Rnd_ACE_Hellfire_AGM114K { // Old style vehicle magazine
        count = 6;
        ammo = "TF47_ACE_Hellfire_AGM114M";
        displayName = "AGM-114M [TF47]";
        displayNameShort = "AGM-114M";
        descriptionShort = "AGM-114M";
    };

    // 1.70 pylon magazines:
    class TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114M: TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K { // Bare missile
        displayName = "1x AGM-114M [TF47]";
        displayNameShort = "AGM-114M";
        descriptionShort = "AGM-114M";
        ammo = "TF47_ACE_Hellfire_AGM114M";
        pylonWeapon = "tf47_ace_hellfire_launcher_M";
    };
    class TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114M: TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K { // 1x Launcher Support Rack
        displayName = "1x AGM-114M [TF47]";
        displayNameShort = "AGM-114M";
        descriptionShort = "AGM-114M";
        ammo = "TF47_ACE_Hellfire_AGM114M";
        pylonWeapon = "tf47_ace_hellfire_launcher_M";
    };
    class TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114M: TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K { // 2x Launcher Support Rack
        displayName = "2x AGM-114M [TF47]";
        displayNameShort = "AGM-114M";
        descriptionShort = "AGM-114M";
        ammo = "TF47_ACE_Hellfire_AGM114M";
        pylonWeapon = "tf47_ace_hellfire_launcher_M";
    };
    class TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114M: TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K { // 3x Launcher Support Rack
        displayName = "3x AGM-114M [TF47]";
        displayNameShort = "AGM-114M";
        descriptionShort = "AGM-114M";
        ammo = "TF47_ACE_Hellfire_AGM114M";
        pylonWeapon = "tf47_ace_hellfire_launcher_M";
    };
    class TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114M: TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
        displayName = "4x AGM-114M [TF47]";
        displayNameShort = "AGM-114M";
        descriptionShort = "AGM-114M";
        ammo = "TF47_ACE_Hellfire_AGM114M";
        pylonWeapon = "tf47_ace_hellfire_launcher_M";
    };
    
    // Papa - AGM114k for UAVs (more range)
    class TF47_6Rnd_ACE_Hellfire_AGM114P: TF47_6Rnd_ACE_Hellfire_AGM114K { // Old style vehicle magazine
        count = 6;
        ammo = "TF47_ACE_Hellfire_AGM114P";
        displayName = "AGM-114P [TF47]";
        displayNameShort = "AGM-114P";
        descriptionShort = "AGM-114P";
    };

    // 1.70 pylon magazines:
    class TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114P: TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K { // Bare missile
        displayName = "1x AGM-114P [TF47]";
        displayNameShort = "AGM-114P";
        descriptionShort = "AGM-114P";
        ammo = "TF47_ACE_Hellfire_AGM114P";
        pylonWeapon = "tf47_ace_hellfire_launcher_P";
    };
    class TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114P: TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K { // 1x Launcher Support Rack
        displayName = "1x AGM-114P [TF47]";
        displayNameShort = "AGM-114P";
        descriptionShort = "AGM-114P";
        ammo = "TF47_ACE_Hellfire_AGM114P";
        pylonWeapon = "tf47_ace_hellfire_launcher_P";
    };
    class TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114P: TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K { // 2x Launcher Support Rack
        displayName = "2x AGM-114P [TF47]";
        displayNameShort = "AGM-114P";
        descriptionShort = "AGM-114P";
        ammo = "TF47_ACE_Hellfire_AGM114P";
        pylonWeapon = "tf47_ace_hellfire_launcher_P";
    };
    class TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114P: TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K { // 3x Launcher Support Rack
        displayName = "3x AGM-114P [TF47]";
        displayNameShort = "AGM-114P";
        descriptionShort = "AGM-114P";
        ammo = "TF47_ACE_Hellfire_AGM114P";
        pylonWeapon = "tf47_ace_hellfire_launcher_P";
    };
    class TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114P: TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
        displayName = "4x AGM-114P [TF47]";
        displayNameShort = "AGM-114P";
        descriptionShort = "AGM-114P";
        ammo = "TF47_ACE_Hellfire_AGM114P";
        pylonWeapon = "tf47_ace_hellfire_launcher_P";
    };
    
    // Romeo - All in One
    class TF47_6Rnd_ACE_Hellfire_AGM114R: TF47_6Rnd_ACE_Hellfire_AGM114K { // Old style vehicle magazine
        count = 6;
        ammo = "TF47_ACE_Hellfire_AGM114R";
        displayName = "AGM-114R [TF47]";
        displayNameShort = "AGM-114R";
        descriptionShort = "AGM-114R";
    };

    // 1.70 pylon magazines:
    class TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114R: TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K { // Bare missile
        displayName = "1x AGM-114R [TF47]";
        displayNameShort = "AGM-114R";
        descriptionShort = "AGM-114R";
        ammo = "TF47_ACE_Hellfire_AGM114R";
        pylonWeapon = "tf47_ace_hellfire_launcher_R";
    };
    class TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114R: TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K { // 1x Launcher Support Rack
        displayName = "1x AGM-114R [TF47]";
        displayNameShort = "AGM-114R";
        descriptionShort = "AGM-114R";
        ammo = "TF47_ACE_Hellfire_AGM114R";
        pylonWeapon = "tf47_ace_hellfire_launcher_R";
    };
    class TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114R: TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K { // 2x Launcher Support Rack
        displayName = "2x AGM-114R [TF47]";
        displayNameShort = "AGM-114R";
        descriptionShort = "AGM-114R";
        ammo = "TF47_ACE_Hellfire_AGM114R";
        pylonWeapon = "tf47_ace_hellfire_launcher_R";
    };
    class TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114R: TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K { // 3x Launcher Support Rack
        displayName = "3x AGM-114R [TF47]";
        displayNameShort = "AGM-114R";
        descriptionShort = "AGM-114R";
        ammo = "TF47_ACE_Hellfire_AGM114R";
        pylonWeapon = "tf47_ace_hellfire_launcher_R";
    };
    class TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114R: TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
        displayName = "4x AGM-114R [TF47]";
        displayNameShort = "AGM-114R";
        descriptionShort = "AGM-114R";
        ammo = "TF47_ACE_Hellfire_AGM114R";
        pylonWeapon = "tf47_ace_hellfire_launcher_R";
    };
    
    // Lima - tandem shaped charge HEAT (anti-tank) Fire and Forget Active Radar Homing
    class TF47_6Rnd_ACE_Hellfire_AGM114L: TF47_6Rnd_ACE_Hellfire_AGM114K { // Old style vehicle magazine
        count = 6;
        ammo = "TF47_ACE_Hellfire_AGM114L";
        displayName = "AGM-114L [TF47]";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
    };

    // 1.70 pylon magazines:
    class TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114L: TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K { // Bare missile
        displayName = "1x AGM-114L [TF47]";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        ammo = "TF47_ACE_Hellfire_AGM114L";
        pylonWeapon = "tf47_ace_hellfire_launcher_L";
    };
    class TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114L: TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K { // 1x Launcher Support Rack
        displayName = "1x AGM-114L [TF47]";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        ammo = "TF47_ACE_Hellfire_AGM114L";
        pylonWeapon = "tf47_ace_hellfire_launcher_L";
    };
    class TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114L: TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K { // 2x Launcher Support Rack
        displayName = "2x AGM-114L [TF47]";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        ammo = "TF47_ACE_Hellfire_AGM114L";
        pylonWeapon = "tf47_ace_hellfire_launcher_L";
    };
    class TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114L: TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K { // 3x Launcher Support Rack
        displayName = "3x AGM-114L [TF47]";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        ammo = "TF47_ACE_Hellfire_AGM114L";
        pylonWeapon = "tf47_ace_hellfire_launcher_L";
    };
    class TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114L: TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K { // 4x Launcher Support Rack
        displayName = "4x AGM-114L [TF47]";
        displayNameShort = "AGM-114L";
        descriptionShort = "AGM-114L";
        ammo = "TF47_ACE_Hellfire_AGM114L";
        pylonWeapon = "tf47_ace_hellfire_launcher_L";
    };
};