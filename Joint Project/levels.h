#pragma once
#ifndef LEVELS
#define LEVELS

#include "ResourceManager.h"
#include "Player.h"
#include "WorldSquares.h"

class Player;
class worldSquares;

class Levels
{
public:
	Levels(LevelData &level, Player &player, worldSquares &squares);
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

};

#endif
