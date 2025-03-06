#define GUI_GRID_X safeZoneX
#define GUI_GRID_Y safeZoneY
#define GUI_MODULE_1_X 11
#define GUI_MODULE_1_Y 3
#define UNIT_SIZE 1
#define GUI_GRID_W ((safeZoneW / 40) * UNIT_SIZE)
#define GUI_GRID_H ((safeZoneH / 25) * UNIT_SIZE)
#define SHORT_SIZE 2 * UNIT_SIZE
#define LONG_SIZE 16 * UNIT_SIZE
#define GUI_MODULE_WIDTH LONG_SIZE * GUI_GRID_W
#define GUI_MODULE_HEIGHT LONG_SIZE * GUI_GRID_H
#define GUI_SHORT_WIDTH SHORT_SIZE * GUI_GRID_W
#define GUI_SHORT_HEIGHT SHORT_SIZE * GUI_GRID_H
#define WIRE_SCALE 1.375



class RscText;
class RscButton;
class RscPicture;
class WireButton: RscButton
{
    colorDisabled[] = {0,0,0,0};
    colorBackground[] = {0,0,0,0};
    colorBackgroundDisabled[] = {0,0,0,0};
    colorBackgroundActive[] = {0.92,0.85,0.2,0.7};
    colorFocused[] = {0,0,0,0};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,0};
    soundClick[] = {"\yoshi-custom-objectives\Sounds\cutting-wire.ogg",1,1};
    soundEnter[] = {"\yoshi-custom-objectives\Sounds\hover.ogg",1,1};
};

class DefuseDialog
{
    idd = 9999;
    movingEnable = false;
    onLoad = "uiNamespace setVariable ['DefuseDialog', _this select 0]; [] spawn YOSHI_CO_fnc_setupButtons;";
    class controlsBackground {
        class Background: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_MODULE_HEIGHT;
            text = "\yoshi-custom-objectives\UI\complexWiresModuleBackground.paa";
        };
        class Ports: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\portPanel.paa";
        };
        class Batteries: RscPicture {
            idc = -1;
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
            text = "\yoshi-custom-objectives\UI\batteryPanel.paa";
        };
        class SerialAndIndicator: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y - SHORT_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\serialIndicatorPanel.paa";
        };
    };

    class controls
    {

        class StatusIndicator: RscPicture
        {
            idc = 1000;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 12.5)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * 0.5)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1.5 * GUI_SHORT_WIDTH;
            h = 1.5 * GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\moduleDoneLightOff.paa";
        };

        class RscButton_1600: WireButton
        {
            idc = 1600;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "";
            action = "[0] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1601: WireButton
        {
            idc = 1601;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 2 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "";
            action = "[1] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1602: WireButton
        {
            idc = 1602;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 3 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "";
            action = "[2] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1603: WireButton
        {
            idc = 1603;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 4 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "";
            action = "[3] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1604: WireButton
        {
            idc = 1604;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 5 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "";
            action = "[4] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1605: WireButton
        {
            idc = 1605;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 6 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "";
            action = "[5] call YOSHI_CO_fnc_handleButton;";
        };

        // Wires
        class RscButton_1400: RscPicture
        {
            idc = 1400;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1401: RscPicture
        {
            idc = 1401;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 2 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1402: RscPicture
        {
            idc = 1402;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 3 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1403: RscPicture
        {
            idc = 1403;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 4 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1404: RscPicture
        {
            idc = 1404;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 5 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1405: RscPicture
        {
            idc = 1405;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 6 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 2)) * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W * WIRE_SCALE;
            h = 8 * GUI_GRID_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };

        // LEDs
        class RscPicture_1200: RscPicture 
        {
            idc = 1200;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 1)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1201: RscPicture 
        {
            idc = 1201;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 2 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 1)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1202: RscPicture 
        {
            idc = 1202;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 3 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 1)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1203: RscPicture 
        {
            idc = 1203;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 4 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 1)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1204: RscPicture 
        {
            idc = 1204;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 5 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 1)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1205: RscPicture 
        {
            idc = 1205;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 6 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 1)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };

        // stars
        class RscPicture_1300: RscPicture 
        {
            idc = 1300;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 10)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1301: RscPicture 
        {
            idc = 1301;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 2 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 10)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1302: RscPicture 
        {
            idc = 1302;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 3 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 10)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1303: RscPicture 
        {
            idc = 1303;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 4 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 10)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1304: RscPicture 
        {
            idc = 1304;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 5 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 10)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };
        class RscPicture_1305: RscPicture 
        {
            idc = 1305;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 6 * WIRE_SCALE)) * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * WIRE_SCALE * 10)) * GUI_GRID_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_W;
            h = WIRE_SCALE * GUI_GRID_H;
        };

        // Ports
        class RscPicture_4500: RscPicture 
        {
            idc = 4500;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class RscPicture_4501: RscPicture 
        {
            idc = 4501;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class RscPicture_4502: RscPicture 
        {
            idc = 4502;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class RscPicture_4503: RscPicture 
        {
            idc = 4503;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class RscPicture_4504: RscPicture 
        {
            idc = 4504;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class RscPicture_4505: RscPicture 
        {
            idc = 4505;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };

        // Batteries
        class RscPicture_4600: RscPicture 
        {
            idc = 4600;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4601: RscPicture 
        {
            idc = 4601;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4602: RscPicture 
        {
            idc = 4602;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4603: RscPicture 
        {
            idc = 4603;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4604: RscPicture 
        {
            idc = 4604;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4605: RscPicture 
        {
            idc = 4605;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4606: RscPicture 
        {
            idc = 4606;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };
        class RscPicture_4607: RscPicture 
        {
            idc = 4607;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE) * GUI_GRID_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_MODULE_HEIGHT;
        };

        // Serial number and indicators
        class RscPicture_4700: RscPicture 
        {
            idc = 4700;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y - SHORT_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class SerialNumber: RscText
        {
            idc = 4701;
            text = ""; //--- ToDo: Localize;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 0.8)) * GUI_GRID_W + GUI_GRID_X;
            y = (1.25 * UNIT_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            colorText[] = {0,0,0,1};
            sizeEx = 2 * GUI_GRID_H;
            shadow=0;
            // colorBackground[] = {0.87,0.87,0.87,1};
        };
        class Indicator: RscText
        {
            idc = 4702;
            text = ""; //--- ToDo: Localize;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 11)) * GUI_GRID_W + GUI_GRID_X;
            y = (1.5 * UNIT_SIZE) * GUI_GRID_H + GUI_GRID_Y;
            w = GUI_SHORT_WIDTH;
            h = GUI_GRID_H;
            colorText[] = {1,1,1,1};
            // colorBackground[] = {0.45,0.11,0.12,1};
        };
    };

    
};