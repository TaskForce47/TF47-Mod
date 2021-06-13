/*
 *	Author: PDT
 *	creates CBA settings
 *
 *	Arguments:
 *  None
 *
 *	Return Value:
 *	None
 *
 */

// ACE check
[
  "PDT_EnhancedNVG_Using_ACE",
  "CHECKBOX",
  [
    "Use ACE color preset",
    "Enable if using ACE"
  ],
  "Fawks's Enhanced NVGs",
  false
] call cba_settings_fnc_init;

// NVG effect select
[
  "PDT_EnhancedNVG_NVG_Effect",
  "LIST",
  [
    "NVG Effect",
    "
    Green Phosphor (no effect).\n
    Modern Warfare (greenish tint WP)\n
    White Phosphor (White Phosphor)
    "
  ],
  "Fawks's Enhanced NVGs",
  [
    [
      "",
      "WhitePhosphor",
      "MWPhosphor"
    ],
    [
      "Green Phosphor",
      "White Phosphor",
      "Modern Warfare"
    ],
    0
  ]
] call cba_settings_fnc_init;

// NVG blacklist
[
  "PDT_EnhancedNVG_NVG_Blacklist",
  "EDITBOX",
  [
    "Blacklisted NVG classnames", "Seperrate classnames by commas \nEg. className1, className2, className3, etc"
  ],
  "Fawks's Enhanced NVGs",
  ""
] call cba_settings_fnc_init;
