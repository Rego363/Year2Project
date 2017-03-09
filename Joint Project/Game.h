#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#include "OptionsScreen.h"
#include "playGame.h"
#include "SoundScreen.h"
#include "MainMenu.h"
#include "GarageScreen.h"
#include "DisplayScreen.h"
#include"Help.h"
#include"DifficultyScreen.h"
#include"SteeringScreen.h"
#include"TurboScreen.h"
#include"BrakingScreen.h"
#include"SpeedScreen.h"
#include"AccelerationScreen.h"

using namespace std;

class SoundScreen;
class DisplayScreen;
class OptionsScreen;

class MainMenu;
class GarageScreen;
class HelpScreen;
class DifficultyScreen;

class SteeringScreen;
class TurboScreen;
class BrakingScreen;
class SpeedScreen;
class AccelerationScreen;

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
	Help,

	Acceleration,
	Speed,
	Braking,
	Turbo,
	Steering
};

enum GameDifficulty {
	Easy,
	Medium,
	Hard
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
	void changeGameDifficulty(GameDifficulty gameDiff);
	sf::RenderWindow m_window;
private:
	void processInput();
	void update(sf::Time);
	void render();

	
	sf::Font m_font;
	sf::Text m_text;
	GameState m_currentGameState = GameState::TheMenu;
	GameDifficulty m_currentDifficulty = GameDifficulty::Medium;

	playGame * m_mapSelect;
	OptionsScreen* m_optionsScreen;
	SoundScreen* m_soundScreen;
	DisplayScreen* m_displayScreen;
	GarageScreen* m_garageScreen;
	MainMenu *m_MainMenu;
	HelpScreen *m_helpScreen;
	DifficultyScreen *m_diffScreen;

	SteeringScreen *m_steeringScreen;
	TurboScreen *m_turboScreen;
	BrakingScreen *m_brakingScreen;
	SpeedScreen *m_speedScreen;
	AccelerationScreen *m_accelerationScreen;
	
};

#endif
