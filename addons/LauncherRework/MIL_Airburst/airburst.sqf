params ["_unit","_round","_fuse",["_randomFail",0]];

_fuse = parseNumber (player getVariable ["FuseSetting","0"]);

if ((_fuse >= 40) && (_fuse < 70) && ((random 1) > 0.85)) exitWith {
	private ["_text"];
	player setVariable ["FuseSetting","0",false];
	sleep 1;
	hint parseText "<t color='#ff0000'>Fuse failed</t>";
};

if (_fuse >= 40) then {	
	waitUntil {(_unit distance _round) >= _fuse};
	_can = "Land_BakedBeans_F" createVehicle (getPos _round);
	_can setPosATL (getPosATL _round);
	sleep 0.1;
	deleteVehicle _can;
	hint "";
};

player setVariable ["FuseSetting","0",false];