#pragma once


#include "GUI.h"
#include "Button.h"

class OptionsScreen
{
public:
	OptionsScreen();
	~OptionsScreen();
	void render(sf::RenderWindow & window);
	void update();

private:

	GUI m_gui;
	Label *m_title;
	Button *m_difficultyButton;
	Button *m_soundButton;
	Button *m_displayButton;
	Button *m_backButton;
	//RadioButton* m_radio;
	Slider *m_slider;
	int m_currentSelect;
	float pizza = 100;
};

