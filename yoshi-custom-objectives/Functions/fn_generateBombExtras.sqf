/*
    Generates a bomb preset.
    Returns an array: [buttonCount, buttonData]
    where buttonData is an array of arrays [led (bool), star (bool), color (string)]
*/

/*
    Function: GenerateRandomString
    Generates a 6-character random string with the following rules:
    - Contains at least one letter and one number
    - Ends with a number (1-9)
    - Excludes letters Y, O and number 0
    - Outputs `endIsEven` and `containsVowel`
    
    Returns:
    - [_string, _endIsEven, _containsVowel]
*/
params ["_object"];

private _letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Z"]; // Excluding Y and O
private _vowels = "AEIUE"; // Valid vowels
private _numbers = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]; // no 0

private _serialNumber = "";
private _containsLetter = false;
private _containsNumber = false;
private _containsVowel = false;

// Generate first 5 characters
for "_i" from 1 to 5 do {
    private _isLetter = floor (random 2) == 0; // 50% chance for letter or number
    private _char = "";

    if (_isLetter || !_containsLetter) then { // Ensure at least one letter
        _char = _letters select (floor (random (count _letters)));
        _containsLetter = true;
        if (_char in _vowels) then { _containsVowel = true; };
    } else {
        _char = _numbers select (floor (random (count _numbers)));
        _containsNumber = true;
    };

    _serialNumber = _serialNumber + _char;
};

// Ensure last character is always a number
private _lastChar = _numbers select floor (random (count _numbers));
_serialNumber = _serialNumber + _lastChar;

// Check if last character is even
private _endIsEven = _lastChar in ["2", "4", "6", "8"];


private _possibleIndicators = ["SND", "CLR", "CAR", "IND", "FRQ", "SIG", "NSA", "MSA", "TRN", "BOB", "FRK"];
private _indicator =  selectRandom _possibleIndicators;
private _indicatorLit = (floor (random 2)) == 0;


private _portCount = random [1, 3, 6]; 
private _possiblePorts = ["port_parallel", "port_dvi", "port_ps2", "port_rj45", "port_rca", "port_serial"];
private _randomizedPorts = _possiblePorts call BIS_fnc_arrayShuffle;
_randomizedPorts resize _portCount;

private _batteryCount = random [1, 1.5, 8];
private _possibleBatteries = ["battery_1", "battery_2", "battery_3", "battery_4", "battery_5", "battery_6", "battery_7", "battery_8"];
private _randomizedBatteries = _possibleBatteries call BIS_fnc_arrayShuffle;
_randomizedBatteries resize _batteryCount;

[_object, [_serialNumber, _endIsEven, _containsVowel], _randomizedPorts, _randomizedBatteries, [_indicator, _indicatorLit]]
