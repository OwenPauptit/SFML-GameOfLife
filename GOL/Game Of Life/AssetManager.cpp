#include "AssetManager.hpp"
#include <SFML/Graphics.hpp>

namespace Aesel {


	AssetManager::AssetManager(){

	}

	void AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;
		if (tex.loadFromFile(fileName)) {
			_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name) {
		return _textures[name];
	}

}