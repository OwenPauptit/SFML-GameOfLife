#pragma once


#define DEFAULT_GRID_WIDTH 100
#define DEFAULT_GRID_HEIGHT 100
#define DEFAULT_CELL_WIDTH 5.0f
#define DEFAULT_CELL_HEIGHT 5.0f

#define SCREEN_WIDTH DEFAULT_GRID_WIDTH * DEFAULT_CELL_WIDTH
#define SCREEN_HEIGHT DEFAULT_GRID_HEIGHT * DEFAULT_CELL_HEIGHT

#define FRAME_RATE 12.0f

#define GOSPER_GLIDER_GUN_FILEPATH "Resources/Presets/GosperGliderGun.txt"

enum CellState {
	eAlive,
	eDead
};