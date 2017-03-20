#include "Liscence.h"

//creates the screen
Liscence::Liscence(Game & game) : m_game(&game)
{
	m_title = new Label("Team C \n Racing \n 2k17", 100, 50);
	m_title->changeTextSize(200);
	m_gui.addLabel(m_title);

}

//destructor
Liscence::~Liscence()
{
}

//Displays screen for 3 seconds then switches to splash screen
void Liscence::update(sf::Time dt)
{
	m_CumulativeTime += dt;

	if (m_CumulativeTime.asSeconds() > 3)
	{
		m_game->changeGameState(GameState::TheSplash);
	}
}

//draws the screen
void Liscence::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

