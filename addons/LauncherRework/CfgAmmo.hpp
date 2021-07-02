class CfgAmmo {
    
    class rhs_ammo_maaws_HEAT;
    class tf47_ammo_maaws_ffv751_heat: rhs_ammo_maaws_HEAT
	{

        submunitionAmmo = "tf47_ammo_maaws_ffv751_heat_penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 1000;
        
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
    
    class tf47_ammo_maaws_ffv751_heat_penetrator: rhs_ammo_maaws_HEAT
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

};