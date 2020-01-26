#include "Cell.hpp"

namespace Aesel {

	Cell::Cell(GameDataRef data, int width, int height, int x, int y, CellState state) :_data(data), _state(state) {
		_rect.setSize(sf::Vector2f(width, height));
		_rect.setPosition(sf::Vector2f(x, y));

		switch (_state) {

		case CellState::eAlive:
			_rect.setFillColor(sf::Color::White);
			break;

		case CellState::eDead:
			_rect.setFillColor(sf::Color::Black);
			break;

		default:
			break;
		}
	}

	void Cell::Birth() {
		_state = CellState::eAlive;
		_rect.setFillColor(sf::Color::White);
	}

	void Cell::Die() {
		_state = CellState::eDead;
		_rect.setFillColor(sf::Color::Black);
	}

	void Cell::Draw() {
		_data->window.draw(_rect);
	}

	CellState Cell::getState() {
		return _state;
	}
}