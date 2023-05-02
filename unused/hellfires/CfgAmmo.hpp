class CfgAmmo {
    class M_Scalpel_AT ;
    class ACE_Hellfire_AGM114K: M_Scalpel_AT {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
    };
    
    class ACE_Hellfire_AGM114K;
    class TF47_ACE_Hellfire_AGM114K: ACE_Hellfire_AGM114K {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
        submunitionAmmo = "rhs_ammo_Hellfire_AT_penetrator";
        
        cameraViewAvailable = 1;
        
        displayName = "AGM-114K";
        displayNameShort = "AGM-114K";
        description = "AGM-114K";
        descriptionShort = "AGM-114K";
        
        effectsMissile = "missile2";

        trackLead = 1;
        trackOversteer = 1;
        
        irLock = 0;
        laserLock = 0;
        manualControl = 0;
        maxSpeed = 450;

        thrustTime = 2.5; // motor burn 2-3 sec
        thrust = 250;
        timeToLive = 40;
        
        flightProfiles[] = {};
            
        class ace_missileguidance {
            enabled = 1;

            minDeflection = 0.0005;     // Minium flap deflection for guidance
            maxDeflection = 0.01;       // Maximum flap deflection for guidance
            incDeflection = 0.0005;     // The incrmeent in which deflection adjusts.

            canVanillaLock = 0;         // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH", "LIDAR", "SARH", "Optic", "Thermal", "GPS", "SACLOS", "MCLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            seekLastTargetPos = 1;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 70;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 1;
            seekerMaxRange = 8000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "hellfire";
            attackProfiles[] = {"hellfire", "hellfire_hi", "hellfire_lo"};
        };
        
        ace_frag_enabled = 1;
        ace_frag_classes[] = {"ace_frag_medium","ace_frag_medium_HD"};
        ace_frag_metal = 4000;
        ace_frag_charge = 3400;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
        
        class TopDown{};
        
        class Components
        {
            class SensorsManagerComponent
            {
                class Components
                {
                    class LaserSensorComponent
                    {
                        class AirTarget
                        {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget
                        {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        maxTrackableSpeed = 55;
                        angleRangeHorizontal = 90;
                        angleRangeVertical = 70;
                        componentType = "LaserSensorComponent";
                        typeRecognitionDistance = 0;
                        color[] = {1,1,1,0};
                        allowsMarking = 1;
                        groundNoiseDistanceCoef = -1;
                        maxGroundNoiseDistance = -1;
                        minSpeedThreshold = 0;
                        maxSpeedThreshold = 0;
                        animDirection = "";
                        aimDown = 0;
                        minTrackableSpeed = -1e+010;
                        minTrackableATL = -1e+010;
                        maxTrackableATL = 1e+010;
                    };
                };
            };
        };
    };
    
    class TF47_ACE_Hellfire_AGM114N: TF47_ACE_Hellfire_AGM114K {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
        submunitionAmmo = "";
        
        displayName = "AGM-114N";
        displayNameShort = "AGM-114N";
        description = "AGM-114N";
        descriptionShort = "AGM-114N";
        
        warheadName = "HE";
        ace_frag_enabled = 0;
        ace_frag_skip = 1;
        hit = 200;
        indirectHit = 200;
        indirectHitRange = 20;
        explosive = 1;
        
        explosionEffects = "BombExplosion";
        class ace_missileguidance: ace_missileguidance {
            enabled = 1; // Missile Guidance must be explicitly enabled
        };
    };
    
    class TF47_ACE_Hellfire_AGM114M: TF47_ACE_Hellfire_AGM114K {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
        submunitionAmmo = "";
        
        displayName = "AGM-114M";
        displayNameShort = "AGM-114M";
        description = "AGM-114M";
        descriptionShort = "AGM-114M";
        
        ace_frag_enabled = 1;
        ace_frag_classes[] = {"ace_frag_medium","ace_frag_medium_HD"};
        ace_frag_metal = 12000;
        ace_frag_charge = 4000;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
        warheadName = "HE";
        indirectHit = 100;
        indirectHitRange = 5;
        explosive = 1;
        
        explosionEffects = "BombExplosion";
        class ace_missileguidance: ace_missileguidance {
            enabled = 1; // Missile Guidance must be explicitly enabled
        };
    };
    
    class TF47_ACE_Hellfire_AGM114L: TF47_ACE_Hellfire_AGM114K {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
        submunitionAmmo = "rhs_ammo_Hellfire_AT_penetrator";
        
        displayName = "AGM-114L";
        displayNameShort = "AGM-114L";
        description = "AGM-114L";
        descriptionShort = "AGM-114L";
        class ace_missileguidance: ace_missileguidance {
            canVanillaLock = 1;
            enabled = 1; // Missile Guidance must be explicitly enabled
            seekLastTargetPos = 1;
            defaultSeekerType = "ARH";
            seekerTypes[] = { "ARH" };
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };
            
            seekerAngle = 130;
            
            // Attack profile type selection
            defaultAttackProfile = "hellfire";
            attackProfiles[] = {"hellfire", "hellfire_hi", "hellfire_lo"};

            activeRadarEngageDistance = 2000;
            seekerMaxRange = 2000; // distance that the hellfire internal radar can scan
        };

        // Vanilla lock system vars
        weaponLockSystem = "8";
        airLock = 1;
        lockType = 0;
        laserLock = 0;
        maneuvrability = 0; // no maneuvrability so that default guidance doesnt work

        missileLockMaxDistance = 8000;
        missileLockMinDistance = 250;
        missileLockMaxSpeed = 50;
        missileLockCone = 130;
        missileKeepLockedCone = 130;
        
        autoSeekTarget = 1;
        lockSeekRadius = 1000;
    

        flightProfiles[] = {};
        
        class Components
        {
            class SensorsManagerComponent
            {
                class Components
                {
                    class MillimeterWaveRadar
                    {
                        componentType = "ActiveRadarSensorComponent";
                        class AirTarget
                        {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget
                        {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        allowsMarking = 1;
                        aimDown = 0;
                        typeRecognitionDistance = 4000;
                        angleRangeHorizontal = 130;
                        angleRangeVertical = 130;
                        groundNoiseDistanceCoef = -1;
                        maxGroundNoiseDistance = -1;
                        minSpeedThreshold = 0;
                        maxSpeedThreshold = 0;
                        maxFogSeeThrough = 0.8;
                        minTrackableSpeed = -1e+010;
                        maxTrackableSpeed = 1e+010;
                        minTrackableATL = -1e+010;
                        maxTrackableATL = 1e+010;
                        nightRangeCoef = 1;
                        maxFogSeeThrough = 0.8;
                    };
                };
            };
        };

    };
    
    class TF47_ACE_Hellfire_AGM114P: TF47_ACE_Hellfire_AGM114K {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
        submunitionAmmo = "rhs_ammo_Hellfire_AT_penetrator";
        thrustTime = 5;
        
        displayName = "AGM-114P";
        displayNameShort = "AGM-114P";
        description = "AGM-114P";
        descriptionShort = "AGM-114P";
        
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            minDeflection = 0.0005;
            maxDeflection = 0.01;
            incDeflection = 0.0005;
            canVanillaLock = 0;
            defaultSeekerType = "SALH";
            seekerTypes[] = {"SALH","LIDAR","SARH","Optic","Thermal","GPS","SACLOS","MCLOS"};
            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = {"LOAL","LOBL"};
            seekLastTargetPos = 1;
            seekerAngle = 100;
            seekerAccuracy = 1;
            seekerMinRange = 1;
            seekerMaxRange = 12000;
            defaultAttackProfile = "hellfire";
            attackProfiles[] = {"hellfire","hellfire_hi","hellfire_lo"};
        };
    };
    
    class TF47_ACE_Hellfire_AGM114R: TF47_ACE_Hellfire_AGM114K {
        model = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K_fly";
        proxyShape = "\rhsusf\addons\rhsusf_airweapons\proxyammo\rhsusf_m_AGM114K";
        submunitionAmmo = "rhs_ammo_Hellfire_AT_penetrator";
        
        displayName = "AGM-114R";
        displayNameShort = "AGM-114R";
        description = "AGM-114R";
        descriptionShort = "AGM-114R";
        
        ace_frag_enabled = 1;
        ace_frag_classes[] = {"ace_frag_medium","ace_frag_medium_HD"};
        ace_frag_metal = 12000;
        ace_frag_charge = 4000;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
        indirectHit = 100;
        indirectHitRange = 5;
        explosive = 1;
        
        class ace_missileguidance: ace_missileguidance {
            enabled = 1; // Missile Guidance must be explicitly enabled
        };
    };

};
