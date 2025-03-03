#include "dialog_defuse.hpp"

class CfgPatches {
    class CustomObjectives {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {};
        author = "Yoshi";
    };
};

class CfgFactionClasses {
    class NO_CATEGORY;
    class Puzzle_Category: NO_CATEGORY {
        displayName = "Yoshi's Custom Objectives"; // Name displayed in Eden Editor
        priority = 2; // Position of the category in the list
        side = 7; // Logic
    };
};

class CfgFunctions {
    class YOSHI_CO {
        class Functions {
            file = "\yoshi-custom-objectives\Functions";
            class defuseModule { 
                description = "Function to defuse the bomb"; 
            };
            class handleButton { 
                description = "Function to handle button"; 
            };
			class openGUI { 
				description = "Function to open the GUI"; 
			};
			class setupButtons {
				description = "Function to setup buttons";
			};
			class generateComplexWiresPreset {
				description = "Function to generate a complex wires preset";
			};
            class generateBombExtras {
                description = "Function to generate bomb extras";
            };
            class checkComplexWiresSolution {
                description = "Function to check the complex wires solution";
            };
            class helpers {
                preInit = 1;
            };
        };
	};
};

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase
        {
            class Edit;
            class Units;
            class Combo;
            class Checkbox;
        };
        class ModuleDescription;
    };

 	class CustomObjectives_CustomBombDefusing: Module_F {
        author = "Yoshi";
        category = "Puzzle_Category";
        displayName = "Custom Bomb Defuse Objective";
        icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\destroy_ca.paa"
        function = "YOSHI_CO_fnc_defuseModule";
        functionPriority = 1; // Execution priority, lower numbers are executed first
        scope = 2; // Editor visibility. 2 is for normal use.
        isGlobal = 0; // Effect is local (0 for local only, 1 for global, 2 for persistent)
        isTriggerActivated = 0;
        isDisposable = 0;

		// class Attributes: AttributesBase {
        //     class ModuleDescription: ModuleDescription{}; // Module description should be shown last
        // };

        class ModuleDescription: ModuleDescription {
            description[] = {
                "Adds a defuse ACE interact action to synchronized objects."
            };
            sync[] = {}; 
        };
    };
};