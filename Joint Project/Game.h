#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#include "Controller.h"
#include "OptionsScreen.h"

using namespace std;



enum GameState {
	TheLicense,
	TheSplash,
	TheMenu,
	TheOptions,
	Playing,
	Display,
	Difficulty,
	Sound,
	Garage
};


/// <summary>
/// Game class
/// </summary>
class Game
{
public:

	Game();
	void init();
	void run();

private:
	void processInput();
	void update(sf::Time);
	void render();
	void changeGameState(GameState gameState);

	sf::RenderWindow m_window;

	X360Controller controller;
	OptionsScreen* m_optionsScreen;
	sf::Font m_font;
	sf::Text m_text;
	GameState m_currentGameState = GameState::TheOptions;

};

#endif
