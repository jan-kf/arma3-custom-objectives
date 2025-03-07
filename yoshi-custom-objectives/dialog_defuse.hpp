#define GUI_GRID_X safeZoneX
#define GUI_GRID_Y safeZoneY
#define GUI_MODULE_1_X 11
#define GUI_MODULE_1_Y 3

#define GUI_GRID_STATIC_W (safeZoneW / 40)
#define GUI_GRID_STATIC_H (safeZoneH / 25) 

#define GUI_MODULE_STATIC_WIDTH 16 * GUI_GRID_STATIC_W
#define GUI_MODULE_STATIC_HEIGHT 16 * GUI_GRID_STATIC_H
#define GUI_SHORT_STATIC_WIDTH 2 * GUI_GRID_STATIC_W
#define GUI_SHORT_STATIC_HEIGHT 2 * GUI_GRID_STATIC_H

#define SHORT_SIZE_STATIC 2
#define LONG_SIZE_STATIC 16


#define UNIT_SIZE 0.5
#define GUI_GRID_W ((safeZoneW / 40) * UNIT_SIZE)
#define GUI_GRID_H ((safeZoneH / 25) * UNIT_SIZE)
#define SHORT_SIZE 2 * UNIT_SIZE
#define LONG_SIZE 16 * UNIT_SIZE
#define GUI_MODULE_WIDTH LONG_SIZE_STATIC * GUI_GRID_STATIC_W * UNIT_SIZE
#define GUI_MODULE_HEIGHT LONG_SIZE_STATIC * GUI_GRID_STATIC_H * UNIT_SIZE
#define GUI_SHORT_WIDTH SHORT_SIZE_STATIC * GUI_GRID_STATIC_W * UNIT_SIZE
#define GUI_SHORT_HEIGHT SHORT_SIZE_STATIC * GUI_GRID_STATIC_H * UNIT_SIZE
#define WIRE_SCALE 1.375 * UNIT_SIZE




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
        class BackgroundModule00: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_MODULE_HEIGHT;
            text = "\yoshi-custom-objectives\UI\complexWiresModuleBackground.paa";
        };
        class BackgroundModule01: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_MODULE_HEIGHT;
            text = "\yoshi-custom-objectives\UI\complexWiresModuleBackground.paa";
        };
        class BackgroundModule10: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = GUI_MODULE_WIDTH;
            h = GUI_MODULE_HEIGHT;
            text = "\yoshi-custom-objectives\UI\complexWiresModuleBackground.paa";
        };
        class BackgroundModule11: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = GUI_MODULE_WIDTH;
            h = GUI_MODULE_HEIGHT;
            text = "\yoshi-custom-objectives\UI\complexWiresModuleBackground.paa";
        };
        
        class Ports: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
            text = "\yoshi-custom-objectives\UI\portPanel.paa";
        };
        class Batteries: RscPicture {
            idc = -1;
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
            text = "\yoshi-custom-objectives\UI\batteryPanel.paa";
        };
        class SerialAndIndicator: RscPicture {
            idc = -1;
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y - SHORT_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
            text = "\yoshi-custom-objectives\UI\serialIndicatorPanel.paa";
        };
    };

    class controls
    {

        class StatusIndicator00: RscPicture
        {
            idc = 1000;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 12.5)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * 0.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1.5 * GUI_SHORT_WIDTH;
            h = 1.5 * GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\moduleDoneLightOff.paa";
        };

        class StatusIndicator01: RscPicture
        {
            idc = 1001;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 12.5)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * 0.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1.5 * GUI_SHORT_WIDTH;
            h = 1.5 * GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\moduleDoneLightOff.paa";
        };

        class StatusIndicator10: RscPicture
        {
            idc = 1002;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 12.5)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * 0.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 1.5 * GUI_SHORT_WIDTH;
            h = 1.5 * GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\moduleDoneLightOff.paa";
        };

        class StatusIndicator11: RscPicture
        {
            idc = 1003;
            x = (GUI_MODULE_1_X + (UNIT_SIZE * 12.5)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + (UNIT_SIZE * 0.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 1.5 * GUI_SHORT_WIDTH;
            h = 1.5 * GUI_SHORT_HEIGHT;
            text = "\yoshi-custom-objectives\UI\moduleDoneLightOff.paa";
        };

        class RscButton_1600: WireButton
        {
            idc = 1600;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[0] call YOSHI_CO_fnc_handleCW_Button;";
        };
        class RscButton_1601: WireButton
        {
            idc = 1601;
            x = (GUI_MODULE_1_X + ( 2 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[1] call YOSHI_CO_fnc_handleCW_Button;";
        };
        class RscButton_1602: WireButton
        {
            idc = 1602;
            x = (GUI_MODULE_1_X + ( 3 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[2] call YOSHI_CO_fnc_handleCW_Button;";
        };
        class RscButton_1603: WireButton
        {
            idc = 1603;
            x = (GUI_MODULE_1_X + ( 4 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[3] call YOSHI_CO_fnc_handleCW_Button;";
        };
        class RscButton_1604: WireButton
        {
            idc = 1604;
            x = (GUI_MODULE_1_X + ( 5 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[4] call YOSHI_CO_fnc_handleCW_Button;";
        };
        class RscButton_1605: WireButton
        {
            idc = 1605;
            x = (GUI_MODULE_1_X + ( 6 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[5] call YOSHI_CO_fnc_handleCW_Button;";
        };

        // Wires
        class RscButton_1400: RscPicture
        {
            idc = 1400;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1401: RscPicture
        {
            idc = 1401;
            x = (GUI_MODULE_1_X + ( 2 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1402: RscPicture
        {
            idc = 1402;
            x = (GUI_MODULE_1_X + ( 3 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1403: RscPicture
        {
            idc = 1403;
            x = (GUI_MODULE_1_X + ( 4 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1404: RscPicture
        {
            idc = 1404;
            x = (GUI_MODULE_1_X + ( 5 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1405: RscPicture
        {
            idc = 1405;
            x = (GUI_MODULE_1_X + ( 6 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 8 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };

        // LEDs
        class RscPicture_1200: RscPicture 
        {
            idc = 1200;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 1)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1201: RscPicture 
        {
            idc = 1201;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + ( 2 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 1)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1202: RscPicture 
        {
            idc = 1202;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + ( 3 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 1)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1203: RscPicture 
        {
            idc = 1203;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + ( 4 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 1)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1204: RscPicture 
        {
            idc = 1204;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + ( 5 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 1)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1205: RscPicture 
        {
            idc = 1205;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = (GUI_MODULE_1_X + ( 6 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 1)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };

        // stars
        class RscPicture_1300: RscPicture 
        {
            idc = 1300;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1301: RscPicture 
        {
            idc = 1301;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + ( 2 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1302: RscPicture 
        {
            idc = 1302;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + ( 3 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1303: RscPicture 
        {
            idc = 1303;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + ( 4 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1304: RscPicture 
        {
            idc = 1304;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + ( 5 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };
        class RscPicture_1305: RscPicture 
        {
            idc = 1305;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = (GUI_MODULE_1_X + ( 6 * WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10)) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = WIRE_SCALE * GUI_GRID_STATIC_W;
            h = WIRE_SCALE * GUI_GRID_STATIC_H;
        };

        // Ports
        class RscPicture_4500: RscPicture 
        {
            idc = 4500;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
        };
        class RscPicture_4501: RscPicture 
        {
            idc = 4501;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
        };
        class RscPicture_4502: RscPicture 
        {
            idc = 4502;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
        };
        class RscPicture_4503: RscPicture 
        {
            idc = 4503;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
        };
        class RscPicture_4504: RscPicture 
        {
            idc = 4504;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
        };
        class RscPicture_4505: RscPicture 
        {
            idc = 4505;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y + LONG_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_STATIC_WIDTH;
            h = GUI_SHORT_STATIC_HEIGHT;
        };

        // Batteries
        class RscPicture_4600: RscPicture 
        {
            idc = 4600;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4601: RscPicture 
        {
            idc = 4601;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4602: RscPicture 
        {
            idc = 4602;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4603: RscPicture 
        {
            idc = 4603;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4604: RscPicture 
        {
            idc = 4604;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4605: RscPicture 
        {
            idc = 4605;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4606: RscPicture 
        {
            idc = 4606;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };
        class RscPicture_4607: RscPicture 
        {
            idc = 4607;
            text = "";
            x = (GUI_MODULE_1_X + LONG_SIZE_STATIC) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = GUI_MODULE_1_Y * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_MODULE_STATIC_HEIGHT;
        };

        // Serial number and indicators
        class RscPicture_4700: RscPicture 
        {
            idc = 4700;
            text = "";
            x = GUI_MODULE_1_X * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (GUI_MODULE_1_Y - SHORT_SIZE_STATIC) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_MODULE_WIDTH;
            h = GUI_SHORT_HEIGHT;
        };
        class SerialNumber: RscText
        {
            idc = 4701;
            text = ""; //--- ToDo: Localize;
            x = (GUI_MODULE_1_X + (0.8)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (1.25) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_STATIC_W;
            h = 1.5 * GUI_GRID_STATIC_H;
            colorText[] = {0,0,0,1};
            sizeEx = 2 * GUI_GRID_STATIC_H;
            shadow=0;
            // colorBackground[] = {0.87,0.87,0.87,1};
        };
        class Indicator: RscText
        {
            idc = 4702;
            text = ""; //--- ToDo: Localize;
            x = (GUI_MODULE_1_X + (11)) * GUI_GRID_STATIC_W + GUI_GRID_X;
            y = (1.5) * GUI_GRID_STATIC_H + GUI_GRID_Y;
            w = GUI_SHORT_STATIC_WIDTH;
            h = GUI_GRID_STATIC_H;
            colorText[] = {1,1,1,1};
            // colorBackground[] = {0.45,0.11,0.12,1};
        };

        // simple wires
        
        class RscButton_4600: WireButton
        {
            idc = 4600;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 2)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[0] call YOSHI_CO_fnc_handleSW_Button;";
        };
        class RscButton_4601: WireButton
        {
            idc = 4601;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 3.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[1] call YOSHI_CO_fnc_handleSW_Button;";
        };
        class RscButton_4602: WireButton
        {
            idc = 4602;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[2] call YOSHI_CO_fnc_handleSW_Button;";
        };
        class RscButton_4603: WireButton
        {
            idc = 4603;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 6.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[3] call YOSHI_CO_fnc_handleSW_Button;";
        };
        class RscButton_4604: WireButton
        {
            idc = 4604;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 8)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[4] call YOSHI_CO_fnc_handleSW_Button;";
        };
        class RscButton_4605: WireButton
        {
            idc = 4605;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 9.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "";
            action = "[5] call YOSHI_CO_fnc_handleSW_Button;";
        };

        // Wires
        class RscButton_4400: RscPicture
        {
            idc = 4400;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 3)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone.paa";
        };
        class RscButton_4401: RscPicture
        {
            idc = 4401;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 4.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone.paa";
        };
        class RscButton_4402: RscPicture
        {
            idc = 4402;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 6)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone.paa";
        };
        class RscButton_4403: RscPicture
        {
            idc = 4403;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 7.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone.paa";
        };
        class RscButton_4404: RscPicture
        {
            idc = 4404;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 9)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone.paa";
        };
        class RscButton_4405: RscPicture
        {
            idc = 4405;
            x = (GUI_MODULE_1_X + ( WIRE_SCALE)) * GUI_GRID_STATIC_W + GUI_GRID_X + GUI_MODULE_WIDTH;
            y = (GUI_MODULE_1_Y + ( WIRE_SCALE * 10.5)) * GUI_GRID_STATIC_H + GUI_GRID_Y + GUI_MODULE_HEIGHT;
            w = 8 * GUI_GRID_STATIC_W * WIRE_SCALE;
            h = 1 * GUI_GRID_STATIC_H * WIRE_SCALE;
            text = "\yoshi-custom-objectives\UI\wireNone.paa";
        };
    };

    
};