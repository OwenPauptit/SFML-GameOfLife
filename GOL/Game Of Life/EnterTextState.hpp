#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "State.hpp"
#include "Game.hpp"

namespace Aesel {

	class EnterTextState : public State {

		EnterTextState(GameDataRef data, bool isFile, bool isSeed);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw();

	private:

		GameDataRef _data;

		sf::Sprite _title;
		sf::Text _inputText;
		std::string _inputString;


	};
}