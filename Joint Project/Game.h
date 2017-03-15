#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <SFML\Graphics\Rect.hpp>
#include "OptionsScreen.h"
#include "playGame.h"
#include "SoundScreen.h"
#include "MainMenu.h"
#include "GarageScreen.h"
#include "DisplayScreen.h"
#include "Player.h"
#include "Help.h"
#include "Liscence.h"
#include "Splash.h"
#include "DifficultyScreen.h"
#include "SteeringScreen.h"
#include "TurboScreen.h"
#include "BrakingScreen.h"
#include "SpeedScreen.h"
#include "AccelerationScreen.h"
#include "Car.h"
#include "XBOX360CONTROLLER.h"
#include "Specs.h"
#include "Liscence.h"
#include "Splash.h"
#include "DifficultyScreen.h"
#include "SteeringScreen.h"
#include "TurboScreen.h"
#include "BrakingScreen.h"
#include "SpeedScreen.h"
#include "AccelerationScreen.h"
#include "changeProfile.h"
#include "ResourceManager.h"
#include "levels.h"
#include "WorldSquares.h"
#include "Ai.h"
#include "EnterNameScreen.h"
#include <SFML\Audio.hpp>

using namespace std;

class SoundScreen;
class DisplayScreen;
class OptionsScreen;
class Liscence;
class Splash;
class MainMenu;
class GarageScreen;
class HelpScreen;
class Player;
class Ai;
class DifficultyScreen;
class SteeringScreen;
class TurboScreen;
class BrakingScreen;
class SpeedScreen;
class AccelerationScreen;
class specs;
class playGame;
class changeProfile;
class worldSquares;
class Levels;
class EnterNameScreen;


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
	Thespecs,
	Acceleration,
	Speed,
	Braking,
	Turbo,
	Steering,
	Racing,
	ChangeP,
	ThewSquares,
	EnterName
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

	string nameDisplay();


	bool isInView(sf::Sprite sprite);

private:
	void processInput();
	void update(sf::Time);
	void render();


	Label* m_currentName;
	sf::Text m_name;

	sf::Font m_font;
	sf::Text m_text;
	


	GameState m_currentGameState = GameState::MapSelect;



	playGame * m_mapSelect;
	
	GameDifficulty m_currentDifficulty = GameDifficulty::Medium;

	OptionsScreen* m_optionsScreen;
	SoundScreen* m_soundScreen;
	DisplayScreen* m_displayScreen;
	GarageScreen* m_garageScreen;
	MainMenu *m_MainMenu;
	HelpScreen *m_helpScreen;
	Player *m_player;
	Ai *m_ai;
	specs *m_specs;
	Liscence *m_Liscence;
	Splash *m_Splash;
	DifficultyScreen *m_diffScreen;
	SteeringScreen *m_steeringScreen;
	TurboScreen *m_turboScreen;
	BrakingScreen *m_brakingScreen;
	SpeedScreen *m_speedScreen;
	AccelerationScreen *m_accelerationScreen;
	changeProfile * m_changeProfile;
	Levels *m_level;
	worldSquares * m_worldSquares;
	EnterNameScreen *m_enterName;

	/*For testing*/
	/**********************/

	Car *m_car;
	Car *m_shagginWaggin;
	sf::View m_view;
	sf::View m_view2;
	sf::Texture m_startCar;
	sf::Vector2f m_startPos;

	std::vector<sf::CircleShape> m_track;
	sf::Texture m_ground;
	sf::Sprite m_groundSprite[70];
	Xbox360Controller m_xbox;


	/*For testing*/
	/**********************/


	/**********************/

	LevelData m_currentLevel;
	LevelLoader m_levelLoader;
	bool hasName=false;
	sf::SoundBuffer m_buffer;
	sf::Sound music;



	/******************************/
	sf::Image image;
	sf::Color color;
	sf::Sprite testSprite;
	sf::Color color2;
	/*******************************/

};

#endif
