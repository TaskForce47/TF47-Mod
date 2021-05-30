#include "script_component.hpp"
class CfgPatches 
{
    class ADDON 
    {
        name = COMPONENT;
        units[] = {"TF47_CH53GS_GER","TF47_CH53GS_VIV_GER","TF47_CH53E_US","TF47_CH53E_VIV_US"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CUP_AirVehicles_CH53E"};
        author = "TF47 Rampage";
        VERSION_CONFIG;
    };
};

class CfgVehicles
{
    class CUP_CH53E_Base;
    class TF47_CH53E_BASE: CUP_CH53E_Base
    {
        armor = 100;            // just some protection against missiles, collisions and explosions
        altFullForce = 5000;    // in what height do the engines still have full thrust
        altNoForce = 6000;      // thrust of the engines interpolates to zero between altFullForce and altNoForce
        maximumLoad = 10000;    // capacity of cargo inventory for backpacks and various other items
        cargoCanEject = 1;      // cargo should be able to grab a chute and drop out of the vehicle
        driverCanEject = 0;     // pilot shouldn't be able to do so as he doesn't have eject seat
        supplyRadius = 3;
        mainBladeRadius = 10;   // describes the radius of main rotor - used for collision detection
        tailBladeRadius = 1;
        maxSpeed = 300;         // what is the maximum speed of the vehicle
        //fuelCapacity = 2500;
        fuelConsumptionRate = 0.138;
        extCameraPosition[] = {0,5,-30};
        gearRetracting = 1;
        gearUpTime = 3;
        gearDownTime = 3;
        armor = 100;
        damageResistance = 0.00555;
        threat[] = {0.3,0.2,0.3};

        mainRotorSpeed = -1;

        //multiplier of lift force
        liftForceCoef = 1.5;            // 1.0 doesn't have enough strenght to lift a hunter, 1.5 has enough to lift even the hemtt
        //multiplier of body friction
        bodyFrictionCoef = 1.4;         // old: 1.00 needed for rapid decell
        //multiplier of bank force
        cyclicAsideForceCoef = 1.2;     // old: 0.3
        //multiplier of dive force
        cyclicForwardForceCoef = 1.0;   // old: 0.3
        //multiplier of back rotor force
        backRotorForceCoef = 1;         // old: 0.3
    };
    class TF47_CH53E_VIV_BASE: TF47_CH53E_BASE
    {
        model = "\cup\airvehicles\cup_airvehicles_ch53e\usec_ch53_e_viv.p3d";
        transportSoldier = 0;
        class VehicleTransport
        {
            class Carrier
            {
                cargoBayDimensions[]        = {"VTV_limit_1", "VTV_limit_2"};   // Memory points in model defining cargo space
                disableHeightLimit          = 0;                                // If set to 1 disable height limit of transported vehicles
                maxLoadMass                 = 13600;                            // Maximum cargo weight (in Kg) which the vehicle can transport
                cargoAlignment[]            = {"center", "front"};              // Array of 2 elements defining alignment of vehicles in cargo space. Possible values are left, right, center, front, back. Order is important.
                cargoSpacing[]              = {0, 0, 0};                        // Offset from X,Y,Z axes (in metres)
                exits[]                     = {"VTV_exit_1"};                   // Memory points in model defining loading ramps, could have multiple
                unloadingInterval           = 3;                                // Time between unloading vehicles (in seconds)
                loadingDistance             = 10;                               // Maximal distance for loading in exit point (in meters).
                loadingAngle                = 60;                               // Maximal sector where cargo vehicle must be to for loading (in degrees).
                parachuteClassDefault       = B_Parachute_02_F;                 // Type of parachute used when dropped in air. Can be overridden by parachuteClass in Cargo.
                parachuteHeightLimitDefault = 50;                               // Minimal height above terrain when parachute is used. Can be overriden by parachuteHeightLimit in Cargo.
            };
        };
    };
    class TF47_CH53GS_GER: TF47_CH53E_BASE
    {
        author = "[TF47]Rampage";

        scope = 2;
        scopeCurator = 2;

        displayName = "CH-53 GS";
        faction="CUP_B_GER";
        side = 1;
        crew = "CUP_B_GER_HPilot";
        typicalCargo[] = {"CUP_B_GER_HPilot","CUP_B_GER_HPilot", "CUP_B_GER_HPilot"};
        hiddenSelectionsTextures[] =
        {
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_1_co_GER.paa",
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_2_co_GER.paa"
        };
        editorPreview = "CUP\AirVehicles\CUP_AirVehicles_CH53E\Data\preview\CUP_B_CH53E_GER.jpg";
    };
    class TF47_CH53GS_VIV_GER: TF47_CH53E_VIV_BASE
    {
        author = "[TF47]Rampage";

        scope = 2;
        scopeCurator = 2;

        displayName = "CH-53 GS";
        faction="CUP_B_GER";
        side = 1;
        crew = "CUP_B_GER_HPilot";
        typicalCargo[] = {"CUP_B_GER_HPilot","CUP_B_GER_HPilot", "CUP_B_GER_HPilot"};
        hiddenSelectionsTextures[] =
        {
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_1_co_GER.paa",
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_2_co_GER.paa"
        };
        editorPreview = "CUP\AirVehicles\CUP_AirVehicles_CH53E\Data\preview\CUP_B_CH53E_GER.jpg";
    };
        class TF47_CH53E_US: TF47_CH53E_BASE
    {
        author = "[TF47]Rampage";

        scope = 2;
        scopeCurator = 2;
        
        displayName = "CH-53 E";
        faction = "CUP_B_USMC";
        side = 1;
        crew = "CUP_B_USMC_Pilot";
        typicalCargo[] = {"CUP_B_USMC_Pilot"};
        hiddenSelectionsTextures[] =
        {
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_1_co.paa",
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_2_co.paa"
        };
        editorPreview = "CUP\AirVehicles\CUP_AirVehicles_CH53E\Data\preview\CUP_B_CH53E_USMC.jpg";
    };
    class TF47_CH53E_VIV_US: TF47_CH53E_VIV_BASE
    {
        author = "[TF47]Rampage";

        scope = 2;
        scopeCurator = 2;
        
        displayName = "CH-53 E";
        faction = "CUP_B_USMC";
        side = 1;
        crew = "CUP_B_USMC_Pilot";
        typicalCargo[] = {"CUP_B_USMC_Pilot"};
        hiddenSelectionsTextures[] =
        {
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_1_co.paa",
            "CUP\AirVehicles\CUP_AirVehicles_CH53E\data\ch53_2_co.paa"
        };
        editorPreview = "CUP\AirVehicles\CUP_AirVehicles_CH53E\Data\preview\CUP_B_CH53E_USMC.jpg";
    };
};