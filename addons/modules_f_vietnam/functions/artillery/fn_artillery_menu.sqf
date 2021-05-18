/*
    File: fn_artillery_menu.sqf
    Author: Ethan Johnson
    Date: 2020-04-29
    Last Update: 2020-06-09
    Public: Yes

    Description:
    Artillery master fuction for the menu

    Parameter(s):
    _mode - Mode to call for the menu [STRING, defaults to ""]
    _params - Mode to call for the menu [ARRAY, defaults to []]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    ["init"] call vn_fnc_artillery_menu
*/

#define DISPLAY (uiNamespace getVariable ["vn_artillery_display",displayNull])

#define TITLE    (DISPLAY displayctrl 350)

#define CALLSIGN_LIST    (DISPLAY displayctrl 102)
#define AMMO_LIST    (DISPLAY displayctrl 103)
#define AMMO_DESCRIPTION    (DISPLAY displayctrl 203)
#define AMOUNT_COMBO    (DISPLAY displayctrl 104)
#define BUTTON   (DISPLAY displayctrl 105)
#define MAP    (DISPLAY displayctrl 7001)

#define AMMO_INDEX    (lbCurSel AMMO_LIST)
#define CALLSIGN_INDEX    (lbCurSel CALLSIGN_LIST)
#define CALLSIGN_VALUE    (CALLSIGN_LIST lbValue (lbCurSel CALLSIGN_LIST))
#define AMOUNT_INDEX    (lbCurSel AMOUNT_COMBO)

params
[
        ["_mode","",[""]],
        ["_params",[],[[]]]
];

if (isNil "vn_artillery_menu_choice") then
{
        vn_artillery_menu_choice = 0;
};

private _params_array = switch vn_artillery_menu_choice do
{
        case 1:
        {
                ["_callsign", "_name", "_description", "_icon", "_vehicleclass", "_containerclass", "_items", "_cooldown", "_tickets", "_cost", "_condition"]
        };
        case 3:
        {
                ["_callsign", "_name", "_description", "_icon", "_vehicleclass", "_cooldown", "_tickets", "_cost", "_condition"]
        };
        case 0;
        case 2:
        {
                ["_callsign", "_name", "_description", "_icon", "_ammo", "_allow_double", "_divergence", "_count", "_cooldown", "_tickets", "_cost", "_illumination", "_magazine", "_function", "_condition", "_origin", "_speed"]
        };
};


if (tolower _mode isEqualTo "draw") exitwith
{
        if (!isNil "vn_artillery_map_selecting_start" && {!isNil "vn_artillery_map_selecting_end"}) then
        {
                { deleteMarkerLocal _x; } foreach vn_artillery_markers;
                vn_artillery_markers = [];

                if !(isNil "vn_artillery_ammo_choice" && {isNil "vn_artillery_callsign_choice"}) then
                {
                        if (vn_artillery_ammo_choice > -1 && {vn_artillery_callsign_choice > -1}) then
                        {
            private _force_artillery_draw = false;
            private _array = (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1#vn_artillery_callsign_choice);
            if (count _array >= 18) then { _force_artillery_draw = ((_array#17) == 1); };

                                switch true do
                                {
                                        case (vn_artillery_menu_choice == 0 && {!_force_artillery_draw}):
                                        {
                                                vn_artillery_map_selecting_start params ["_x","_y"];

                                                (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1#vn_artillery_callsign_choice) params _params_array;

                                                private _divergence_negative = false;
                                                if (_divergence < 0) then
                                                {
                                                        _divergence_negative = true;
                                                        _divergence = abs _divergence;
                                                };

                                                private _dir = vn_artillery_map_selecting_end getDir vn_artillery_map_selecting_start;
                                                for "_m" from 0 to AMOUNT_INDEX do
                                                {
                                                        private _position = vn_artillery_map_selecting_start getPos [_divergence*(1.5+_m), _dir];
                                                        private _name = format["vn_artillery_marker_direction_%1_vehicle",_m];

                                                        private _marker_direction = createMarkerLocal [_name,_position];
                                                        _marker_direction setMarkerTypeLocal "loc_plane";
                                                        _marker_direction setMarkerDirLocal (_dir - 180);
                                                        _marker_direction setMarkerColorLocal "ColorWhite";
                                                        vn_artillery_markers pushBack _marker_direction;
                                                };

                                                private _marker_zone = createMarkerLocal ["vn_artillery_marker_zone_vehicle",[_x,_y,0]];
                                                _marker_zone setMarkerShapeLocal "ELLIPSE";
                                                _marker_zone setMarkerBrush "DIAGGRID";
                                                _marker_zone setMarkerColorLocal "ColorRed";
                                                _marker_zone setMarkerDirLocal (_dir - 180);
                                                if _divergence_negative then
                                                {
                                                        // Negative divergence is treated as circle rather than oval
                                                        _marker_zone setMarkerSizeLocal [_divergence,_divergence];
                                                }
                                                else
                                                {
                                                        _marker_zone setMarkerSizeLocal [_divergence*0.5,_divergence];
                                                };
                                                vn_artillery_markers pushBack _marker_zone;

                                                private _marker_background = createMarkerLocal ["vn_artillery_marker_background_vehicle",[_x,_y,0]];
                                                _marker_background setMarkerTypeLocal "n_unknown";
                                                _marker_background setMarkerColorLocal "ColorRed";
                                                vn_artillery_markers pushBack _marker_background;

                                                private _marker_icon = createMarkerLocal ["vn_artillery_marker_icon_vehicle",[_x,_y,0]];
                                                _marker_icon setMarkerTypeLocal "loc_mine";
                                                _marker_icon setMarkerColorLocal "ColorWhite";
                                                vn_artillery_markers pushBack _marker_icon;
                                        };
                                        case (vn_artillery_menu_choice == 1 && {!_force_artillery_draw}):
                                        {
                                                private _dir = vn_artillery_map_selecting_end getDir vn_artillery_map_selecting_start;
                                                private _position = vn_artillery_map_selecting_start getPos [30*1.5, _dir];
                                                private _name = format["vn_artillery_marker_direction_%1_vehicle",0];

                                                private _marker_direction = createMarkerLocal [_name,_position];
                                                _marker_direction setMarkerTypeLocal "loc_heli";
                                                _marker_direction setMarkerDirLocal (_dir - 180);
                                                _marker_direction setMarkerColorLocal "ColorWhite";
                                                vn_artillery_markers pushBack _marker_direction;

                                                private _marker_background = createMarkerLocal ["vn_artillery_marker_background_vehicle",vn_artillery_map_selecting_start];
                                                _marker_background setMarkerTypeLocal "n_unknown";
                                                _marker_background setMarkerColorLocal "ColorGreen";
                                                vn_artillery_markers pushBack _marker_background;

                                                private _marker_icon = createMarkerLocal ["vn_artillery_marker_icon_vehicle",vn_artillery_map_selecting_start];
                                                _marker_icon setMarkerTypeLocal "loc_container";
                                                _marker_icon setMarkerColorLocal "ColorWhite";
                                                vn_artillery_markers pushBack _marker_icon;
                                        };
                                        case (vn_artillery_menu_choice == 2 || _force_artillery_draw):
                                        {
                                                (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1#vn_artillery_callsign_choice) params _params_array;

                                                private _count = 1;
                                                if (_ammo isEqualType []) then
                                                {
                                                        _count = count _ammo;
                                                };
                                                if (AMOUNT_INDEX > 0) then { _count = _count*2; };
                                                for "_i" from 1 to (_count max 2) do
                                                {
                                                        private _x = linearConversion [1, _count, _i, (vn_artillery_map_selecting_start#0), (vn_artillery_map_selecting_end#0)];
                                                        private _y = linearConversion [1, _count, _i, (vn_artillery_map_selecting_start#1), (vn_artillery_map_selecting_end#1)];

                                                        private _marker_zone = createMarkerLocal [format["vn_artillery_marker_zone_%1",_i],[_x,_y,0]];
                                                        _marker_zone setMarkerShapeLocal "ELLIPSE";
                                                        _marker_zone setMarkerBrush "DIAGGRID";
                                                        _marker_zone setMarkerColorLocal "ColorRed";
                                                        _marker_zone setMarkerSizeLocal [_divergence,_divergence];
                                                        vn_artillery_markers pushBack _marker_zone;

                                                        private _marker_background = createMarkerLocal [format["vn_artillery_marker_background_%1",_i],[_x,_y,0]];
                                                        _marker_background setMarkerTypeLocal "n_unknown";
                                                        _marker_background setMarkerColorLocal "ColorRed";
                                                        vn_artillery_markers pushBack _marker_background;

                                                        private _marker_icon = createMarkerLocal [format["vn_artillery_marker_icon_%1",_i],[_x,_y,0]];
                     _marker_icon setMarkerTypeLocal "loc_mine";
                                                        _marker_icon setMarkerColorLocal "ColorWhite";
                                                        vn_artillery_markers pushBack _marker_icon;
                                                };
                                        };
                                        case (vn_artillery_menu_choice == 3):
                                        {
                                                {
                                                        private _marker_background = createMarkerLocal [format["vn_artillery_marker_background_%1",_foreachindex],_x];
                                                        _marker_background setMarkerTypeLocal "n_unknown";
                                                        _marker_background setMarkerColorLocal "ColorGreen";
                                                        vn_artillery_markers pushBack _marker_background;

                                                        private _marker_icon = createMarkerLocal [format["vn_artillery_marker_icon_%1",_foreachindex],_x];
                                                        _marker_icon setMarkerTypeLocal (["loc_LetterA","loc_LetterB"]#_foreachindex);
                                                        _marker_icon setMarkerColorLocal "ColorWhite";
                                                        vn_artillery_markers pushBack _marker_icon;

                                                } foreach [vn_artillery_map_selecting_start, vn_artillery_map_selecting_end];
                                        };
                                };
                        };
                };

                if
                (
                        lbCurSel AMMO_LIST >= 0
                        &&
                        {
                                lbCurSel CALLSIGN_LIST >= 0
                                &&
                                {
                                        lbCurSel AMOUNT_COMBO >= 0
                                        &&
                                        {
                                                !vn_artillery_map_selecting
                                                &&
                                                {
                                                        !isNil "vn_artillery_map_selecting_start"
                                                        &&
                                                        {
                                                                !isNil "vn_artillery_map_selecting_end"
                                                        }
                                                }
                                        }
                                }
                        }
                )
                then
                {
                        if isNil "vn_artillery_busy" then
                        {
                                // For some reason if the nil is removed "draw" is automagicaly passed through?
                                // Don't ask me how, I don't know either.
                                if ([nil] call vn_fnc_artillery_radio) then
                                {
                                        BUTTON ctrlEnable true;
                                        BUTTON ctrlSetTooltip localize "STR_VN_ARTILLERY_MENU_BUTTON_TOOLTIP_PASS";
                                }
                                else
                                {
                                        BUTTON ctrlEnable false;
                                        BUTTON ctrlSetTooltip localize "STR_VN_ARTILLERY_MENU_BUTTON_TOOLTIP_NO_RADIO";
                                };
                        }
                        else
                        {
                                BUTTON ctrlEnable false;
                                BUTTON ctrlSetTooltip localize "STR_VN_ARTILLERY_MENU_BUTTON_TOOLTIP_TIMEOUT";
                        };
                }
                else
                {
                        BUTTON ctrlEnable false;
                        BUTTON ctrlSetTooltip localize "STR_VN_ARTILLERY_MENU_BUTTON_TOOLTIP_INCOMPLETE";
                };
        };
        true
};
switch tolower _mode do
{
        case "init":
        {
                _params params ["_display"];

                if (!isNull (findDisplay 46)) then
                {
                        createDialog "vn_displayartillery";
                };
        };
        case "radio:type":
        {
                private _ctrl = uinamespace getVariable ["vn_artillery_display_preser_button",controlNull];
                // When new choices are added, add more switches
                switch vn_artillery_menu_choice do
                {
                        // Artillery support
                        case 0:
                        {
                                vn_artillery_menu_choice = 2;
                                _ctrl ctrlSetAngle [67.5, 0.5, 0.5];
                                TITLE ctrlSetText localize "STR_VN_ARTILLERY_MENU_TITLE_FIRE";
                        };
                        // Air support
                        case 2:
                        {
                                vn_artillery_menu_choice = 0;
                                _ctrl ctrlSetAngle [90, 0.5, 0.5];
                                TITLE ctrlSetText localize "STR_VN_ARTILLERY_MENU_TITLE_AIR";
                        };
         /*
                        // Transport support
                        case 2:
                        {
                                vn_artillery_menu_choice = 3;
                                _ctrl ctrlSetAngle [125, 0.5, 0.5];
                                TITLE ctrlSetText localize "STR_VN_ARTILLERY_MENU_TITLE_TRANSPORT";
                        };
                        // Resupply support
                        case 3:
                        {
                                vn_artillery_menu_choice = 1;
                                _ctrl ctrlSetAngle [110, 0.5, 0.5];
                                TITLE ctrlSetText localize "STR_VN_ARTILLERY_MENU_TITLE_RESUPPLY";
                        };
         */
                };
                vn_artillery_callsign_choice = -1;
                ['gui:clear'] call vn_fnc_artillery_menu;
                ['gui:setup'] call vn_fnc_artillery_menu;
        };
        case "onload":
        {
                _params params ["_display"];
                if (isNil "vn_artillery_module") exitWith
                {
                        _display closeDisplay 2;
                        diag_log "!!! VN artillery menu was opened without module placed !!!";
                        diag_log "!!! VN artillery menu was forced closed !!!";
                        true
                };

                uiNamespace setVariable ["vn_artillery_display",_display];

                if (isNil "vn_artillery_config") then
                {
                        // No config loaded? - Just save it here
                        missionNamespace setVariable
                        [
                                "vn_artillery_config",
                                (
                                        [configFile >> "vn_artillery_settings",missionConfigFile >> "vn_artillery_settings"]
                                        select
                                        (isClass (missionConfigFile >> "vn_artillery_settings"))
                                )
                        ];
                };
                if (isNil "vn_artillery_saved") then
                {
                        // Type, callsign, amount
                        vn_artillery_saved = [-1, -1, -1];
                };
                vn_artillery_saved_allow = false;
                vn_artillery_markers = [];

                ['gui:clear'] call vn_fnc_artillery_menu;
                ['gui:setup'] call vn_fnc_artillery_menu;
        };
        case "onunload":
        {
                if (vn_artillery_saved_allow) then
                {
                        vn_artillery_saved =
                        [
                                AMMO_INDEX,
                                CALLSIGN_VALUE,
                                AMOUNT_INDEX
                        ];
                };
                { deleteMarkerLocal _x; } foreach vn_artillery_markers;
                uiNamespace setVariable ["vn_artillery_display",displayNull];
        };
        case "lbselchanged":
        {
                _params params ["_ctrl_index","_lb_index"];
                if (_lb_index isEqualTo -1) exitWith {true};
                switch _ctrl_index do
                {
                        // Ammo type
                        case 0:
                        {
                                vn_artillery_ammo_choice = _lb_index;
                                vn_artillery_callsign_choice = -1;
                                ['gui:combo:callsign'] call vn_fnc_artillery_menu;
                                CALLSIGN_LIST ctrlEnable true;
                        };
                        // Callsign type
                        case 1:
                        {
                                vn_artillery_callsign_choice = _lb_index;
                                ['gui:combo:amount'] call vn_fnc_artillery_menu;
                                AMOUNT_COMBO ctrlEnable true;
                        };
                };

                if (_ctrl_index < 0 || _lb_index < 0) then
                {
                        AMMO_DESCRIPTION ctrlSetText localize "STR_VN_ARTILLERY_MENU_INFO_DEFAULT";
                }
                else
                {
                        AMMO_DESCRIPTION ctrlSetText localize "STR_VN_ARTILLERY_MENU_INFO_DEFAULT";
                        if !(isNil "vn_artillery_ammo_choice" && {isNil "vn_artillery_callsign_choice"}) then
                        {
                                if (vn_artillery_ammo_choice > -1 && {vn_artillery_callsign_choice > -1}) then
                                {
                                        (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1#vn_artillery_callsign_choice) params _params_array;

                                        private _cost_string = "";
                                        if !((missionNamespace getVariable ["vn_artillery_score_variable",""]) isEqualTo "") then
                                        {
                                                if (vn_artillery_menu_choice in [0,2]) then
                                                {
                                                        _cost_string = format[localize "STR_VN_ARTILLERY_MENU_COST_FORMAT",_cost * _double];
                                                }
                                                else
                                                {
                                                        _cost_string = format[localize "STR_VN_ARTILLERY_MENU_COST_FORMAT",_cost];
                                                };
                                        };

                                        AMMO_DESCRIPTION ctrlSetStructuredText parseText ([_name,_description,_cost_string] joinString "<br/>");
                                };
                        };
                };
        };
        case "mousebuttondown":
        {
                _params params ["_ctrl", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];
                if (_button isEqualTo 0) then
                {
                        private _position = (MAP ctrlMapScreenToWorld [_xPos, _yPos]);
                        vn_artillery_map_selecting = true;
                        vn_artillery_map_selecting_start = _position;
                        vn_artillery_map_selecting_end = _position;
                };
        };
        case "mousebuttonup":
        {
                _params params ["_ctrl", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];
                if (vn_artillery_map_selecting) then
                {
                        private _position = (MAP ctrlMapScreenToWorld [_xPos, _yPos]);
                        vn_artillery_map_selecting = false;
                        vn_artillery_map_selecting_end = _position;
                };
        };
        case "mousemoving":
        {
                _params params ["_ctrl", "_xPos", "_yPos", "_mouseOver"];
                if (vn_artillery_map_selecting) then
                {
                        private _position = (MAP ctrlMapScreenToWorld [_xPos, _yPos]);
                        vn_artillery_map_selecting_end = _position;
                };
        };
        case "gui:setup":
        {
                // Disable options that we don't want players changing yet.
                {
                        _x ctrlEnable false;
                } foreach [CALLSIGN_LIST, AMMO_LIST, AMOUNT_COMBO, BUTTON];

                AMMO_LIST ctrlAddEventHandler ["LBSelChanged",{ ["lbselchanged",[0,_this#1]] call vn_fnc_artillery_menu }];
                CALLSIGN_LIST ctrlAddEventHandler ["LBSelChanged",{ ["lbselchanged",[1,_this#1]] call vn_fnc_artillery_menu }];
                AMOUNT_COMBO ctrlAddEventHandler ["LBSelChanged",{ ["lbselchanged",[2,_this#1]] call vn_fnc_artillery_menu }];
                MAP ctrlAddEventHandler ["MouseButtonDown",{ ["mousebuttondown",_this] call vn_fnc_artillery_menu }];
                MAP ctrlAddEventHandler ["MouseButtonUp",{ ["mousebuttonup",_this] call vn_fnc_artillery_menu }];
                MAP ctrlAddEventHandler ["MouseExit",{ ["mousebuttonup",_this] call vn_fnc_artillery_menu }];
                MAP ctrlAddEventHandler ["MouseMoving",{ ["mousemoving",_this] call vn_fnc_artillery_menu }];
                MAP ctrlAddEventHandler ["Draw",{ ["draw",_this] call vn_fnc_artillery_menu }];
                BUTTON ctrlAddEventHandler ["ButtonClick",{ ["gui:button:bombardment",_this] call vn_fnc_artillery_menu; false }];

                private _title = ["STR_VN_ARTILLERY_MENU_TITLE_AIR", "STR_VN_ARTILLERY_MENU_TITLE_RESUPPLY", "STR_VN_ARTILLERY_MENU_TITLE_FIRE", "STR_VN_ARTILLERY_MENU_TITLE_TRANSPORT"];
                private _angle = [90, 110, 67.5, 125];

                private _ctrl_button = uinamespace getVariable ["vn_artillery_display_preser_button", controlNull];
                TITLE ctrlSetText localize (_title#vn_artillery_menu_choice);
                _ctrl_button ctrlSetAngle [(_angle#vn_artillery_menu_choice), 0.5, 0.5];

                ['gui:combo:ammo'] call vn_fnc_artillery_menu;
                {
                        private _index = (vn_artillery_saved#_foreachindex);
                        if (_index > -1) then
                        {
                                _x lbSetCurSel _index;
                        };
                } foreach [AMMO_LIST, CALLSIGN_LIST, AMOUNT_COMBO];
                vn_artillery_saved_allow = true;
        };
        case "gui:clear":
        {
                // Disable options that we don't want players changing yet.
                {
                        _x ctrlEnable false;
                } foreach [CALLSIGN_LIST, AMMO_LIST, AMOUNT_COMBO, BUTTON];

                CALLSIGN_LIST ctrlRemoveAllEventHandlers "LBSelChanged";
                AMMO_LIST ctrlRemoveAllEventHandlers "LBSelChanged";
                AMOUNT_COMBO ctrlRemoveAllEventHandlers "LBSelChanged";
                MAP ctrlRemoveAllEventHandlers "MouseButtonDown";
                MAP ctrlRemoveAllEventHandlers "MouseButtonUp";
                MAP ctrlRemoveAllEventHandlers "MouseExit";
                MAP ctrlRemoveAllEventHandlers "MouseMoving";
                BUTTON ctrlRemoveAllEventHandlers "ButtonClick";

                lbClear CALLSIGN_LIST;
                lbClear AMMO_LIST;
                lbClear AMOUNT_COMBO;

                AMMO_DESCRIPTION ctrlSetText "";

                vn_artillery_saved_allow = true;
        };
        case "gui:combo:ammo":
        {
                lbClear AMMO_LIST;
                AMMO_LIST lbSetCurSel -1;
                {
                        _x params ["_displayname"];
                        private _index = AMMO_LIST lbAdd _displayname;
                        AMMO_LIST lbSetTooltip [_index, _displayname];
                } foreach (vn_artillery_config_array#vn_artillery_menu_choice);
                AMMO_LIST ctrlEnable true;
        };
        case "gui:combo:callsign":
        {
                lbClear CALLSIGN_LIST;
                CALLSIGN_LIST lbSetCurSel -1;
                {
                        _x params _params_array;
                        if (call compile _condition) then
                        {
                                private _index = CALLSIGN_LIST lbAdd _name;
                                CALLSIGN_LIST lbSetPicture [_index, _icon];
                                CALLSIGN_LIST lbSetTooltip [_index, _name];
                                CALLSIGN_LIST lbSetValue [_index, _foreachindex];
                        };
                } foreach (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1);
                CALLSIGN_LIST ctrlEnable true;
        };
        case "gui:combo:amount":
        {
                if !(isNil "vn_artillery_ammo_choice" && {isNil "vn_artillery_callsign_choice"}) then
                {
                        (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1#vn_artillery_callsign_choice) params _params_array;
                        lbClear AMOUNT_COMBO;
                        AMOUNT_COMBO lbSetCurSel -1;

                        // Add normal amount
                        private _index = AMOUNT_COMBO lbAdd localize "STR_VN_ARTILLERY_MENU_AMOUNT_NORMAL";
                        AMOUNT_COMBO lbSetCurSel _index;

                        if (vn_artillery_menu_choice in [0,2] && {_allow_double > 0 }) then
                        {
                                private _score_variable = missionNamespace getVariable ["vn_artillery_score_variable",""];
                                private _score_pass = true;
                                if !(_score_variable isEqualTo "") then
                                {
                                        private _score = missionNamespace getVariable [_score_variable, 0];
                                        if (_score >= _cost*2) then
                                        {
                                                // Add heavy amount
                                                private _index = AMOUNT_COMBO lbAdd localize "STR_VN_ARTILLERY_MENU_AMOUNT_HEAVY";
                                        };
                                }
            else
            {
               private _index = AMOUNT_COMBO lbAdd localize "STR_VN_ARTILLERY_MENU_AMOUNT_HEAVY";
            };
                        };
                };
        };
        case "gui:button:bombardment":
        {
                DISPLAY closeDisplay 2;

                if !(isNil "vn_artillery_ammo_choice" && {isNil "vn_artillery_callsign_choice"}) then
                {
                        (vn_artillery_config_array#vn_artillery_menu_choice#vn_artillery_ammo_choice#1#vn_artillery_callsign_choice) params _params_array;

                        if (call compile _condition) then
                        {
                                private _player = call vn_fnc_player;

                                if (_player isEqualTo vehicle _player) then {_player playActionNow "vn_artillery_speaking";};
                                vn_artillery_saved = [ AMMO_INDEX, CALLSIGN_VALUE, AMOUNT_INDEX ];

                                switch vn_artillery_menu_choice do
                                {
                                        case 1:
                                        {
                                                // Resupply
                                                [vn_artillery_saved, vn_artillery_map_selecting_start, vn_artillery_map_selecting_end, _player, vn_artillery_menu_choice] remoteExec ["vn_fnc_artillery_resupply",2];
                                        };
                                        case 3:
                                        {
                                                // Transport
                                                [vn_artillery_saved, vn_artillery_map_selecting_start, vn_artillery_map_selecting_end, _player, vn_artillery_menu_choice] remoteExec ["vn_fnc_artillery_transport",2];
                                        };
                                        case 0;
                                        case 2:
                                        {
                                                // Air support & Artillery support
                                                [vn_artillery_saved, vn_artillery_map_selecting_start, vn_artillery_map_selecting_end, _player, vn_artillery_menu_choice] remoteExec ["vn_fnc_artillery_server_check",2];
                                        };
                                };

                                vn_artillery_busy = true;
                                [] spawn
                                {
                                        sleep 30;
                                        vn_artillery_busy = nil;
                                };
                        };
                };
        };
};
true
