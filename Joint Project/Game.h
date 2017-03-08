#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#include "OptionsScreen.h"
#include "playGame.h"
#include "SoundScreen.h"
#include "MainMenu.h"
#include"GarageScreen.h"

using namespace std;

class SoundScreen;


enum GameState {
	TheLicense,
	TheSplash,
	TheMenu,
	TheOptions,
	Playing,
	Display,
	Difficulty,
	Sound,
	Garage,
	MapSelect
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
	void changeGameState(GameState gameState);

private:
	void processInput();
	void update(sf::Time);
	void render();

	sf::RenderWindow m_window;

	
	OptionsScreen* m_optionsScreen;
	playGame * m_mapSelect;
	sf::Font m_font;
	sf::Text m_text;
	GameState m_currentGameState = GameState::Sound;

	SoundScreen* m_soundScreen;
	GarageScreen* m_garageScreen;
	MainMenu *m_MainMenu;
	
	
};

#endif
