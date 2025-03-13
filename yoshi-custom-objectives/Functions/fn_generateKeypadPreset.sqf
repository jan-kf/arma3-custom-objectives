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
        ["euro", "balloon", "leftc", "cursive", "hollowstar", "hookn", "questionmark"],
        ["copyright", "pumpkin", "cursive", "doublek", "meltedthree", "upsidedowny", "hollowstar"],
        ["six", "paragraph", "bt", "squidknife", "doublek", "questionmark", "smileyface"],
        ["pitchfork", "smileyface", "bt", "rightc", "paragraph", "dragon", "filledstar"],
        ["six", "euro", "tracks", "ae", "pitchfork", "nwithhat", "omega"]
    ];
    private _chosenColumn = selectRandom _columns; 
    private _shuffledGlyphs = _chosenColumn call BIS_fnc_arrayShuffle;
    _shuffledGlyphs resize 4;

    private _answerIndexArray = [];
    {
        private _index = _chosenColumn find _x;
        _answerIndexArray pushBack _index;
    } forEach _shuffledGlyphs;
    _answerIndexArray sort true;

    private _answerGlyphs = [];
    {
        _answerGlyphs pushBack (_chosenColumn select _x);
    } forEach _answerIndexArray;

    _shuffledGlyphs call BIS_fnc_arrayShuffle; // one more time for fun

    [_shuffledGlyphs, _answerGlyphs, []];
    
};


private _keypadData = [] call _generate_KP;

_keypadData
