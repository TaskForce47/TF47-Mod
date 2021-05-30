/// Magazines macros definition ///

#define mag_2(a) a, a
#define mag_3(a) a, a, a
#define mag_4(a) a, a, a, a
#define mag_5(a) a, a, a, a, a
#define mag_6(a) a, a, a, a, a, a
#define mag_7(a) a, a, a, a, a, a, a
#define mag_8(a) a, a, a, a, a, a, a, a
#define mag_9(a) a, a, a, a, a, a, a, a, a
#define mag_10(a) a, a, a, a, a, a, a, a, a, a
#define mag_11(a) a, a, a, a, a, a, a, a, a, a, a
#define mag_12(a) a, a, a, a, a, a, a, a, a, a, a, a
#define mag_13(a) a, a, a, a, a, a, a, a, a, a, a, a, a
#define mag_14(a) a, a, a, a, a, a, a, a, a, a, a, a, a, a
#define mag_15(a) a, a, a, a, a, a, a, a, a, a, a, a, a, a, a
#define mag_24(a) a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a
// Tank > Tank_F > MBT_01_base_F > MBT_01_arty_base_F > rhsusf_m109tank_base

class CfgVehicles {
    class LandVehicle;
    class Tank: LandVehicle {
        class ACE_SelfActions;
    };
    class Tank_F: Tank {
        class ACE_SelfActions: ACE_SelfActions {};
        class Turrets {
            class MainTurret;
        };
        class AnimationSources;
    };
    class MBT_01_base_F: Tank_F {
        class ACE_SelfActions: ACE_SelfActions {};
        class Turrets: Turrets {
            class MainTurret: MainTurret {};
        };
        class AnimationSources: AnimationSources {};
    };
    class MBT_01_arty_base_F: MBT_01_base_F {
        class ACE_SelfActions: ACE_SelfActions {};
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
            class MainTurret: MainTurret { };
        };
    };
    class B_MBT_01_arty_base_F: MBT_01_arty_base_F {
        class ACE_SelfActions: ACE_SelfActions {};
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
                class MainTurret: MainTurret { };
        };
    };

    class rhsusf_m109tank_base : B_MBT_01_arty_base_F {
        class ACE_SelfActions: ACE_SelfActions {};
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
                class MainTurret: MainTurret { };
        };
    };
    class rhsusf_m109_usarmy: rhsusf_m109tank_base {
        class ACE_SelfActions: ACE_SelfActions {};
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
                class MainTurret: MainTurret { };
        };
    };
    class itc_land_rhsusf_m109_usarmy: rhsusf_m109_usarmy {
        displayname = "M109A6 mod. 0 Paladin 2 (WD)";
        scopeCurator = 2;
        class ACE_SelfActions: ACE_SelfActions {
            class ITC_Land_SPHammohandler {
                displayName = "Open Ammo Handling Interface";
                condition = "( gunner _target ) == ACE_Player";
                statement = "createDialog 'ITC_Land_SPHammohandler'";
            };
            class ITC_Land_CommanderTablet {
                displayName = "Open Mounted Tablet";
                icon = "\itc_land_tablet\UI\arty-icon.paa";
                condition = "([_target] call itc_land_tablet_fnc_vehicleHasTablet) && (( commander _target ) == ACE_Player)";
                statement = "[_target] call itc_land_tablet_fnc_openVehicleTablet";
            };
        };
        artilleryScanner = 0;
        class itc_land {
            loaderType = 1; // semi automatic
            tabletInterfaces[] = {"spg"};
            mountedTablet = "itc_land_tablet_spg";
            class fcs {
                tableList = "g_155";
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                turretInfoType = "ITC_Land_RscAltGunnerSightSPH";
                weapons[] = {"itc_land_rhs_weap_m284"};
                magazines[] = {
                    mag_15("itc_land_m109hex"),
                    mag_9("itc_land_m109icm"),
                    
                    mag_5("itc_land_m109smo"),
                    mag_5("itc_land_m109ill"),
                    
                    mag_3("itc_land_m109map"),
                    mag_3("itc_land_m109mat"),
                    
                    mag_3("itc_land_m109pgm"),
                    mag_3("itc_land_m109icmpgm"),
                    
                    mag_3("itc_land_m109lgm"),
                    mag_3("itc_land_m109lgmat"),
                    
                    mag_3("itc_land_m109ext"),
                    mag_3("itc_land_m109fal")

                };
                lockWhenVehicleSpeed = 5;
                maxHorizontalRotSpeed = "((360/30)/45)";
            };
        };
        class AnimationSources: AnimationSources {};

    };
    class rhsusf_m109d_usarmy: rhsusf_m109_usarmy {
        class ACE_SelfActions: ACE_SelfActions {};
        class AnimationSources: AnimationSources {};
        class Turrets: Turrets {
                class MainTurret: MainTurret { };
        };
    };
    class itc_land_rhsusf_m109d_usarmy: rhsusf_m109d_usarmy {
        displayname = "M109A6 mod. 0 Paladin 2 (DES)";
        scopeCurator = 2;
        class ACE_SelfActions: ACE_SelfActions {
            class ITC_Land_SPHammohandler {
                displayName = "Open Ammo Handling Interface";
                condition = "( gunner _target ) == ACE_Player";
                statement = "createDialog 'ITC_Land_SPHammohandler'";
            };
            class ITC_Land_CommanderTablet {
                displayName = "Open Mounted Tablet";
                icon = "\itc_land_tablet\UI\arty-icon.paa";
                condition = "([_target] call itc_land_tablet_fnc_vehicleHasTablet) && (( commander _target ) == ACE_Player)";
                statement = "[_target] call itc_land_tablet_fnc_openVehicleTablet";
            };
        };
    artilleryScanner = 0;
        class itc_land {
            loaderType = 1; // semi automatic
            tabletInterfaces[] = {"spg"};
            mountedTablet = "itc_land_tablet_spg";
            class fcs {
                tableList = "g_155";
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                turretInfoType = "ITC_Land_RscAltGunnerSightSPH";
                weapons[] = {"itc_land_rhs_weap_m284"};
                magazines[] = {
                    mag_15("itc_land_m109hex"),
                    mag_9("itc_land_m109icm"),
                    
                    mag_5("itc_land_m109smo"),
                    mag_5("itc_land_m109ill"),
                    
                    mag_3("itc_land_m109map"),
                    mag_3("itc_land_m109mat"),
                    
                    mag_3("itc_land_m109pgm"),
                    mag_3("itc_land_m109icmpgm"),
                    
                    mag_3("itc_land_m109lgm"),
                    mag_3("itc_land_m109lgmat"),
                    
                    mag_3("itc_land_m109ext"),
                    mag_3("itc_land_m109fal")

                };
                lockWhenVehicleSpeed = 5;
                maxHorizontalRotSpeed = "((360/30)/45)";
            };
        };
        class AnimationSources: AnimationSources {};

    };
};

