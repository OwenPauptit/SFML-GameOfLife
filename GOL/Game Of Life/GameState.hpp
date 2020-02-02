#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "State.hpp"
#include "Game.hpp"
#include "Cell.hpp"

namespace Aesel {
	class GameState : public State{

	public:
		GameState(GameDataRef data, int gridWidth, int gridHeight, int cellWidth, int cellHeight, int seed, std::string fileName);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:
		GameDataRef _data;

		Cell* _tempCell;
		std::vector<Cell*> _row;
		std::vector<std::vector<Cell*>> _cells;
		std::vector<std::vector<Cell*>> _cells2;

		int _gridWidth, _gridHeight, _cellWidth, _cellHeight;
		int _seed;
		bool _proceed;
		std::string _fileName;

		CellState RandomState();
		CellState IntToState(int n);
	};
}