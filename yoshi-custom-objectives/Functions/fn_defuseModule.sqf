/* 
    Parameters: _this = [module, syncedObjects]
*/
params ["_logic", "_id", "_params"];

if (isDedicated) exitWith {};

{
    // Generate a bomb preset (an array: [buttonCount, buttonData])
    private _preset = [] call YOSHI_CO_fnc_generateComplexWiresPreset;
    private _extrasPreset = [] call YOSHI_CO_fnc_generateBombExtras;
    // Store the preset on the object (so each synced object can have its own configuration)
    _x setVariable ["complexWiresPreset", _preset, true];
    _x setVariable ["extrasPreset", _extrasPreset, true];

    _x addAction [
        "Defuse",
        {
            params ["_target", "_caller", "_actionId", "_arguments"];
            // Pass both the object (_target) and the player (_caller) to openGUI
            [_target] spawn YOSHI_CO_fnc_openGUI;
        },
        nil, 6, false, true, "", "alive _target"
    ];
} forEach (synchronizedObjects _logic);