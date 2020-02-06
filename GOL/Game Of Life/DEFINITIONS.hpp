#pragma once


#define DEFAULT_GRID_WIDTH 220
#define DEFAULT_GRID_HEIGHT 220
#define DEFAULT_CELL_WIDTH 3.0f
#define DEFAULT_CELL_HEIGHT 3.0f

#define SCREEN_WIDTH DEFAULT_GRID_WIDTH * DEFAULT_CELL_WIDTH
#define SCREEN_HEIGHT DEFAULT_GRID_HEIGHT * DEFAULT_CELL_HEIGHT

#define FRAME_RATE 12.0f

#define MENU_TITLE_FILEPATH "Resources/Images/Main Menu/title.png"
#define MENU_RANDOM_FILEPATH "Resources/Images/Main Menu/randomseed.png"
#define MENU_CUSTOM_FILEPATH "Resources/Images/Main Menu/customseed.png"
#define MENU_PRESET_FILEPATH "Resources/Images/Main Menu/preset.png"
#define MENU_FILE_FILEPATH "Resources/Images/Main Menu/fromfile.png"
#define MENU_EXIT_FILEPATH "Resources/Images/Main Menu/exit.png"
#define ENTER_SEED_FILEPATH "Resources/Images/Main Menu/enterSeed.png"
#define ENTER_FILEPATH_FILEPATH "Resources/Images/Main Menu/enterFilePath.png"
#define TITLE_SCALE 0.75f
#define OPTIONS_SCALE 0.7f


//#define GOSPER_GLIDER_GUN_FILEPATH "Resources/Presets/GosperGliderGun.txt"
//#define THEA_FILEPATH "Resources/Presets/Thea.txt"
//#define CALLAHAN_GROWTH_FILEPATH "Resources/Presets/PaulCallahan'sInfiniteGrowth.txt"
#define MAX_FILEPATH "Resources/Presets/Max.txt"
#define AK94_FILEPATH "Resources/Presets/Ak-94.txt"
#define TEST_FILEPATH "Resources/Presets/Test.txt"
#define GLIDERLESS_GUN_FILEPATH "Resources/Presets/GliderlessGun.txt"
#define DOUBLE_GLIDERLESS_GUN_FILEPATH "Resources/Presets/DoubleGliderlessGun.txt"
#define SIDECAR_GUN_FILEPATH "Resources/Presets/SideCarGun.txt"


enum CellState {
	eAlive,
	eDead
};