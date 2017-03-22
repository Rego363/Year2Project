#include "Help.h"

HelpScreen::HelpScreen(Game & game):
	m_game(&game)
{
	m_label = new Label("You will get no help!", 1280 / 2, 720 / 4);

	m_backButton = new Button("Back", 1280 / 2, 720 / 2);
	m_backButton->getFocus();
	m_backButton->Enter = std::bind(&HelpScreen::goBack, this);
	
	m_gui.addButton(m_backButton);
	m_gui.addLabel(m_label);
	m_gui.vertical = true;
}

void HelpScreen::update()
{
	m_gui.update(m_selectedItem, 1);
}

void HelpScreen::draw(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

void HelpScreen::goBack()
{
	m_game->changeGameState(GameState::TheMenu);
}
