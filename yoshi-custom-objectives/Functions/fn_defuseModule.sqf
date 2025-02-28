/* 
    Parameters: _this = [module, syncedObjects]
*/
params ["_logic", "_id", "_params"];

if (isDedicated) exitWith {};

{
    // Generate a bomb preset (an array: [buttonCount, buttonData])
    private _preset = [] call YOSHI_CO_fnc_generateBombPreset;
    // Store the preset on the object (so each synced object can have its own configuration)
    _x setVariable ["bombPreset", _preset, true];

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