params ["_index"];

private _simpleWireData = uiNamespace getVariable ["DefuseDialog_SimpleWires", []];
if (isNil "_simpleWireData" || {_simpleWireData isEqualTo []}) exitWith {};
private _extra_preset = uiNamespace getVariable ["DefuseDialog_ExtrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

private _lastDigitIsEven = (_extra_preset select 1) select 1;
private _hasParallelPort = "port_parallel" in (_extra_preset select 2);
private _has2OrMoreBatteries = count (_extra_preset select 3) >= 2;

private _object = _extra_preset select 0;

private _buttonCount = _simpleWireData select 0;
private _buttonsData = _simpleWireData select 1;
private _colorArray = [];
{
    _colorArray pushBack (_x select 0);
} forEach _buttonsData;

private _getColorCount = {
    params ["_color", "_array"];
    private _count = 0;
    {
        if (_x isEqualTo _color) then {
            _count = _count + 1;
        };
    } forEach _array;

    _count
};

if (_index < 0 || {_index >= _buttonCount}) exitWith {};

private _data = _buttonsData select _index;
_data set [1, true]; // Simulate a cut wire
uiNamespace setVariable ["DefuseDialog_SimpleWires", _simpleWireData];
_object setVariable ["simpleWires", _simpleWireData, true];

private _display = uiNamespace getVariable ["DefuseDialog", displayNull];
if (isNull _display) exitWith {};

private _wireCtrl = _display displayCtrl (4400 + _index);
_wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireNone.paa";

private _buttonCtrl = _display displayCtrl (4600 + _index);
_buttonCtrl ctrlShow false;

private _redColorCount = ["Red", _colorArray] call _getColorCount;
private _blueColorCount = ["Blue", _colorArray] call _getColorCount;
private _yellowColorCount = ["Yellow", _colorArray] call _getColorCount;
private _whiteColorCount = ["White", _colorArray] call _getColorCount;
private _blackColorCount = ["Black", _colorArray] call _getColorCount;

private _correct = false;

// Check if the wire was cut correctly
if (_buttonCount == 3) then {
    if (_colorArray isEqualTo ["Blue", "Blue", "Red"]) then {
        _correct = (_index == 1);
    } else {
        if (_redColorCount == 0) then {
            _correct = (_index == 1);
        } else {
            _correct = (_index == 2);
        };
    };
};
if (_buttonCount == 4) then {
    if ((_redColorCount >= 2) && !_lastDigitIsEven) then {
        // find index of last red wire
        private _lastRedIndex = -1;
        {
            if (_x isEqualTo "Red") then {
                _lastRedIndex = _forEachIndex;
            };
        } forEach _colorArray;
        _correct = (_index == _lastRedIndex);
    } else {
        if (((_colorArray select 3) isEqualTo "Yellow") && (_redColorCount == 0)) then {
            _correct = (_index == 0);
        } else {
            if (_blueColorCount == 1) then {
                _correct = (_index == 0);
            } else {
                if (_yellowColorCount >= 2) then {
                    _correct = (_index == 3);
                } else {
                    _correct = (_index == 1);
                };
            };
        };
    };
};
if (_buttonCount == 5) then {
    if (((_colorArray select 4) isEqualTo "Black") && !_lastDigitIsEven) then {
        _correct = (_index == 3);
    } else {
        if ((_redColorCount == 1) && (_yellowColorCount >= 2)) then {
            _correct = (_index == 0);
        } else {
            if (_blackColorCount == 0) then {
                _correct = (_index == 1);
            } else {
                _correct = (_index == 0);
            };
        };
    };
};
if (_buttonCount == 6) then {
    if ((_yellowColorCount == 0) && !_lastDigitIsEven) then {
        _correct = (_index == 2);
    } else {
        if ((_yellowColorCount == 1) && (_whiteColorCount >= 2)) then {
            _correct = (_index == 3);
        } else {
            if (_redColorCount == 0) then {
                _correct = (_index == 5);
            } else {
                _correct = (_index == 3);
            };
        };
    };
};



if (_correct) then {
    private _statusCtrl = _display displayCtrl 1003;
    _statusCtrl ctrlSetText "\yoshi-custom-objectives\UI\moduleDoneLightOn.paa";
    [_object, ["successBell", 100, 1]] remoteExec ["say3D"];
} else {
    private _statusCtrl = _display displayCtrl 1003;
    _statusCtrl ctrlSetText "\yoshi-custom-objectives\UI\moduleDoneLightFail.paa";
    [_object] spawn {
        params ["_object"];

        [_object, ["chargingSound", 300, 1]] remoteExec ["say3D"];
        sleep 2;
        createVehicle ["Bomb_04_F", getPosATL _object, [], 0, "CAN_COLLIDE"];
    };
    private _defuseActionNumber = _object getVariable ["defuseActionNumber", -1];
    if (_defuseActionNumber != -1) then {
        _object removeAction _defuseActionNumber;
    };
};

