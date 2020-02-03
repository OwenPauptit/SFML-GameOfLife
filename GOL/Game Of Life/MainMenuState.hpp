#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Aesel {
	class MainMenuState : public State {
	public:
		MainMenuState(GameDataRef data);


		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:

		GameDataRef _data;

		sf::Sprite _title;
		sf::Sprite _random;
		sf::Sprite _custom;
		sf::Sprite _preset;
		sf::Sprite _fromFile;
		sf::Sprite _exit;

		sf::RectangleShape _selectRect;
	};
}