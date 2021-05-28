/*
*   Author: Patch & TF47itz
*   Sets up player actions.
*   params: _player: the unit to add actions to.
*/

params ["_player"];
        
// player addAction ["Rappel Self", {[player, vehicle player] call TF47_fnc_AUR_Rappel_Action;}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Action_Check"];

// player addAction ["Rappel AI Units", { 
        // [player] call TF47_fnc_AUR_Rappel_AI_Units_Action;
// }, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_AI_Units_Action_Check"];

player addAction ["Climb To Top", { 
        [player] call TF47_fnc_AUR_Rappel_Climb_To_Top_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Climb_To_Top_Action_Check"];

player addAction ["Detach Rappel Device", { 
        [player] call TF47_fnc_AUR_Rappel_Detach_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Detach_Action_Check"];

player addAction ["Climb Up", { 
        [player] call TF47_fnc_AUR_Climb_Up_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Climb_Up_Action_Check"];


player addAction ["Place Rappel Anchor", { 
        [player] call TF47_fnc_AUR_Place_Anchor_Action;
}, nil, 0, false, true, "", "[player] call TF47_FNC_AUR_Place_Anchor_Action_Check"];

player addAction ["Tie in", { 
        [player] call TF47_fnc_AUR_Tie_In_Action;
}, nil, 0, false, true, "", "_this  call TF47_fnc_AUR_Tie_In_Action_Check"];

player addAction ["Place Rappel Point", { 
        [player, 80] call TF47_fnc_AUR_Place_Rappel_Point_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Place_Rappel_Point_Action_Check"];

player addAction ["Pick Up Rappel Point", { 
        [player, 80] call TF47_fnc_AUR_Pickup_Rappel_Point_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Pickup_Rappel_Point_Action_Check"];

player addAction ["Pack Up Rope", {
        [player] call TF47_fnc_AUR_PackRope_Action;
}, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_PackRope_Action_Check"];



player addEventHandler ["Respawn", {
        player setVariable ["AUR_Actions_Loaded",false];
}];