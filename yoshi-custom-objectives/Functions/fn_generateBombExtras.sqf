/*
    Generates a bomb preset.
    Returns an array: [buttonCount, buttonData]
    where buttonData is an array of arrays [led (bool), star (bool), color (string)]
*/
private _portCount = random [1, 3, 6]; 
private _possiblePorts = ["port_parallel", "port_dvi", "port_ps2", "port_rj45", "port_rca", "port_serial"];
private _randomizedPorts = _possiblePorts call BIS_fnc_arrayShuffle;
_randomizedPorts resize _portCount;

private _batteryCount = random [1, 1.5, 8];
private _possibleBatteries = ["battery_1", "battery_2", "battery_3", "battery_4", "battery_5", "battery_6", "battery_7", "battery_8"];
private _randomizedBatteries = _possibleBatteries call BIS_fnc_arrayShuffle;
_randomizedBatteries resize _batteryCount;

[_randomizedPorts, _randomizedBatteries]
