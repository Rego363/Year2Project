#include "Liscence.h"

Liscence::Liscence(Game & game) : m_game(&game)
{
	m_title = new Label("Team C \n Racing \n 2k17", 100, 50);
	m_title->changeTextSize(200);
	m_gui.addLabel(m_title);
}

Liscence::~Liscence()
{
}

void Liscence::update(sf::Time dt)
{
	m_CumulativeTime += dt;

	if (m_CumulativeTime.asSeconds() > 5)
	{
		m_game->changeGameState(GameState::TheSplash);
	}
}

void Liscence::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

