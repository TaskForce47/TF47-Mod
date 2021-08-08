///////
//Airburst HE
//By: Millenwise (beno_83au)
///////
//Use and abuse as required. Please just give credit for the original concept.
///////

I created this for VBS3 and converted it across (and fancied it up) for ArmA 3. It allows required ammunition types to be detonated for use as an airburst round. This was converted primarily for the ADF Uncut Carl Gustav 84mm HE round, however it could conceivably be used for any explosive round.

Features:

	- GUI for quick input of range.
	- Engagement distances:
		- Range setting under 40m will have no affect (i.e. impact detonation).
		- Range setting between 40m and 70m will have a chance to fail to detonate.
	- Can be applied to only selected players (e.g. units who would be trained in the application of HE rounds for airburst).
	- Can account for numerous ammunition types (customisable).
	- Range setting will be "remembered" until a round is fired (pre-set a range into the next round).
	- More of a sacrifice on realism in favour of gameplay:
		- Range can be re-adjusted, including closer, without "breaking" the fuse.
		- AT gunner is the one making fuse adjustments.
	- ACE3 compatible.

To use:	

	- Copy the folder MIL_Airburst to your mission folder.
	
	- Add these lines to your description.ext
		#include "MIL_Airburst\defines.hpp"	//(basic level of GUI defines, nothing flash, only use if needed)
		#include "MIL_Airburst\fuseSetting_dialog.hpp"
	
	- Run this command from initPlayerLocal.sqf for MP (or init.sqf for SP) before the mission starts:
		private ["_units","_ammo"];
		_units = ["_unitName"];
		_ammo = ["_magazineName"];
		if ((str player) in _units) then {
			nul = _ammo execVM "MIL_Airburst\initAirburst.sqf";
		};
		
		_unitName - string - unit/s to be allowed to set ranges.
		_magazineName - string - magazine/s to be allowed to have their range set.
		
		Exmaple:
		private ["_units","_ammo"];
		_units = ["p1","p2"];
		_ammo = ["RPG32_HE_F"];
		if ((str player) in _units) then {
			nul = _ammo execVM "MIL_Airburst\initAirburst.sqf";
		};
		
Credits:

	- madpat3 for his German translation.