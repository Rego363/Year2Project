#pragma once
#ifndef LISCENCE
#define LISCENCE

#include "Game.h"

class Game;

//class for Licence sceen
class Liscence
{
public:
	Liscence(Game &game);
	~Liscence();
	void update(sf::Time dt);
	void render(sf::RenderWindow & window);

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;

	sf::Time m_CumulativeTime;

};

#endif