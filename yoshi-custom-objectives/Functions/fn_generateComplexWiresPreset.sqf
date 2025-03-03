/*
    Generates a complex wires preset.
    Returns an array: [buttonCount, buttonData]
    where buttonData is an array of arrays [led (bool), star (bool), color (string)]
*/
params ["_extra_preset"];

private _generate_CW = {
    private _buttonCount = 6; 
    private _allowedColors = ["Red", "Blue", "White", "Red/Blue", "Blue/White", "Red/White"];
    private _buttonData = [];

    for "_i" from 0 to (_buttonCount - 1) do {
        private _led = (random 1 > 0.5);
        private _star = (random 1 > 0.5);
        private _color = selectRandom _allowedColors;
        _buttonData pushBack [_led, _star, _color, false];
    };

    [_buttonCount, _buttonData]
};

private _complexWireData = [] call _generate_CW;

private _isAlreadySolved = [_complexWireData, _extra_preset] call YOSHI_CO_fnc_checkComplexWiresSolution;

while {_isAlreadySolved} do {
    _complexWireData = [] call _generate_CW;
    _isAlreadySolved = [_complexWireData, _extra_preset] call YOSHI_CO_fnc_checkComplexWiresSolution;
};

_complexWireData
