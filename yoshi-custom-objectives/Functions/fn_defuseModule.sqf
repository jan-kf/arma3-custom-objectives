/* 
    Parameters: _this = [module, syncedObjects]
*/
params ["_logic", "_id", "_params"];

if (isDedicated) exitWith {};

{
    // Generate a bomb preset (an array: [buttonCount, buttonData])
    private _extrasPreset = [_x] call YOSHI_CO_fnc_generateBombExtras;
    private _complexWiresPreset = [_extrasPreset] call YOSHI_CO_fnc_generateComplexWiresPreset;
    private _simpleWiresPreset = [] call YOSHI_CO_fnc_generateSimpleWiresPreset;
    private _keypadPreset = [] call YOSHI_CO_fnc_generateKeypadPreset;
    // Store the preset on the object (so each synced object can have its own configuration)
    _x setVariable ["complexWires", _complexWiresPreset, true];
    _x setVariable ["simpleWires", _simpleWiresPreset, true];
    _x setVariable ["keypad", _keypadPreset, true];
    _x setVariable ["extrasPreset", _extrasPreset, true];

    private _actionNumber = _x addAction [
        "Defuse",
        {
            params ["_target", "_caller", "_actionId", "_arguments"];
            // Pass both the object (_target) and the player (_caller) to openGUI
            [_target] spawn YOSHI_CO_fnc_openGUI;
        },
        nil, 6, false, true, "", "alive _target"
    ];
    _x setVariable ["defuseActionNumber", _actionNumber, true];
} forEach (synchronizedObjects _logic);