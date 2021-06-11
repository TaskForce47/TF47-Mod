/*
*   Author: Patch & Tirpitz
*   Editor: Rampage
*   Sets up player actions.
*   params: player: the unit to add actions to.
*/

//Rewrite to ACE Actions

params ["player"];
/* Legacy        
player addAction [localize "STR_AUR_RAPPEL_SELF", { 
        [player] call TF47_fnc_AUR_Rappel_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Action_Check"];
*/
/* Currently not working
player addAction [localize "STR_AUR_Rappel_AI", { 
        [player] call TF47_fnc_AUR_Rappel_AI_Units_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_AI_Units_Action_Check"];
*/
//[player] call TF47_fnc_AUR_Changeplayer_Action;//Was machst du wirklich?

player addAction [localize "STR_AUR_Throw_Grappling_Hook", { 
        [player] call TF47_fnc_AUR_Rappel_Climb_To_Top_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Climb_To_Top_Action_Check"];

player addAction [localize "STR_AUR_RAPPEL_DETACH", { 
        [player] call TF47_fnc_AUR_Rappel_Detach_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Detach_Action_Check"];

player addAction [localize "STR_AUR_Throw_Grappling_Hook", { 
        [player] call TF47_fnc_AUR_Climb_Up_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Climb_Up_Action_Check"];

player addAction [localize "STR_AUR_Place_Rappel_Anchor", { 
        [player] call TF47_fnc_AUR_Place_Anchor_Action;
}, nil, 0, false, true, "", "[player] call TF47_FNC_AUR_Place_Anchor_Action_Check"];

player addAction [localize "STR_AUR_Tie_In", { 
        [player] call TF47_fnc_AUR_Tie_In_Action;
}, nil, 0, false, true, "", "_this  call TF47_fnc_AUR_Tie_In_Action_Check"];

player addAction [localize "STR_AUR_Place Rappel Point", { 
        [player, 80] call TF47_fnc_AUR_Place_Rappel_Point_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Place_Rappel_Point_Action_Check"];

player addAction [localize "STR_AUR_Pick_Rappel_Point", { 
        [player, 80] call TF47_fnc_AUR_Pickup_Rappel_Point_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Pickup_Rappel_Point_Action_Check"];

player addAction [localize "STR_AUR_Pack_Rope", {
        [player] call TF47_fnc_AUR_PackRope_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_PackRope_Action_Check"];


player addEventHandler ["Respawn", {
        player setVariable ["AUR_Actions_Loaded",false];
}];

if (isNil{player getVariable "AUR_Rappel_AI_mutex"}) then {player setVariable ["AUR_Rappel_AI_mutex", time + AUR_AI_RAPPEL_CHECK_INTERVAL};  // help var to have less load while checking for AI units
if (isNil{player getVariable "AUR_Rappel_AI_mutex_last_check"}) then  {player setVariable ["AUR_Rappel_AI_mutex_last_check", false]};          // help var to have less load while checking for AI units
