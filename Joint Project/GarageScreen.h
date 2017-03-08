#pragma once

#include"GUI.h"

class GarageScreen {

public:
	GarageScreen(float x, float y);
	void update();
	void draw(sf::RenderWindow &window);

private:
	int m_selectedItem = 0;
	static const int MAX_ITEMS = 6;
	Widget* m_widgets[MAX_ITEMS];
	Label* m_label;
	GUI m_gui;

};