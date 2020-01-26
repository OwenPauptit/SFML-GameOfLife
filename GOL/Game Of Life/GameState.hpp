#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.hpp"
#include "Game.hpp"
#include "Cell.hpp"

namespace Aesel {
	class GameState : public State{

	public:
		GameState(GameDataRef data, int gridWidth, int gridHeight, int cellWidth, int cellHeight);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:
		GameDataRef _data;
		std::vector<Cell*> _row;
		std::vector<std::vector<Cell*>> _cells;
		std::vector<std::vector<Cell*>> _cells2;
		int _gridWidth, _gridHeight, _cellWidth, _cellHeight;
		Cell* _tempCell;
		bool _proceed;
		CellState RandomState();
	};
}