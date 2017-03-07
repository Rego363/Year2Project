#include "OptionsScreen.h"



OptionsScreen::OptionsScreen()
{
	m_title = new Label("Options", 475, 50);
	m_difficultyButton = new Button("Difficulty", 550, 250);
	m_difficultyButton->getFocus();
	m_soundButton = new Button("Sound", 570, 350);
	m_displayButton = new Button("Display", 565, 450);
	m_backButton = new Button("Back", 575, 550);
	m_gui.addButton(m_difficultyButton);
	m_gui.addButton(m_soundButton);
	m_gui.addButton(m_displayButton);
	m_gui.addButton(m_backButton);
	m_gui.addLabel(m_title);
	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);
}


OptionsScreen::~OptionsScreen()
{
}


void OptionsScreen::render(sf::RenderWindow & window)
{

	m_gui.draw(window);
}

void OptionsScreen::update()
{
	m_gui.update(m_currentSelect,4);
}
