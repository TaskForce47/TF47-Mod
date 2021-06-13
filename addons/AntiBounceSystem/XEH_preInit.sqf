/* 

	Function: CBA_fnc_addKeybind

	Description:
	 Adds || updates the keybind handler for a specified mod action, && associates
	 a function with that keybind being pressed.

	Parameters:
	 _modName           Name of the registering mod [String]
	 _actionId  	    Id of the key action. [String]
	 _displayName       Pretty name, || an array of strings for the pretty name && a tool tip [String]
	 _downCode          Code for down event, empty string for no code. [Code]
	 _upCode            Code for up event, empty string for no code. [Code]

	 Optional:
	 _defaultKeybind    The keybinding data in the format [DIK, [shift, ctrl, alt]] [Array]
	 _holdKey           Will the key fire every frame while down [Bool]
	 _holdDelay         How long after keydown will the key event fire, in seconds. [Float]
	 _overwrite         Overwrite any previously stored default keybind [Bool]

*/ 

#include "\a3\editor_f\Data\Scripts\dikCodes.h"

["ABS_enableMod", "CHECKBOX", ["Enable Anti-Bounce System", "Master switch for all vehicles. Requires mission restart."], "Anti-Bounce System" ,true, 1, {}, true] call CBA_Settings_fnc_init;