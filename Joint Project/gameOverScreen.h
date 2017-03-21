#pragma once
#ifndef GAMEOVERSCREEN
#define GAMEOVERSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

class GameOverScreen {
public:
	GameOverScreen(Game &game);
	void draw(sf::RenderWindow &window);
	void update();
	void goToGame();

private:

	int m_selectedItem = 0;
	Label *m_label;
	Label *m_moneyEarned;
	Label *m_time;
	Label *m_placement;
	Button *m_button;
	static const int MAX_ITEMS = 1;
	Widget* m_widgets[MAX_ITEMS];
	Game *m_game;
	GUI m_gui;
};
#endif