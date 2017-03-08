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
#include"Help.h"
using namespace std;

class SoundScreen;
class MainMenu;
class GarageScreen;
class HelpScreen;

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
	MapSelect,
	Help
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
	sf::RenderWindow m_window;
private:
	void processInput();
	void update(sf::Time);
	void render();

	
	OptionsScreen* m_optionsScreen;
	playGame * m_mapSelect;
	sf::Font m_font;
	sf::Text m_text;
	GameState m_currentGameState = GameState::TheMenu;

	SoundScreen* m_soundScreen;
	GarageScreen* m_garageScreen;
	MainMenu *m_MainMenu;
	HelpScreen *m_helpScreen;
	
};

#endif
