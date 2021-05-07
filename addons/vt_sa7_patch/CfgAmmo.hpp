class CfgAmmo 
{
	class vn_m_asraam_base;
	class vn_missile_sa7_ammo: vn_m_asraam_base 
	{
		scope = 2;
		author = "Savage Game Design";
		appId = 1.2277e+006;
		model = "\vn\weapons_v_f_vietnam\missile\vn_missile_sa7_ammo.p3d";
		proxyShape = "\vn\weapons_v_f_vietnam\missile\vn_missile_sa7_proxy.p3d";
		explosionEffects = "vn_fx_exp_m_sraa_frag";
		effectsMissile = "vn_fx_trail_m_sa7";
		soundfly[] = {"vn\sounds_f_vietnam\weapons\launcher\rocket_fly_1.ogg",1,1,400};
		soundsetexplosion[] = {"vn_missile_epl_soundset","vn_epl_shock_soundset","vn_rocket_explosion_tails_soundset","vn_debris_small_soundset","vn_explosion_shrapnel_soundset"};
		warheadName = "HE";
		hit = 130;
		indirectHit = 85;
		indirectHitRange = 10;
		proximityExplosionDistance = 20;
		fuseDistance = 200;
		maneuvrability = 30;
		airFriction = 0.17;
		sideAirFriction = 0.23;
		trackOversteer = 1.5;
		trackLead = 0.9;
		initTime = 0;
		timeToLive = 18;
		thrustTime = 4;
		thrust = 225;
		maxSpeed = 700;
		simulationStep = 0.002;
		airLock = 2;
		lockType = 0;
		cmimmunity = 0.92;
		weaponLockSystem = "2 + 16";
		missileLockCone = 180;
		missileKeepLockedCone = 180;
		missileLockMaxDistance = 5000;
		missileLockMinDistance = 250;
		missileLockMaxSpeed = 600;
		cost = 1000;
		whistleDist = 20;
		aiAmmoUsageFlags = 256;
		missileFireAnim = "rocket_fire_hide";
		CraterEffects = "AAMissileCrater";
		muzzleEffect = "B01_fnc_effectFiredJetMissile";
		autoSeekTarget = 1;
		class LoalDistance
		{
			lockSeekDistanceFromParent = 30;
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						maxTrackableSpeed = 600;
						minTrackableATL = 3;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						color[] = {1,0,0,1};
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						allowsMarking = 1;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = "";
						aimDown = 0;
						minTrackableSpeed = -1e+010;
						maxTrackableATL = 1e+010;
					};
				};
			};
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						maxTrackableSpeed = 600;
						minTrackableATL = 3;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						color[] = {1,0,0,1};
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						allowsMarking = 1;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = ";
						aimDown = 0;
						minTrackableSpeed = -1e+010;
						maxTrackableATL = 1e+010;
					};
				};
			};
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						maxTrackableSpeed = 600;
						minTrackableATL = 3;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						color[] = {1,0,0,1};
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						allowsMarking = 1;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = "";
						aimDown = 0;
						minTrackableSpeed = -1e+010;
						maxTrackableATL = 1e+010;
					};
				};
			};
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						maxTrackableSpeed = 600;
						minTrackableATL = 3;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						color[] = {1,0,0,1};
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						allowsMarking = 1;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = ";
						aimDown = 0;
						minTrackableSpeed = -1e+010;
						maxTrackableATL = 1e+010;
					};
				};
			};
		};
		manualControl = 0;
		maxControlRange = 4000;
		soundHit1[] = {"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_01",2.51189,1,2000};
		soundHit2[] = {"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_02",2.51189,1,2000};
		soundHit3[] = {"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_03",2.51189,1,2000};
		multiSoundHit[] = {"soundHit1",0.34,"soundHit2",0.33,"soundHit3",0.33};
		explosionSoundEffect = "DefaultExplosion";
		soundFly[] = {"vn\sounds_f_vietnam\weapons\launcher\rocket_fly_1.ogg",1,1,400};
		soundEngine[] = {"",1,1,50};
		supersonicCrackNear[] = {"A3\Sounds_F\weapons\Explosion\supersonic_crack_close",0.398107,1,20};
		supersonicCrackFar[] = {"A3\Sounds_F\weapons\Explosion\supersonic_crack_50meters",0.316228,1,50};
		deflecting = 0;
		cmImmunity = 0.92;
		dangerRadiusHit = -1;
		suppressionRadiusHit = 30;
		class HitEffects
		{
			hitWater = "ImpactEffectsWaterRocket";
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						maxTrackableSpeed = 600;
						minTrackableATL = 3;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						color[] = {1,0,0,1};
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						allowsMarking = 1;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = ";
						aimDown = 0;
						minTrackableSpeed = -1e+010;
						maxTrackableATL = 1e+010;
					};
				};
			};
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						maxTrackableSpeed = 600;
						minTrackableATL = 3;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						color[] = {1,0,0,1};
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						allowsMarking = 1;
						class AirTarget
						{
							minRange = 500;
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = ";
						aimDown = 0;
						minTrackableSpeed = -1e+010;
						maxTrackableATL = 1e+010;
					};
				};
			};
		};
		maverickWeaponIndexOffset = 0;
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 0;
		tBody = 0;
		simulation = "shotMissile";
		visibleFire = 32;
		audibleFire = 32;
		visibleFireTime = 20;
		soundHit[] = {",100,1};
		access = 3;
		underwaterHitRangeCoef = 1;
		typicalSpeed = 900;
		explosionForceCoef = 1;
		isCraterOriented = 0;
		craterShape = ";
		weaponType = "Default";
		animated = 0;
		shadow = 0;
		cartridge = ";
		tracerColor[] = {0.7,0.7,0.5,0.04};
		tracerColorR[] = {0.7,0.7,0.5,0.04};
		soundFakeFall[] = {"soundFall",1};
		hitGroundSoft[] = {"soundHit",1};
		hitGroundHard[] = {"soundHit",1};
		hitMan[] = {"soundHit",1};
		hitArmor[] = {"soundHit",1};
		hitIron[] = {"soundHit",1};
		hitBuilding[] = {"soundHit",1};
		hitFoliage[] = {"soundHit",1};
		hitWood[] = {"soundHit",1};
		hitGlass[] = {"soundHit",1};
		hitGlassArmored[] = {"soundHit",1};
		hitConcrete[] = {"soundHit",1};
		hitRubber[] = {"soundHit",1};
		hitPlastic[] = {"soundHit",1};
		hitDefault[] = {"soundHit",1};
		hitMetal[] = {"soundHit",1};
		hitMetalplate[] = {"soundHit",1};
		hitTyre[] = {"soundHit",1};
		hitWater[] = {"soundHit",1};
		impactGroundSoft[] = {"soundImpact",1};
		impactGroundHard[] = {"soundImpact",1};
		impactMan[] = {"soundImpact",1};
		impactIron[] = {"soundImpact",1};
		impactArmor[] = {"soundImpact",1};
		impactBuilding[] = {"soundImpact",1};
		impactFoliage[] = {"soundImpact",1};
		impactWood[] = {"soundImpact",1};
		impactGlass[] = {"soundImpact",1};
		impactGlassArmored[] = {"soundImpact",1};
		impactConcrete[] = {"soundImpact",1};
		impactRubber[] = {"soundImpact",1};
		impactPlastic[] = {"soundImpact",1};
		impactDefault[] = {"soundImpact",1};
		impactMetal[] = {"soundImpact",1};
		impactMetalplate[] = {"soundImpact",1};
		impactTyre[] = {"soundImpact",1};
		impactWater[] = {"soundImpact",1};
		grenadeFireSound[] = {};
		grenadeBurningSound[] = {};
		deflectionSlowDown = 0.8;
		explosive = 1;
		craterEffects = "AAMissileCrater";
		craterWaterEffects = "ImpactEffectsWater";
		effectsMissileInit = ";
		effectsSmoke = "SmokeShellWhite";
		effectsFire = "CannonFire";
		effectFlare = "FlareShell";
		effectFly = ";
		mineJumpEffects = "";
		waterEffectOffset = 0.45;
		directionalExplosion = 0;
		explosionAngle = 60;
		explosionDir = "explosionDir";
		explosionPos = "explosionPos";
		explosionEffectsDir = "explosionDir";
		minimumSafeZone = 0.1;
		soundTrigger[] = {};
		soundActivation[] = {};
		soundDeactivation[] = {};
		minTimeToLive = 0;
		irLock = 0;
		laserLock = 0;
		nvLock = 0;
		artilleryLock = 0;
		hitOnWater = 0;
		lockSeekRadius = 100;
		maverickweaponIndexOffset = 0;
		artilleryDispersion = 1;
		artilleryCharge = 1;
		shootDistraction = -1;
		explosionTime = 0;
		icon = ";
		submunitionAmmo = "";
		explosionType = "explosive";
		mineTrigger = "RangeTrigger";
		mineBoundingTime = 3;
		mineBoundingDist = 3;
		mineInconspicuousness = 10;
		mineFloating = -1;
		mineDiveSpeed = 1;
		minePlaceDist = 0.5;
		class HitEffects
		{
			hitWater = "ImpactEffectsWaterRocket";
		};
		suppressionRadiusBulletClose = -1;
		dangerRadiusBulletClose = -1;
		caliber = 1;
		whistleOnFire = 0;
		minDamageForCamShakeHit = 0.55;
	}
}