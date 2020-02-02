#include "Game.hpp"
#include "GameState.hpp"
#include <string>

namespace Aesel {

	Game::Game(int width, int height, std::string title) {

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

		_data->stateMGR.ChangeState(StateRef ( new GameState(_data, DEFAULT_GRID_WIDTH, DEFAULT_GRID_HEIGHT, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, time(0),GOSPER_GLIDER_GUN_FILEPATH)));

		this->Run();
	}

	void Game::Run() {

		float newTime, frameTime;

		float currentTime = _clock.getElapsedTime().asSeconds();

		float accumulator = 0.0f;


		while (_data->window.isOpen()) {

			_data->stateMGR.ProcessChanges();

			newTime = _clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			// while more time has passed since the last update than the length of one frame, handle inputs of the state, and updates the state
			while (accumulator >= dt) {

				_data->stateMGR.GetActiveState()->HandleInput();

				_data->stateMGR.GetActiveState()->Update(dt);

				accumulator -= dt;

			}

			this->_data->stateMGR.GetActiveState()->Draw();

		}
	}
}