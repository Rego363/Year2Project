#pragma once
#ifndef LEVELS
#define LEVELS

#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "Player.h"
#include "Ai.h"
#include "LevelLoad.h"

class Player;
class Game;
class Ai;

//class to draw and update the game depending on what map was chosen
class Levels
{
public:
	Levels(LevelData &level, Player &player,  Ai &ai, Ai &aiTwo, Ai &aiThree,  Game &game);
	~Levels();

	void update(float dt, sf::View &view);
	void render(sf::RenderWindow & window);
	void loadFont();
	sf::Clock m_startRace;
	int m_maxLaps;
	void setStateBack();
	std::string getBestLapTime();
	void resetLevel();
private:

	void startTimes();
	void setupTexts();

	Ai *m_ai;
	Ai *m_aiTwo;
	Ai *m_aiThree;
	LevelData *m_currentLevel;
	Player *m_currentPlayer;
	
	sf::Font m_font;
	Game *m_game;

	sf::Clock m_raceTime;
	bool m_raceStarted;
	bool m_countDown;
	sf::Text m_countDownNumber;
	sf::Text m_currentLapTime;
	sf::Text m_currentSpeed;
	sf::Text m_bestLap;
	sf::Text m_lastLap;
	sf::Text m_Lap;;
	sf::Text m_turbos;
	sf::Text easterEgg;
	float tempTime = 0;
	int currentlap = 1;
	GUI m_gui;
	int m_currentSelect = 0;
	Button *m_credits;
	bool game_on;

	sf::RectangleShape m_startLine;
	

};

#endif
