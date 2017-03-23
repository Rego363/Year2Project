#pragma once

#ifndef DISPLAYSCREEN
#define DISPLAYSCREEN

#include "Game.h"

class Game;

class DisplayScreen
{
public:
	DisplayScreen(Game &game);
	~DisplayScreen();
	void update();
	void render(sf::RenderWindow & window);

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;

	CheckBox *m_animeOn;

	Button *m_backButton;

	float m_speed;
	int m_currentSelect;
	void setStateBack();
	void animationOn();
};

#endif