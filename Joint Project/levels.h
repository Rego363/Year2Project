#pragma once
#ifndef LEVELS
#define LEVELS

#include "ResourceManager.h"
#include "Player.h"
#include "WorldSquares.h"

class Player;
class worldSquares;
class Game;

//class to draw and update the game depending on what map was chosen
class Levels
{
public:
	Levels(LevelData &level, Player &player, worldSquares &squares, Game &game);
	~Levels();

	void update(float dt, sf::View &view);
	void render(sf::RenderWindow & window);
	void loadImages();
	void loadFont();
private:
	LevelData *m_currentLevel;
	Player *m_currentPlayer;
	worldSquares *m_squares;
	sf::Texture m_lambo;
	sf::Font m_Font;
	Game *m_game;

	sf::Clock m_startRace;
	sf::Clock m_raceTime;
	bool m_raceStarted = false;
	bool m_countDown = true;
	sf::Text m_countDownNumber;

};

#endif
