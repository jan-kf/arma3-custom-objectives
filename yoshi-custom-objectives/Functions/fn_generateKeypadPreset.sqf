/*
*/
private _generate_KP = {
    private _allGlyphs = [
        "copyright", 
        "filledstar", 
        "hollowstar", 
        "smileyface", 
        "doublek", 
        "omega", 
        "squidknife", 
        "pumpkin", 
        "hookn", 
        "six", 
        "squigglyn", 
        "at", 
        "ae", 
        "meltedthree", 
        "euro", 
        "nwithhat", 
        "dragon", 
        "questionmark", 
        "paragraph", 
        "rightc", 
        "leftc", 
        "pitchfork", 
        "cursive", 
        "tracks", 
        "balloon", 
        "upsidedowny", 
        "bt"
    ];

    private _columns = [
        ["balloon", "at", "upsidedowny", "squigglyn", "squidknife", "hookn", "leftc"],
        ["euro", "ballon", "leftc", "cursive", "hollowstar", "hookn", "questionmark"],
        ["copyright", "pumpkin", "cursive", "doublek", "meltedthree", "upsidedowny", "hollowstar"],
        ["six", "paragraph", "bt", "squidknife", "doublek", "questionmark", "smileyface"],
        ["pitchfork", "smileyface", "bt", "rightc", "paragraph", "dragon", "filledstar"],
        ["six", "euro", "tracks", "ae", "pitchfork", "nwithhat", "omega"]
    ];
    private _chosenColumn = selectRandom _columns; 
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


private _keypadData = [] call _generate_KP;

_keypadData
