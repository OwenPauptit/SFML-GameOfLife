#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Aesel {
	class Cell {
	public:

		Cell(GameDataRef data, int width, int height, int x, int y, CellState state);

		void Die();
		void Birth();

		void Draw();

		CellState getState();

	private:

		CellState _state;
		sf::RectangleShape _rect;
		GameDataRef _data;

	};
}