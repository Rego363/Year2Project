#pragma once
#ifndef GARAGESCREEN
#define GARAGESCREEN

#include"GUI.h"
#include"Game.h"

class GarageScreen {

public:
	GarageScreen(float x, float y, Game& game);
	void update();
	void draw(sf::RenderWindow &window);
	void goBack();
	void goAccel();
	void goTurbo();
	void goBrake();
	void goSpeed();
	void goSteer();

private:
	int m_selectedItem = 0;
	static const int MAX_ITEMS = 6;
	Widget* m_widgets[MAX_ITEMS];
	Label* m_label;
	GUI m_gui;
	Game *m_game;

};
#endif // !GARAGESCREEN