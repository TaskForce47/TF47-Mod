// import stuff
#include "macros.hpp"

/*
 *	Author: PDT
 *	sets the player's NVG effect; effects are defined in macros.hpp
 *
 *	Arguments:
 *  None
 *
 *	Return Value:
 *	<ARRAY> - [<STRING>, <BOOL>], ["NVG Effect", true if effect was set; false if not]
 *
 * example:
 * [] spawn PDT_EnhancedNVG_fnc_setNvgEffect;
 */

// player is not using NVGs, exit
if !(call TF47_EnhancedNVGs_fnc_getVisionMode) exitWith {
  _return = ["", false];
  _return
};

private _nvgEffect = call TF47_EnhancedNVGs_fnc_getNvgEffect;  // nvg VFX
private _effect = ppEffectCreate ["ColorCorrections", 1500]; // effect

// change effect based on player's selection in CBA settings
switch (_nvgEffect select 0) do {
  case "WhitePhosphor": { // player wants WP effect
    _nvgEffect = [WPEFFECT,WPACEEFFECT] select (_nvgEffect select 1);
  };
  case "MWPhosphor": {    // player wants MW effects
    _nvgEffect = [MWEFFECT, MWACEEFFECT] select (_nvgEffect select 1);
  };
  default {              // player wants GP effects
    _nvgEffect = [];
  };
};

// player doesn't want NVG effects, exit
if (_nvgEffect isEqualTo []) exitWith {
  _return = ["", false];
  _return
};

_effect ppEffectAdjust _nvgEffect; // set the effect
_effect ppEffectForceInNVG true;   // force it in NVGs
_effect ppEffectCommit 0.01;       // commit the effect
_effect ppEffectEnable true;

// wait until player isn't using NVGs
waitUntil {!(call TF47_EnhancedNVGs_fnc_getVisionMode)};
_effect ppEffectEnable false; // hide the effect
ppEffectDestroy _effect;      // get rid of the effect
