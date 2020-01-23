#pragma once

#include <SFML/Graphics.hpp>

namespace Aesel {
	class InputManager {
	public:
		InputManager();

		bool isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window);

		sf::Vector2i getMousePosition(sf::RenderWindow& window);
	};
}