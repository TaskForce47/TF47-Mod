class CfgAmmo {
    
    ///// ---------- 751 ---------- /////
    
    // FFV 751 MAAWS
    class rhs_ammo_maaws_HEAT;
    class rhs_ammo_maaws_HEAT_penetrator;
    class tf47_ammo_maaws_ffv751_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_maaws_ffv751_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
		explosive = 0.8;

		hit = 100; //Tandem
		indirectHit = 15;
		indirectHitRange = 3.1;
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

		visibleFire = 15;
		audibleFire = 20;
		warheadName	= "TandemHEAT";
	};
    
    class tf47_ammo_maaws_ffv751_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 400; //Penetrator
		caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "TandemHEAT";
	};
    
    // FFV 751 RAWS
    class tf47_ammo_raws_ffv751_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_raws_ffv751_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
		explosive = 0.8;

		hit = 100; //Tandem
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

		visibleFire = 15;
		audibleFire = 20;
		warheadName	= "TandemHEAT";
	};
    
    class tf47_ammo_raws_ffv751_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 400; //Penetrator
		caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "TandemHEAT";
	};
    
    ///// ---------- 756 ---------- /////
    
    // FFV 756 MAAWS
    class rhs_ammo_maaws_HEDP;
    class rhs_ammo_maaws_HEDP_penetrator;
    class tf47_ammo_maaws_ffv756_mt: rhs_ammo_maaws_HEDP
	{

        submunitionAmmo = "tf47_ammo_maaws_ffv756_mt_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,0.8};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 100;
        triggerOnImpact = false;
        triggerTime = 0.1;
        
		explosive = 1;

		hit = 100; //Tandem
		indirectHit = 15;
		indirectHitRange = 2;
		caliber = 34.48;
		cost = 800;
		maxSpeed = 290;

		allowAgainstInfantry = 1;

		visibleFire = 15;
		audibleFire = 20;
		warheadName	= "HEAT";
	};
    
    class tf47_ammo_maaws_ffv756_mt_penetrator: rhs_ammo_maaws_HEDP_penetrator
	{
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 210;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 470;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_small_HD","ACE_frag_tiny_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
		explosive = 1;

		hit = 50; //Penetrator
        indirectHit = 30;
		indirectHitRange = 4;
		caliber = 1; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "HE";
	};
    
    // FFV 756 RAWS
    class tf47_ammo_raws_ffv756_mt: rhs_ammo_maaws_HEDP
	{
        submunitionAmmo = "tf47_ammo_raws_ffv756_mt_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,0.8};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 100;
        triggerOnImpact = false;
        triggerTime = 0.1;
        
		explosive = 1;

		hit = 100; //Tandem
		indirectHit = 15;
		indirectHitRange = 2;
		caliber = 34.48;
		cost = 800;
		maxSpeed = 350;

		allowAgainstInfantry = 1;

		visibleFire = 15;
		audibleFire = 20;
		warheadName	= "HEAT";
	};
    
    class tf47_ammo_raws_ffv756_mt_penetrator: rhs_ammo_maaws_HEDP_penetrator
	{
        ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 210;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 470;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_small_HD","ACE_frag_tiny_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
		explosive = 1;

		hit = 50; //Penetrator
        indirectHit = 30;
		indirectHitRange = 4;
		caliber = 1; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "HE";
	};
    
    ///// ---------- 655 ---------- /////
    
    // FFV 655 MAAWS
    class tf47_ammo_maaws_ffv655_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_maaws_ffv655_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
        
		explosive = 0.8;

		hit = 100; //Tandem
		indirectHit = 15;
		indirectHitRange = 3.1;
		caliber = 0.8;
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
		warheadName	= "TandemHEAT";
	};
    
    class tf47_ammo_maaws_ffv655_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 350; //Penetrator
		caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "TandemHEAT";
	};
    
    // FFV 655 RAWS
    class tf47_ammo_raws_ffv655_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_raws_ffv655_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
        
		explosive = 0.8;

		hit = 100; //Tandem
		indirectHit = 15;
		indirectHitRange = 3.1;
		caliber = 0.8;
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
		warheadName	= "TandemHEAT";
	};
    
    class tf47_ammo_raws_ffv655_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 400; //Penetrator
		caliber = 137.931; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 350;


		warheadName	= "TandemHEAT";
	};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///// ---------- 551 ---------- /////
    
    // FFV 551 MAAWS
    class tf47_ammo_maaws_ffv551_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_maaws_ffv551_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
        
		explosive = 0.8;

		hit = 100;
		indirectHit = 15;
		indirectHitRange = 3.1;
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

		warheadName	= "HEAT";
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

		hit = 350; //Penetrator
		caliber = 80.459; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "HEAT";
	};
    
    // FFV 551 RAWS
    class tf47_ammo_raws_ffv551_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_raws_ffv551_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
      
		explosive = 0.8;

		hit = 100; 
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

		warheadName	= "HEAT";
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

		hit = 400; //Penetrator
		caliber = 80.459; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 350;


		warheadName	= "HEAT";
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
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
        
		explosive = 0.8;

		hit = 100;
		indirectHit = 15;
		indirectHitRange = 3.1;
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

		warheadName	= "HEAT";
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

		hit = 350; //Penetrator
		caliber = 91.954; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "HEAT";
	};
    
    // FFV 551c RAWS
    class tf47_ammo_raws_ffv551c_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_raws_ffv551c_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
      
		explosive = 0.8;

		hit = 100; 
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
		
		warheadName	= "HEAT";
	};
    
    class tf47_ammo_raws_ffv551c_heat_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionAmmo = "rhs_ammo_spall";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 400; //Penetrator
		caliber = 91.954; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 350;


		warheadName	= "HEAT";
	};
	
	///// ---------- 441d ---------- /////
    
    // FFV 441d MAAWS
	class rhs_ammo_maaws_HE;
    class tf47_ammo_maaws_ffv441d_he: rhs_ammo_maaws_HE
	{
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
        
		explosive = 0.8;

		hit = 100;
		indirectHit = 15;
		indirectHitRange = 3.1;
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

		warheadName	= "HE";
		
		ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1000;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_medium"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
		explosive = 1;
		
	};
    
    
    // FFV 441d RAWS
    class tf47_ammo_raws_ffv441d_he: rhs_ammo_maaws_HE
	{

		explosive = 0.8;

		hit = 100; 
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

		warheadName	= "HE";
		
		ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 1000;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_medium"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
		explosive = 1;
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
        
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;
        
		explosive = 0.8;

		hit = 100;
		indirectHit = 15;
		indirectHitRange = 3.1;
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

		warheadName	= "HEAT";
		
		ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 600;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_medium_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
		explosive = 1;
		
	};
    
    class tf47_ammo_maaws_ffv502_hedp_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 350; //Penetrator
		caliber = 45,977; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 290;


		warheadName	= "HEAT";
	};
    
    // FFV 502 RAWS
    class tf47_ammo_raws_ffv502_hedp: rhs_ammo_maaws_HEDP
	{

        submunitionAmmo = "tf47_ammo_raws_ffv502_hedp_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 290;
      
		explosive = 0.8;

		hit = 100; 
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

		warheadName	= "HEAT";
		
		ace_frag_enabled = 1;
        ACE_damageType = "explosive";
        
        ace_frag_metal = 600;  // Amount of metal being fragmented (grams) - information below
        ace_frag_charge = 590;  // Amount of explosive filler (grams) - information below
        ace_frag_gurney_c = 2800;  // Gurney velocity constant for explosive type - information below
        ace_frag_gurney_k = 3/5;  // Gurney shape factor - information below
        ace_frag_classes[] = {"ACE_frag_medium_HD"};  // Type of fragments - information below
        ace_frag_skip = 0;  // (Optional) Skip fragmentation for this ammo type (0-disabled, 1-enabled) - information below
        ace_frag_force = 1;  // (Optional) Force fragmentation system (0-disabled, 1-enabled) - information below
        
		explosive = 1;
		
	};
    
    class tf47_ammo_raws_ffv502_hedp_penetrator: rhs_ammo_maaws_HEAT_penetrator
	{

        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionConeType[] = {"randomcenter",30};
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        
		explosive = 0;

		hit = 400; //Penetrator
		caliber = 45,977; // caliber = (mm penetration @speedX)*1000 / (bulletPenetrability * speedX)
		cost = 800;
		maxSpeed = 350;

		warheadName	= "HE";
		
	};
	
	///// ---------- 401 ---------- /////
    
    // FFV 401 MAAWS
    class tf47_ammo_maaws_ffv401_adm: rhs_ammo_maaws_HE
	{
       	submunitionAmmo[] = {"tf47_ammo_maaws_ffv401_adm_penetrator"};
		submunitionConeType[] = {"poissondisccenter", 1000};
        submunitionConeAngle = 0.50;
		simulation = shotSubmunitions;
		
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;

		hit = 1;
		indirectHit = 1;
		indirectHitRange = 0.1;
		caliber = 0.8;
		cost = 800;
		airFriction = 0.010;
		sideAirFriction = 0.00;
		maxSpeed = 290;
		initTime = 0;
		thrustTime = 0.1;
		thrust = 0.1;
		triggerTime = 0.0001;

		timeToLive = 25;
		maneuvrability = 0;
		allowAgainstInfantry = 1;

	};
	
		class B_127x99_Ball;
		class tf47_ammo_maaws_ffv401_adm_penetrator: B_127x99_Ball
    {
        hit = 10;
        indirectHit = 0;
        indirectHitRange = 0;
        caliber = 5;

		submunitionInitSpeed = 300;
        typicalSpeed = 200;
        airFriction = -0.000617;
        tracerScale = 0.2;
        tracerStartTime = 0.01;
        tracerEndTime = 3;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
		
	};
    
    // FFV 401 RAWS
    class tf47_mag_raws_ffv401_adm: rhs_ammo_maaws_HE
	{
		submunitionAmmo[] = {"tf47_ammo_raws_ffv401_adm_penetrator"};
		submunitionConeType[] = {"poissondisccenter", 1000};
        submunitionConeAngle = 0.50;
		simulation = shotSubmunitions;
		
        ace_overpressure_range = 3;
        ace_overpressure_priority = 10;
        ace_overpressure_damage = 0.3;
        ace_overpressure_angle = 30;

		hit = 1;
		indirectHit = 1;
		indirectHitRange = 0.1;
		caliber = 0.8;
		cost = 800;
		airFriction = 0.010;
		sideAirFriction = 0.00;
		maxSpeed = 350;
		initTime = 0;
		thrustTime = 0.1;
		thrust = 0.1;
		triggerTime = 0.0001;

		timeToLive = 25;
		maneuvrability = 0;
		allowAgainstInfantry = 1;

	};

		class tf47_ammo_raws_ffv401_adm_penetrator: B_127x99_Ball
    {
        hit = 10;
        indirectHit = 0;
        indirectHitRange = 0;
        caliber = 5;

		submunitionInitSpeed = 300;
        typicalSpeed = 200;
        airFriction = -0.000617;
        tracerScale = 0.2;
        tracerStartTime = 0.01;
        tracerEndTime = 3;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
		
	};
	
};