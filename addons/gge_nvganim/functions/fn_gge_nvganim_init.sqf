if (isDedicated) exitWith {};

gge_nvganim_fnc_NVGAnimHandler = {
	if (gge_core_var_NVGChanged) then { // Previously included check for () - look into reusing this
		_toggleNVG = (currentVisionMode player) > 0;
		_nvgAnim = ["gge_nvganim_anim_nvgsdown", "gge_nvganim_anim_nvgsup"] select _toggleNVG;
		
		_canPlayAnim = (
			(stance player != "PRONE") &&
			!(missionNamespace getVariable ["gge_canting_var_cantingAim", false]) &&
			!(missionNamespace getVariable ["gge_captives_var_isEscorting", false]) &&
			((cameraOn == player) && !(cameraView == "GUNNER"))
		);
		
		if (_canPlayAnim) then {
			[_nvgAnim, false] call gge_core_fnc_playGesture;
		};
		//player action [["NVGogglesOff", "NVGoggles"] select _toggleNVG, player];

	};
};


["GGE NVG Animation Handler Initialised..."] call gge_core_fnc_debugLog;

// No need to return any more, this is handled in GGE Core Module Loader now
[gge_nvganim_fnc_NVGAnimHandler]