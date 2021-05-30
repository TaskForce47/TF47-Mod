class CfgWeapons {
    class ace_hellfire_launcher;
    class tf47_ace_hellfire_launcher: ace_hellfire_launcher {
        displayName = "AGM-114K Hellfire II ""Kilo""";
        magazines[] = {
            "TF47_6Rnd_ACE_Hellfire_AGM114K", 
            "TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114K", 
            "TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114K", 
            "TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114K", 
            "TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114K", 
            "TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114K"};
        magazineWell[] += {ace_hellfire_K};
    };
    
    class tf47_ace_hellfire_launcher_N: tf47_ace_hellfire_launcher {
        displayName = "AGM-114N Hellfire II ""November""";
        magazines[] = {
            "TF47_6Rnd_ACE_Hellfire_AGM114N", 
            "TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114N", 
            "TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114N", 
            "TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114N", 
            "TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114N", 
            "TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114N"};
        magazineWell[] += {ace_hellfire_N};
    };

    class tf47_ace_hellfire_launcher_M: tf47_ace_hellfire_launcher {
        displayName = "AGM-114M Hellfire II ""Mike""";
        magazines[] = {
            "TF47_6Rnd_ACE_Hellfire_AGM114M", 
            "TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114M", 
            "TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114M", 
            "TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114M", 
            "TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114M", 
            "TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114M"};
        magazineWell[] += {ace_hellfire_M};
    };
    
    class tf47_ace_hellfire_launcher_P: tf47_ace_hellfire_launcher {
        displayName = "AGM-114P Hellfire II ""Papa""";
        magazines[] = {
            "TF47_6Rnd_ACE_Hellfire_AGM114P", 
            "TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114P", 
            "TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114P", 
            "TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114P", 
            "TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114P", 
            "TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114P"};
        magazineWell[] += {ace_hellfire_P};
    };
    
    class tf47_ace_hellfire_launcher_R: tf47_ace_hellfire_launcher {
        displayName = "AGM-114R Hellfire II ""Romeo""";
        magazines[] = {
            "TF47_6Rnd_ACE_Hellfire_AGM114R", 
            "TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114R", 
            "TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114R", 
            "TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114R", 
            "TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114R", 
            "TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114R"};
        magazineWell[] += {ace_hellfire_R};
    };
    
    class tf47_ace_hellfire_launcher_L: tf47_ace_hellfire_launcher {
        magazines[] = {
            "TF47_6Rnd_ACE_Hellfire_AGM114L", 
            "TF47_PylonMissile_1Rnd_ACE_Hellfire_AGM114L", 
            "TF47_PylonRack_1Rnd_ACE_Hellfire_AGM114L", 
            "TF47_PylonRack_2Rnd_ACE_Hellfire_AGM114L", 
            "TF47_PylonRack_3Rnd_ACE_Hellfire_AGM114L", 
            "TF47_PylonRack_4Rnd_ACE_Hellfire_AGM114L"};
        magazineWell[] += {ace_hellfire_L};
        displayName = "AGM-114L Hellfire ""Longbow""";
        ace_laser_canSelect = 0;
        ace_laser_showHud = 1;

        cursor = "EmptyCursor";
        cursorAim = "missile";
        showAimCursorInternal = 0;

        weaponLockSystem = 8;
        cmImmunity = 0.9;
        lockAcquire = 0;
        weaponLockDelay = 0.3;
        canLock = 2;
    };
};