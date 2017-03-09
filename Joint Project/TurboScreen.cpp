#include "TurboScreen.h"

TurboScreen::TurboScreen(Game & game):
	m_game(&game)
{
	m_label = new Label("Turbo", 100, 50);
	m_label->setUnderLined();
	m_label->changeTextSize(70);
	m_gui.addLabel(m_label);
	m_widgets[0] = new Button("Small", 100, 150);
	m_widgets[0]->getFocus();
	//m_widgets[0]->Enter = std::bind(&BrakingScreen::goToGarage, this);
	m_widgets[1] = new Button("Medium", 100, 250);
	m_widgets[2] = new Button("Large", 100, 350);
	m_widgets[3] = new Button("Back", 100, 450);
	m_widgets[3]->Enter = std::bind(&TurboScreen::goToGarage, this);

	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);
	}
	m_gui.vertical = true;
}

void TurboScreen::draw(sf::RenderWindow &window)
{
	m_gui.draw(window);
}

void TurboScreen::update()
{
	m_gui.update(m_selectedItem, MAX_ITEMS);
}

void TurboScreen::goToGarage()
{
	m_game->changeGameState(GameState::Garage);
}
