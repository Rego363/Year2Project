#pragma once
#ifndef HELPSCREEN
#define HELPSCREEN

#include"GUI.h"
#include"Help.h"
#include"Game.h"

class Game;

//this is the screen where additional info is displayed
class HelpScreen {

public:
	HelpScreen(Game &game); //constructor
	void update(); //update loop
	void draw(sf::RenderWindow &window); //draw loop
	void goBack(); //go to menu

private:
	//widgets
	Game *m_game;
	GUI m_gui; //gui
	Button* m_backButton;
	Label* m_label;
	int m_selectedItem = 0;
};
#endif // !HELPSCREEN