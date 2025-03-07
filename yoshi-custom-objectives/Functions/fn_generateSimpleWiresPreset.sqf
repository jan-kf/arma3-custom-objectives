/*
    Generates a complex wires preset.
    Returns an array: [buttonCount, buttonData]
    where buttonData is an array of arrays [led (bool), star (bool), color (string)]
*/
private _generate_SW = {
    private _buttonCount = selectRandom [3, 4, 5, 6]; 
    private _allowedColors = ["Red", "Blue", "White", "Black", "Yellow"];
    private _buttonData = [];

    // Generate initial button data
    for "_i" from 0 to (_buttonCount - 1) do {
        private _color = selectRandom _allowedColors;
        _buttonData pushBack [_color, false];
    };

    // Ensure array is always 6 values long by filling missing slots
    while { count _buttonData < 6 } do {
        _buttonData pushBack ["None", false];
    };

    [_buttonCount, _buttonData]
};


private _simpleWireData = [] call _generate_SW;

_simpleWireData
