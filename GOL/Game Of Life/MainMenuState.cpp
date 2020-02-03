#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Aesel {

	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {

	}

	void MainMenuState::Init(){

		_data->assetMGR.LoadTexture("Title", MENU_TITLE_FILEPATH);
		_data->assetMGR.LoadTexture("Random", MENU_RANDOM_FILEPATH);
		_data->assetMGR.LoadTexture("Custom", MENU_CUSTOM_FILEPATH);
		_data->assetMGR.LoadTexture("File", MENU_FILE_FILEPATH);
		_data->assetMGR.LoadTexture("Preset", MENU_PRESET_FILEPATH);
		_data->assetMGR.LoadTexture("Exit", MENU_EXIT_FILEPATH);

		_title.setTexture(_data->assetMGR.GetTexture("Title"));
		_random.setTexture(_data->assetMGR.GetTexture("Random"));
		_custom.setTexture(_data->assetMGR.GetTexture("Custom"));
		_preset.setTexture(_data->assetMGR.GetTexture("Preset"));
		_fromFile.setTexture(_data->assetMGR.GetTexture("File"));
		_exit.setTexture(_data->assetMGR.GetTexture("Exit"));

		_title.setScale(sf::Vector2f(TITLE_SCALE, TITLE_SCALE));
		_random.setScale(sf::Vector2f(OPTIONS_SCALE, OPTIONS_SCALE));
		_preset.setScale(sf::Vector2f(OPTIONS_SCALE, OPTIONS_SCALE));
		_fromFile.setScale(sf::Vector2f(OPTIONS_SCALE, OPTIONS_SCALE));
		_exit.setScale(sf::Vector2f(OPTIONS_SCALE, OPTIONS_SCALE));
		_custom.setScale(sf::Vector2f(OPTIONS_SCALE, OPTIONS_SCALE));

		_title.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - _title.getGlobalBounds().width / 2, _data->window.getSize().y   * 1 / 8));
		_random.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - _random.getGlobalBounds().width / 2, _data->window.getSize().y * 3 / 8));
		_custom.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - _custom.getGlobalBounds().width / 2, _data->window.getSize().y * 4 / 8));
		_preset.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - _preset.getGlobalBounds().width / 2, _data->window.getSize().y * 5 / 8));
		_fromFile.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - _fromFile.getGlobalBounds().width / 2, _data->window.getSize().y * 6 / 8));
		_exit.setPosition(sf::Vector2f(_data->window.getSize().x / 2 - _exit.getGlobalBounds().width / 2, _data->window.getSize().y * 7 / 8));

	}

	void MainMenuState::HandleInput() {

		sf::Event event;

		while (_data->window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}

			if (_data->inputMGR.isSpriteClicked(_random, sf::Mouse::Left, _data->window)) {
				_data->stateMGR.ChangeState(StateRef(new GameState(_data, DEFAULT_GRID_WIDTH, DEFAULT_GRID_HEIGHT, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, time(0),"")));
			}
			else if (_data->inputMGR.isSpriteClicked(_custom, sf::Mouse::Left, _data->window)) {
				int n;
				std::cout << "Enter seed: ";
				std::cin >> n;
				_data->stateMGR.ChangeState(StateRef(new GameState(_data, DEFAULT_GRID_WIDTH, DEFAULT_GRID_HEIGHT, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, n, "")));
			}
			else if (_data->inputMGR.isSpriteClicked(_preset, sf::Mouse::Left, _data->window)) {
				std::string fileName;
				std::cout << "Enter preset name: ";
				std::cin >> fileName;
				fileName = "Resources/Presets/" + fileName + ".txt";
				_data->stateMGR.ChangeState(StateRef(new GameState(_data, DEFAULT_GRID_WIDTH, DEFAULT_GRID_HEIGHT, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, time(0), fileName)));
			}
			else if (_data->inputMGR.isSpriteClicked(_fromFile, sf::Mouse::Left, _data->window)) {
				std::string fileName;
				std::cout << "Enter file name: ";
				std::cin >> fileName;
				_data->stateMGR.ChangeState(StateRef(new GameState(_data, DEFAULT_GRID_WIDTH, DEFAULT_GRID_HEIGHT, DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT, time(0), fileName)));
			}
			else if (_data->inputMGR.isSpriteClicked(_exit, sf::Mouse::Left, _data->window)) {
				_data->window.close();
			}

		}
	}

	void MainMenuState::Update(float dt) {

	}

	void MainMenuState::Draw() {

		_data->window.clear();

		_data->window.draw(_title);
		_data->window.draw(_random);
		_data->window.draw(_custom);
		_data->window.draw(_preset);
		_data->window.draw(_fromFile);
		_data->window.draw(_exit);

		_data->window.display();
	}


}