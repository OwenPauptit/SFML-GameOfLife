#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <cstdlib>
#include <ctime>

namespace Aesel {

	GameState::GameState(GameDataRef data, int gridWidth, int gridHeight, int cellWidth, int cellHeight) :_data(data), _gridWidth(gridWidth), _gridHeight(gridHeight), _cellWidth(cellWidth), _cellHeight(cellHeight){
		
	}

	void GameState::Init() {
		srand(time(0));
		int x, y;
		for (int r = 0; r < _gridWidth + 2; r++) {

			y = _data->window.getSize().y / _gridHeight * r - _cellHeight;
			_row.clear();
			for (int c = 0; c < _gridHeight + 2; c++) {
				x = _data->window.getSize().x / _gridWidth * c - _cellWidth;
				_tempCell = new Cell(_data, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, x, y, RandomState());
				_row.push_back(std::move(_tempCell));
			}
			_cells.push_back(_row);
		}
		for (int r = 0; r < _gridWidth + 2; r++) {

			y = _data->window.getSize().y / _gridHeight * r - _cellHeight;
			_row.clear();
			for (int c = 0; c < _gridHeight + 2; c++) {
				x = _data->window.getSize().x / _gridWidth * c - _cellWidth;
				_tempCell = new Cell(_data, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, x, y, CellState::eDead);
				_row.push_back(std::move(_tempCell));
			}
			_cells2.push_back(_row);
		}

	}

	CellState GameState::RandomState() {
		int n = rand() % 2;
		if (n == 1) {
			return CellState::eAlive;
		}
		else {
			return CellState::eDead;
		}
	}

	void GameState::HandleInput() {

		sf::Event event;

		while (_data->window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}

			if (_data->inputMGR.isClick(sf::Mouse::Left, _data->window)) {
				_proceed = true;
			}
			else {
				_proceed = false;
			}
		}

		
	}

	void GameState::Update(float dt) {
		if (_proceed) {

			_proceed = false;
			int numAlive;
			for (int y = 1; y < _gridHeight + 1; y++) {
				for (int x = 1; x < _gridWidth + 1; x++) {
					numAlive = 0;

					// Row above
					if (_cells[y - 1][x - 1]->getState() == CellState::eAlive) {
						numAlive++;
					}
					if (_cells[y - 1][x]->getState() == CellState::eAlive) {
						numAlive++;
					}
					if (_cells[y - 1][x + 1]->getState() == CellState::eAlive) {
						numAlive++;
					}
					// Same Row
					if (_cells[y][x - 1]->getState() == CellState::eAlive) {
						numAlive++;
					}
					if (_cells[y][x + 1]->getState() == CellState::eAlive) {
						numAlive++;
					}
					// Row below
					if (_cells[y + 1][x - 1]->getState() == CellState::eAlive) {
						numAlive++;
					}
					if (_cells[y + 1][x]->getState() == CellState::eAlive) {
						numAlive++;
					}
					if (_cells[y + 1][x + 1]->getState() == CellState::eAlive) {
						numAlive++;
					}

					if (_cells[y][x]->getState() == CellState::eAlive) {
						if (numAlive < 2 || numAlive > 3) {
							_cells2[y][x]->Die();
						}
						else {
							_cells2[y][x]->Birth();
						}
					}
					else {
						if (numAlive == 3) {
							_cells2[y][x]->Birth();
						}
						else {
							_cells2[y][x]->Die();
						}
					}
				}
			}

			for (int y = 0; y < _gridHeight + 2; y++) {
				for (int x = 0; x < _gridWidth + 2; x++) {
					if (_cells2[y][x]->getState() == CellState::eAlive){
						_cells[y][x]->Birth();
					}
					else {
						_cells[y][x]->Die();
					}
				}
			}
		}
	}

	void GameState::Draw() {
		_data->window.clear();
		for (int y = 1; y < _gridHeight + 1; y++) {
			for (int x = 1; x < _gridWidth + 1; x++) {
				_cells[y][x]->Draw();
			}
		}
		_data->window.display();
	}
}