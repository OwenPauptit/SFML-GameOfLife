#pragma once

#include <SFML/Graphics.hpp>

namespace Aesel {
	class InputManager {
	public:
		InputManager();

		bool isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window);
		bool isClick(sf::Mouse::Button button, sf::RenderWindow& window);

	};
}