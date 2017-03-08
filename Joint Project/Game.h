#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#include "OptionsScreen.h"
<<<<<<< HEAD
#include "playGame.h"
=======
#include "SoundScreen.h"
#include "MainMenu.h"
#include"GarageScreen.h"
>>>>>>> f2e16c175919c11297e855f498f39340de55a8d4

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
<<<<<<< HEAD
	playGame * m_mapSelect;
	sf::Font m_font;
	sf::Text m_text;
	GameState m_currentGameState = GameState::MapSelect;

=======
	SoundScreen* m_soundScreen;
	GarageScreen* m_garageScreen;
	sf::Font m_font;
	sf::Text m_text;
	MainMenu *m_MainMenu;
	GameState m_currentGameState = GameState::Garage;
	
	
>>>>>>> f2e16c175919c11297e855f498f39340de55a8d4
};

#endif
