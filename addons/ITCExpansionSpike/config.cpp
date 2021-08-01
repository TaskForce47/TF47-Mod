class CfgPatches {
	class itc_land_spike {
		author = "ITC Addons Team";
		authors[] = {"TF47 Desty"};
		requiredaddons[] = {"A3_Weapons_F"};
		requiredversion = 1.9;
		units[] = {};
		weapons[] = {"tf47_itc_land_spikeLR"};
		magazines[] = {"tf47_itc_land_spikeLR_1rnd"};
	};
};
class NewTurret;

#include "config\baseControls.hpp"
#include "config\CfgAmmo.hpp"
#include "config\CfgMagazines.hpp"
#include "config\CfgWeapons.hpp"
#include "config\CfgVehicles.hpp"
#include "config\cfgFunctions.hpp"
#include "config\ace_missileguidance_AttackProfiles.hpp"
#include "config\ITC_Land_SpikeSeeker.hpp"
