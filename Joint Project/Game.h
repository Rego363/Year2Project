#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>


#include "MainMenu.h"


#include "OptionsScreen.h"
#include"GarageScreen.h"
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

	
	OptionsScreen* m_optionsScreen;

	GarageScreen* m_garageScreen;
	sf::Font m_font;
	sf::Text m_text;
	MainMenu *m_MainMenu;
	GameState m_currentGameState = GameState::Garage;
	
	
};

#endif
