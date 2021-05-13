#include "script_component.hpp"

params [["_newState", true]];

private _tfarEnabled = !(isNil "TFAR_VolumeHudTransparency");

if (!_tfarEnabled) exitWith {};

if (_newState) then {
    TFAR_VolumeHudTransparency = GVAR(tfar);
    [] call TFAR_fnc_updateSpeakVolumeUI;
} else {
    GVAR(tfar) = TFAR_VolumeHudTransparency;
    TFAR_VolumeHudTransparency = 1;
    [] call TFAR_fnc_updateSpeakVolumeUI;
};
