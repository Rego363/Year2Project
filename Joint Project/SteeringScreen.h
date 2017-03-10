#pragma once
#ifndef STEERINGSCREEN
#define STEERINGSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

class SteeringScreen {
public:
	SteeringScreen(Game &game);
	void draw(sf::RenderWindow &window);
	void update();

	void goToGarage();
private:

	Label *m_label;
	static const int MAX_ITEMS = 4;
	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem = 0;
	GUI m_gui;
	Game *m_game;
};
#endif