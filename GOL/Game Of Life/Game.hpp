#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "StateManager.hpp"
#include "InputManager.hpp"
#include "DEFINITIONS.hpp"

namespace Aesel {
	
	struct GameData {
		InputManager inputMGR;
		StateManager stateMGR;
		sf::RenderWindow window;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
	public:
		Game(int width, int height, std::string title);

	private:
		const float dt = 1.0f / FRAME_RATE;

		sf::Clock _clock;

		GameDataRef _data = std::make_shared <GameData>();

		void Run();
	};
}