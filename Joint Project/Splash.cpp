#include "Splash.h"

Splash::Splash(Game & game) : m_game(&game)
{
	m_currentSelect = 0;
	m_button = new Button("Start Game", 560, 600);
	m_button->getFocus();
	m_button->Enter = std::bind(&Splash::setStateBack, this);
	m_gui.addButton(m_button);

	m_gui.vertical = true;
	
}

Splash::~Splash()
{
}

void Splash::update()
{
	m_gui.update(m_currentSelect, 1);
}

void Splash::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

void Splash::setStateBack()
{
	m_game->changeGameState(GameState::TheMenu);
}