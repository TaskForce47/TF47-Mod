// get height from a position [x,y,z] to the next surface lying beneath. Over water, the height above sea level will be returned.
params ["_unit", "_unitStartPosition", "_rappelPoint", "_rappelDirection"];
private ["_dummy", "_z"];
/* 
OK, a bit complicated. For the rope length to be calculated correctly, we need to have the height from unit's start
position to the next surface lying underneath. In more complex situations, like from one building to another, or 
from a ship in water to another boat beneath, correct height is only found by 'getPos'. But getPos has the disadvantage,
that it        will give values near zero, if the position measured from lies beneath, but near the model the unit is rappelling 
from. I can only guess, that it has something to do with the boundaries of the model, which are wider than the optic 
appearance of the model itself. As a workaround, we will check for the height as long as we get some reasonable value 
by gradually increasing        the distance of the height measurement from the object the unit wants to rappel from. 
Due to the nature of complex 3D worlds, this could lead to imprecise measurements. But is is the only possible way I
know.
I will leave this documentation for someone brighter than me wondering. And do a better solution.

Have fun with it - markooff
*/
for "_i" from 2 to 10 do {        
        _unitStartPosition = _rappelPoint vectorAdd (_rappelDirection vectorMultiply _i);// check height 2m to 10m out from the rappel point        
        _unitStartPosition set [2, getPosASL _unit select 2];
        _dummy = "Sign_Arrow_Blue_F" createVehicle _unitStartPosition;
        hideObject _dummy;
        _dummy enableSimulation false;
        _dummy allowDamage false;
        _dummy setPosASL _unitStartPosition;
        _z = getPos _dummy select 2;
        deleteVehicle _dummy;
        // diag_log formatText ["%1%2%3%4%5", time, "s  (AUR_Position_GetPos_Z) _unitStartPosition: ", _unitStartPosition, ", z: ", _z];
        if ((getPos _dummy select 2) > AUR_Minimal_Rappel_Height) exitWith {
                // diag_log formatText ["%1%2%3", time, "s  (AUR_Position_GetPos_Z) exit at vector: ", _i];
        };
};
if (_z < AUR_Minimal_Rappel_Height) then {
        _z = [_unit] call TF47_fnc_AUR_Get_Unit_Height_Above_Ground;// security check, in case getPos fails for some reason
};
_z
