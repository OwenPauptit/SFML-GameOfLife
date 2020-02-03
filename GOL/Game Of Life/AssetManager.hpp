#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace Aesel {
	class AssetManager {
	public:
		AssetManager();

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

	private:
		std::map <std::string, sf::Texture> _textures;
	};
}
