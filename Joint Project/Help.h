#pragma once
#ifndef HELPSCREEN
#define HELPSCREEN

#include"GUI.h"
#include"Help.h"
#include"Game.h"

class Game;

class HelpScreen {

public:
	HelpScreen(Game &game);
	void update();
	void draw(sf::RenderWindow &window);
	void goBack();

private:
	Game *m_game;
	GUI m_gui;
	Button* m_backButton;
	Label* m_label;
	int m_selectedItem = 0;
};
#endif // !HELPSCREEN