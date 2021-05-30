class CfgWeapons {
    class cannon_155mm;
    class rhs_weap_m284: cannon_155mm {class Single1;};
    class itc_land_rhs_weap_m284: rhs_weap_m284 {
        scope = 1;
        displayName = "Howitzer 155 mm";
        autoReload = 0;
        modes[] = {"Single"};
        reloadTime = 1;
        magazineReloadTime = 6;
        #include "CfgWeapons_howitzers_magazinesm109.hpp"
        class Single: Single1 {
            displayName = "";
            artilleryCharge = 1;
            reloadTime = 6;
        };
        class EventHandlers
        {
            class itc_land_veh_weapons
            {
                fired = "_this call itc_land_veh_weapons_fnc_fired;";
            };
        };
    };

};