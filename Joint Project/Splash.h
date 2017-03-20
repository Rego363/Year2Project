#pragma once
#ifndef SPLASH
#define SPLASH

#include "Game.h"

class Game;

//splash screen class
class Splash
{
public:
	Splash(Game &game);
	~Splash();
	void update();
	void render(sf::RenderWindow & window);
	void load();
	void setStateBack();

private:
	Game *m_game;
	GUI m_gui;
	Button *m_button;

	int m_currentSelect = 0;
	sf::Time m_CumulativeTime;

	sfe::Movie m_animation;
	bool m_play = true;

};

#endif
