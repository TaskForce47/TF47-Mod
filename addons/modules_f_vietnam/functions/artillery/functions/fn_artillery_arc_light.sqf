/*
    File: fn_artillery_arc_light.sqf
    Author: Ethan Johnson
    Date: 2020-10-27
    Last Update: 2021-01-04
    Public: No

    Description:
    Function which spawns the bombs for the Arc Light artillery mission

    Parameter(s):
    _start_pos - Position at which the bombing run should start [ARRAY]
    _unit - Unit which called in the run [OBJECT]
    _end_pos - Position at which the bombing run should end [ARRAY]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [[0,0,0],player,[100,100,0]] call vn_fnc_artillery_arc_light
*/


params ["_start_pos","_unit","_end_pos"];

private _max = 20;
private _ammo_class = "vn_bomb_750_m117_he_ammo";
private _divergence = 50;

["011", "Covey", _unit] call vn_fnc_artillery_message;

for "_i" from 1 to _max do
{
        private _x_pos = linearConversion [1, _max, _i, (_start_pos getPos [-150, _start_pos getDir _end_pos])#0, (_start_pos getPos [150, _start_pos getDir _end_pos])#0];
        private _y_pos = linearConversion [1, _max, _i, (_start_pos getPos [-150, _start_pos getDir _end_pos])#1, (_start_pos getPos [150, _start_pos getDir _end_pos])#1];

        private _height = 1500;
        private _velocity = random[-1, -150, -300];


        private _position = [_x_pos + random[-_divergence,0,_divergence], _y_pos + random[-_divergence,0,_divergence], _height];
        private _bomb = createVehicle [_ammo_class, _position, [], 0, "CAN_COLLIDE"];
        _bomb setPosATL _position;
        _bomb setVectorDirAndUp [[0,0,-1],[0,1,0]];
        _bomb setVelocity [0, 0, _velocity];
        sleep 0.1;
};
