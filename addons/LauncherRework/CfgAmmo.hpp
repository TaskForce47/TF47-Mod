class CfgAmmo {
    
    // Base Classes
    class rhs_ammo_maaws_HEAT;
    class rhs_ammo_maaws_HEAT_penetrator;
    class tf47_ammo_base_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",50};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;

        hit = 400; //Penetrator
        caliber = 36.333; // 500mm - caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        maxSpeed = 1050;

        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_base_maaws: rhs_ammo_maaws_HEAT
    {
        submunitionAmmo = "tf47_ammo_base_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 1050;

        hit = 100;
        indirectHit = 15;
        indirectHitRange = 3;
        caliber = 1;
        
        maxSpeed = 290;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "TandemHEAT"; // TandemHEAT, HEAT, HE, AP
        simulationStep = 0.02;
    };
    
    class tf47_ammo_base_raws: rhs_ammo_maaws_HEAT
    {
        submunitionAmmo = "tf47_ammo_base_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 1050;

        hit = 100; //Tandem
        indirectHit = 15;
        indirectHitRange = 3;
        caliber = 1;

        maxSpeed = 350;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "TandemHEAT"; // TandemHEAT, HEAT, HE, AP
        simulationStep = 0.02;
    };
    
    ///// ---------- 751 ---------- /////
    
    // FFV 751 MAAWS
    class tf47_ammo_maaws_ffv751_heat: tf47_ammo_base_maaws
    {
        submunitionAmmo = "tf47_ammo_maaws_ffv751_heat_penetrator";
        warheadName = "TandemHEAT";
    };
    
    class tf47_ammo_maaws_ffv751_heat_penetrator: tf47_ammo_base_penetrator
    {
        hit = 400; //Penetrator
        caliber = 40; // 600 mm
        warheadName = "TandemHEAT";
    };
    
    // FFV 751 RAWS
    class tf47_ammo_raws_ffv751_heat: rhs_ammo_maaws_HEAT
    {

        submunitionAmmo = "tf47_ammo_raws_ffv751_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;

        hit = 200; //Tandem
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 0.8;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 350;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_raws_ffv751_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;

        hit = 400; //Penetrator
        caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;


        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };
    
    ///// ---------- 756 ---------- /////
    
    // FFV 756 MAAWS
    class rhs_ammo_maaws_HEDP;
    class rhs_ammo_maaws_HEDP_penetrator;
    class tf47_ammo_maaws_ffv756_mt: rhs_ammo_maaws_HEDP
    {
        submunitionAmmo[] = {"tf47_ammo_maaws_ffv756_mt_penetrator",1,"tf47_ammo_maaws_ffv756_mt_heat_penetrator",1};
        submunitionConeType[] = {"poissondisccenter", 2};
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 100;
        triggerOnImpact = 1;
        
        explosive = 0.65;

        hit = 200; //Tandem
        indirectHit = 15;
        indirectHitRange = 2;
        caliber = 1;
        cost = 800;
        maxSpeed = 290;

        allowAgainstInfantry = 1;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_maaws_ffv756_mt_penetrator: rhs_ammo_maaws_HEDP_penetrator
    {
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1500;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 750;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_small"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;

        hit = 100; //Penetrator
        indirectHit = 30;
        indirectHitRange = 6;
        caliber = 10; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;
        explosionTime = 0.001;
        triggerTime = 0.001;
        
        warheadName = "HE";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_maaws_ffv756_mt_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {
        
        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
        explosive = 0;

        hit = 400; //Penetrator
        caliber = 45.977; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;


        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    // FFV 756 RAWS
    class tf47_ammo_raws_ffv756_mt: rhs_ammo_maaws_HEDP
    {
        submunitionAmmo[] = {"tf47_ammo_raws_ffv756_mt_penetrator",1,"tf47_ammo_raws_ffv756_mt_heat_penetrator",1};
        submunitionConeType[] = {"poissondisccenter", 2};
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 100;
        triggerOnImpact = 1;
        
        explosive = 0.65;

        hit = 200; //Tandem
        indirectHit = 15;
        indirectHitRange = 2;
        caliber = 1;
        cost = 800;
        maxSpeed = 350;

        allowAgainstInfantry = 1;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_raws_ffv756_mt_penetrator: rhs_ammo_maaws_HEDP_penetrator
    {
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1500;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 750;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_small"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;

        hit = 100; //Penetrator
        indirectHit = 30;
        indirectHitRange = 4;
        caliber = 10; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;
        explosionTime = 0.001;
        triggerTime = 0.001;


        warheadName = "HE";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_raws_ffv756_mt_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {
        
        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
        explosive = 0;

        hit = 400; //Penetrator
        caliber = 45.977; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        maxSpeed = 290;


        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    ///// ---------- 655 ---------- /////
    
    // FFV 655 MAAWS
    class tf47_ammo_maaws_ffv655_heat_cs: rhs_ammo_maaws_HEAT
    {

        submunitionAmmo = "tf47_ammo_maaws_ffv655_heat_cs_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;

        hit = 150; //Tandem
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 45.977;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 145; //Zeroing wont work, but that thing has 300 m range IRL so CQC only
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_maaws_ffv655_heat_cs_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;

        hit = 400; //Penetrator
        caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;


        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };
    
    
    // FFV 655 RAWS
    class tf47_ammo_raws_ffv655_heat_cs: rhs_ammo_maaws_HEAT
    {

        submunitionAmmo = "tf47_ammo_raws_ffv655_heat_cs_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;

        hit = 150; //Tandem
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 45.977;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 175;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_raws_ffv655_heat_cs_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;

        hit = 400; //Penetrator
        caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 350;

        warheadName = "TandemHEAT";
        simulationStep = 0.02;
    };

    ///// ---------- 551 ---------- /////
    
    // FFV 551 MAAWS
    class tf47_ammo_maaws_ffv551_heat: rhs_ammo_maaws_HEAT
    {

        submunitionAmmo = "tf47_ammo_maaws_ffv551_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        explosive = 0.65;

        hit = 150;
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 0.8;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 290;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_maaws_ffv551_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
        explosive = 0;

        hit = 450; //Penetrator
        caliber = 80.459; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;


        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    // FFV 551 RAWS
    class tf47_ammo_raws_ffv551_heat: rhs_ammo_maaws_HEAT
    {

        submunitionAmmo = "tf47_ammo_raws_ffv551_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
      
        explosive = 0.65;

        hit = 150; 
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 0.8;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 350;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_raws_ffv551_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
        explosive = 0;

        hit = 450; //Penetrator
        caliber = 80.459; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 350;


        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    ///// ---------- 551c ---------- /////
    
    // FFV 551c MAAWS
    class tf47_ammo_maaws_ffv551c_heat: rhs_ammo_maaws_HEAT
    {

        submunitionAmmo = "tf47_ammo_maaws_ffv551c_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        explosive = 0.65;

        hit = 200;
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 30;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 290;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_maaws_ffv551c_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
        explosive = 0;

        hit = 450; //Penetrator
        caliber = 91.954; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;


        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    // FFV 551c RAWS
    class tf47_ammo_raws_ffv551c_heat: rhs_ammo_maaws_HEAT
    {
        submunitionAmmo = "tf47_ammo_raws_ffv551c_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;

        hit = 200; 
        indirectHit = 15;
        indirectHitRange = 3.1;
        caliber = 30;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 350;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;
        
        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    class tf47_ammo_raws_ffv551c_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {
        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;

        hit = 450; //Penetrator
        caliber = 91.954; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 350;

        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    ///// ---------- 441d ---------- /////
    
    // FFV 441d MAAWS
    class rhs_ammo_maaws_HE;
    class tf47_ammo_maaws_ffv441d_he: rhs_ammo_maaws_HE
    {

        hit = 100;
        indirectHit = 50;
        indirectHitRange = 8;
        caliber = 1;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 290;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HE";
        simulationStep = 0.02;
        
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 3000;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 800;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_small_HD"};  // Type of fragments - information below
        //ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 1;
        
    };
    
    
    // FFV 441d RAWS
    class tf47_ammo_raws_ffv441d_he: rhs_ammo_maaws_HE
    {


        hit = 100; 
        indirectHit = 50;
        indirectHitRange = 8;
        caliber = 1;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 350;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HE";
        simulationStep = 0.02;
        
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 3000;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 800;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_small_HD"};  // Type of fragments - information below
        //ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;
    };
    
    ///// ---------- 502 ---------- /////
    
    // FFV 502 MAAWS
    class tf47_ammo_maaws_ffv502_hedp: rhs_ammo_maaws_HEDP
    {

        submunitionAmmo = "tf47_ammo_maaws_ffv502_hedp_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;

        hit = 125;
        indirectHit = 50;
        indirectHitRange = 6;
        caliber = 0.8;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 290;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HE";
        simulationStep = 0.02;
        
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1500;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ace_frag_small_HD","ACE_frag_small"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;
        
    };
    
    class tf47_ammo_maaws_ffv502_hedp_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {
        explosive = 0;

        hit = 380; //Penetrator
        caliber = 45.977; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;


        warheadName = "HEAT";
        simulationStep = 0.02;
    };
    
    // FFV 502 RAWS
    class tf47_ammo_raws_ffv502_hedp: rhs_ammo_maaws_HEDP
    {

        submunitionAmmo = "tf47_ammo_raws_ffv502_hedp_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;

        hit = 125; 
        indirectHit = 50;
        indirectHitRange = 6;
        caliber = 0.8;
        cost = 800;
        airFriction = 0.010;
        sideAirFriction = 0.00;
        maxSpeed = 350;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HE";
        simulationStep = 0.02;
        
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1500;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_medium_HD","ACE_frag_small_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;
        
    };
    
    class tf47_ammo_raws_ffv502_hedp_penetrator: rhs_ammo_maaws_HEAT_penetrator
    {
        explosive = 0;

        hit = 380; //Penetrator
        caliber = 45.977; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;

        warheadName = "HEAT";
        simulationStep = 0.02;
        
    };
    
    ///// ---------- 401 ---------- /////
    
    // FFV 401 MAAWS
    class B_12Gauge_Pellets_Submunition;
    class tf47_ammo_maaws_ffv401_adm: B_12Gauge_Pellets_Submunition
    {
        hit = 6;
        caliber = 1;
        timeToLive = 3;

        visibleFire = 100;
        visibleFireTime = 9;
        audibleFire = 850;
        audibleFireTime = 12;
        
        submunitionAmmo = "tf47_ammo_maaws_ffv401_adm_penetrator";
        submunitionConeAngle = 6;
        submunitionConeType[] = {"random",300};
        submunitionDirectionType = "SubmunitionModelDirection";
        explosive = 1;
        explosionTime = 0.2;
        
        simulation = "shotRocket";
        simulationStep = 0.05;
        sideAirFriction = 0.05;
        initSpeed = 270;
        airFriction = 0.1;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
    };
    
    class B_12Gauge_Pellets_Submunition_Deploy;
    class tf47_ammo_maaws_ffv401_adm_penetrator: B_12Gauge_Pellets_Submunition_Deploy
    {
        triggerTime = 0;

        visibleFire = 100;
        visibleFireTime = 9;
        audibleFire = 850;
        audibleFireTime = 12;
        
        hit = 10;
        coefGravity = 0.3;
        indirectHit = 13;
        indirectHitRange = 2.66;
        caliber = 5;
        airFriction = -0.0008;
        simulationStep = 0.5;
        timeToLive = 1.4;
        deleteParentWhenTriggered = 1;
        triggerOnImpact = 1;
        deflecting = 20;
        
    };
    
    // FFV 401 RAWS
    class tf47_ammo_raws_ffv401_adm: B_12Gauge_Pellets_Submunition
    {
        hit = 6;
        caliber = 1;
        timeToLive = 3;

        visibleFire = 100;
        visibleFireTime = 9;
        audibleFire = 850;
        audibleFireTime = 12;
        
        submunitionAmmo = "tf47_ammo_maaws_ffv401_adm_penetrator";
        submunitionConeAngle = 6;
        submunitionConeType[] = {"random",300};
        submunitionDirectionType = "SubmunitionModelDirection";
        explosive = 1;
        explosionTime = 0.2;
        
        simulation = "shotRocket";
        simulationStep = 0.05;
        sideAirFriction = 0.05;
        initSpeed = 270;
        airFriction = 0.1;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
    };

    class tf47_ammo_raws_ffv401_adm_penetrator: B_12Gauge_Pellets_Submunition_Deploy
    {
        triggerTime = 0;

        visibleFire = 100;
        visibleFireTime = 9;
        audibleFire = 850;
        audibleFireTime = 12;
        
        hit = 10;
        coefGravity = 0.3;
        indirectHit = 13;
        indirectHitRange = 2.66;
        caliber = 5;
        airFriction = -0.0008;
        simulationStep = 0.5;
        timeToLive = 1.4;
        deleteParentWhenTriggered = 1;
        triggerOnImpact = 1;
        deflecting = 20;
    };
    
     ///// ---------- 509 ---------- /////
    
    // FFV 509 MAAWS
    class tf47_ammo_maaws_ffv509_asm: rhs_ammo_maaws_HEDP
    {
        submunitionAmmo = "tf47_ammo_maaws_ffv509_asm_penetrator";
        submunitionConeType = "poissondisccenter";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,0.8};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 100;
        triggerOnImpact = 1;
        
        explosive = 0.65;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;

        hit = 100; //Tandem
        indirectHit = 15;
        indirectHitRange = 2;
        caliber = 1;
        cost = 800;
        maxSpeed = 290;

        allowAgainstInfantry = 1;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "HEAT";
    };
    
    class tf47_ammo_maaws_ffv509_asm_penetrator: rhs_ammo_maaws_HEDP_penetrator
    {
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 2000;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 1000;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ace_frag_small_HD","ACE_frag_medium_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;

        hit = 50; //Penetrator
        indirectHit = 30;
        indirectHitRange = 8;
        caliber = 10; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;
        explosionTime = 0.001;
        triggerTime = 0.001;
        
        warheadName = "HE";
    };
    
    // FFV 509 RAWS
    class tf47_ammo_raws_ffv509_asm: rhs_ammo_maaws_HEDP
    {
        submunitionAmmo = "tf47_ammo_raws_ffv509_asm_penetrator";
        submunitionConeType = "poissondisccenter";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,0.8};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 100;
        triggerOnImpact = 1;
        
        explosive = 0.65;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;

        hit = 100; //Tandem
        indirectHit = 15;
        indirectHitRange = 2;
        caliber = 1;
        cost = 800;
        maxSpeed = 350;

        allowAgainstInfantry = 1;

        visibleFire = 15;
        audibleFire = 20;
        warheadName = "HEAT";
    };
    
    class tf47_ammo_raws_ffv509_asm_penetrator: rhs_ammo_maaws_HEDP_penetrator
    {
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 2000;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 1000;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ace_frag_small_HD","ACE_frag_small"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;

        hit = 50; //Penetrator
        indirectHit = 30;
        indirectHitRange = 8;
        caliber = 10; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
        cost = 800;
        maxSpeed = 290;
        explosionTime = 0.001;
        triggerTime = 0.001;
        
        warheadName = "HE";
    };
    
    ///// ---------- 545 ---------- /////
    
    // FFV 545 MAAWS
    class tf47_ammo_maaws_ffv545c_illum: B_12Gauge_Pellets_Submunition
    {
        hit = 6;
        caliber = 1;
        timeToLive = 3;

        visibleFire = 100;
        visibleFireTime = 9;
        audibleFire = 850;
        audibleFireTime = 12;
        
        submunitionAmmo = "tf47_ammo_maaws_ffv545c_illum_deploy";
        submunitionConeAngle = 1;
        submunitionConeType[] = {"random",1};
        submunitionDirectionType = "SubmunitionModelDirection";
        
        simulation = "shotRocket";
        simulationStep = 0.05;
        sideAirFriction = 0.05;
        initSpeed = 240;
        maxSpeed = 290;
        airFriction = 0.1;
        allowAgainstInfantry = 1;
        
        ace_overpressure_range = 1;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0;
        ace_overpressure_angle = 30;
    };
    
    class FlareBase;
    class tf47_ammo_maaws_ffv545c_illum_deploy: FlareBase
    {
        intensity = 2000350;
        coefGravity = 0.01;
        lightColor[] = {0.91, 0.91, 1, 0};
        triggerTime = 1;
        timeToLive = 45;
        flareSize = 15;
        smokeColor[] = {0.91, 0.91, 1, 0};
        dayLight = 1;
        MaxDistance = 550;
        
        class Attenuation {
                start = 475;
                constant = 100;
                linear = 60;
                quadratic = 20;
                hardLimitStart = 480;
                hardLimitEnd = 550;
        };
    };
    
    // FFV 545 RAWS
    class tf47_ammo_raws_ffv545c_illum: B_12Gauge_Pellets_Submunition
    {
        hit = 6;
        caliber = 1;
        timeToLive = 3;

        visibleFire = 100;
        visibleFireTime = 9;
        audibleFire = 850;
        audibleFireTime = 12;
        
        submunitionAmmo = "tf47_ammo_raws_ffv545c_illum_deploy";
        submunitionConeAngle = 1;
        submunitionConeType[] = {"random",1};
        submunitionDirectionType = "SubmunitionModelDirection";
        
        simulation = "shotRocket";
        simulationStep = 0.05;
        sideAirFriction = 0.05;
        initSpeed = 240;
        maxSpeed = 350;
        airFriction = 0.1;
        allowAgainstInfantry = 1;
        
        ace_overpressure_range = 1;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0;
        ace_overpressure_angle = 30;
    };
    
    class tf47_ammo_raws_ffv545c_illum_deploy: FlareBase
    {
        intensity = 2000350;
        coefGravity = 0.01;
        lightColor[] = {0.91, 0.91, 1, 0};
        triggerTime = 1;
        timeToLive = 45;
        flareSize = 15;
        smokeColor[] = {0.91, 0.91, 1, 0};
        dayLight = 1;
        MaxDistance = 550;
        
        class Attenuation {
                start = 475;
                constant = 100;
                linear = 60;
                quadratic = 20;
                hardLimitStart = 480;
                hardLimitEnd = 550;
        };
    };
    
     ///// ---------- 469 ---------- /////
    
    // FFV 469 MAAWS
    class tf47_ammo_maaws_ffv469c_smoke: tf47_ammo_maaws_ffv502_hedp
    {
        hit = 6;
        caliber = 1;
        
        airFriction = 0.010;
        sideAirFriction = 0.05;
        maxSpeed = 290;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "HE";
        simulationStep = 0.02;
        
        ace_frag_enabled = 0;
        
        //CraterEffects = "80mm_Smoke";
        //effectsSmoke = "SmokeShellWhite";
        //ExplosionEffects = "UK3CB_WPExplosion";
        //simulation = "shotSmokeX";
        
        submunitionAmmo = "tf47_ammo_maaws_ffv469c_smoke_submun";
        submunitionConeAngle = 1;
        submunitionConeType[] = {"random",1};
        submunitionDirectionType = "SubmunitionModelDirection";
        triggerOnImpact = 1;
    };
    
    class UK3CB_BAF_Smoke_81mm_AMOS;
    class tf47_ammo_maaws_ffv469c_smoke_submun: UK3CB_BAF_Smoke_81mm_AMOS
    {
        fuseDistance = 0;
        smokeColor[] = {1,1,1,1};
        triggerOnImpact = 1;
    };
    
    // FFV 469 RAWS
    class tf47_ammo_raws_ffv469c_smoke: tf47_ammo_raws_ffv502_hedp
    {
        hit = 6;
        caliber = 1;
        
        airFriction = 0.010;
        sideAirFriction = 0.05;
        maxSpeed = 350;
        initTime = 0;
        thrustTime = 0.1;
        thrust = 0.1;

        timeToLive = 25;
        maneuvrability = 0;
        allowAgainstInfantry = 0;

        warheadName = "Default";
        simulationStep = 0.02;
        
        ace_frag_enabled = 0;
        
        //CraterEffects = "80mm_Smoke";
        //effectsSmoke = "SmokeShellWhite";
        //ExplosionEffects = "UK3CB_WPExplosion";
        //simulation = "shotSmokeX";
        
        submunitionAmmo = "tf47_ammo_maaws_ffv469c_smoke_submun";
        submunitionConeAngle = 1;
        submunitionConeType[] = {"random",1};
        submunitionDirectionType = "SubmunitionModelDirection";
        triggerOnImpact = 1;
    };
    
    class tf47_ammo_raws_ffv469c_smoke_submun: UK3CB_BAF_Smoke_81mm_AMOS
    {
        fuseDistance = 0;
        smokeColor[] = {1,1,1,1};
        triggerOnImpact = 1;
    };

     ///// ---------- GMM ---------- /////
    
    // GMM RAWS
    class M_Titan_AT ;
    class tf47_ammo_raws_gmm_hedp: M_Titan_AT 
    {  
        submunitionAmmo = "tf47_ammo_raws_ffv502_hedp_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        model = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Launchers\UK3CB_Javelin_Rocket.p3d";
        proxyShape = "";

        hit = 100; 
        indirectHit = 50;
        indirectHitRange = 6;
        caliber = 0.8;
        cost = 800;

        maxSpeed = 200;
        initTime = 0.2;
        thrustTime = 6;
        thrust = 150;

        airLock = 0;
        irLock = 0;
        laserLock = 0;
        manualControl = 0;


        trackOversteer = 1;
        sideAirFriction = 0.14;
        airFriction = 0.1;
        
        flightProfiles[] = {};

        warheadName = "HE";
        simulationStep = 0.02;
        
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1500;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_medium_HD","ACE_frag_small_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
        explosive = 0.65;
        
        class ace_missileguidance {
            enabled = 1;

            minDeflection = 0.0005;     // Minium flap deflection for guidance
            maxDeflection = 0.01;       // Maximum flap deflection for guidance
            incDeflection = 0.0005;     // The incrmeent in which deflection adjusts.

            canVanillaLock = 0;         // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH"};

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = {"LOAL","LOBL"};

            seekLastTargetPos = 1;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 120;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 1;
            seekerMaxRange = 2000;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "LIN";
            attackProfiles[] = {"LIN"};
        };
        
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
                            minRange = 3000;
                            maxRange = 3000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget
                        {
                            minRange = 3000;
                            maxRange = 3000;
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
    
    class tf47_ammo_raws_gmm_at: M_Titan_AT 
    {
        submunitionAmmo = "tf47_ammo_raws_ffv751_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
      
        model = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Launchers\UK3CB_Javelin_Rocket.p3d";
        proxyShape = "";

        hit = 100; 
        indirectHit = 30;
        indirectHitRange = 6;
        caliber = 0.8;
        cost = 800;

        maxSpeed = 200;
        initTime = 0.2;
        thrustTime = 6;
        thrust = 150;
        
        explosive = 0.65;

        airLock = 0;
        irLock = 0;
        laserLock = 0;
        manualControl = 0;


        trackOversteer = 1;
        sideAirFriction = 0.14;
        airFriction = 0.1;
        
        flightProfiles[] = {};

        ace_frag_skip = 0;

        warheadName = "TandemHEAT";
        simulationStep = 0.02;
        
        class ace_missileguidance {
            enabled = 1;

            minDeflection = 0.0005;     // Minium flap deflection for guidance
            maxDeflection = 0.01;       // Maximum flap deflection for guidance
            incDeflection = 0.0005;     // The incrmeent in which deflection adjusts.

            canVanillaLock = 0;         // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "SALH";
            seekerTypes[] = { "SALH"};

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = {"LOAL","LOBL"};

            seekLastTargetPos = 1;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 120;           // Angle in front of the missile which can be searched
            seekerAccuracy = 1;         // seeker accuracy multiplier

            seekerMinRange = 1;
            seekerMaxRange = 3500;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "LIN";
            attackProfiles[] = {"LIN"};
        };
        
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
                            minRange = 3000;
                            maxRange = 3000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget
                        {
                            minRange = 3000;
                            maxRange = 3000;
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

    
};