#include "Game.hpp"

namespace Aesel {

	Game::Game(int width, int height, std::string title) {

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

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