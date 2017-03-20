#pragma once

#ifndef CREDITS
#define CREDITS

#include "Game.h"

class Game;

//credits class
class Credits
{
public:
	Credits(Game &game, LevelData &level);
	~Credits();
	void update();
	void render(sf::RenderWindow & window);
	void load();
private:
	Game *m_game;
	LevelData *m_currentLevel;
	sfe::Movie m_credits;
	bool m_play = true;
};

#endif