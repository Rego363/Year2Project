#include "DifficultyScreen.h"

DifficultyScreen::DifficultyScreen(Game & game):
	m_game(&game)
{
	m_selectedItem = 0;
	m_widgets[0] = new RadioButton("easy", 550, 250, "diff");
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&DifficultyScreen::setEasy, this);
	m_widgets[1] = new RadioButton("medium", 550, 350, "diff");
	m_widgets[1]->getActive();
	m_widgets[0]->Enter = std::bind(&DifficultyScreen::setMedium, this);
	m_widgets[2] = new RadioButton("hard", 550, 450, "diff");
	m_widgets[0]->Enter = std::bind(&DifficultyScreen::setHard, this);
	m_widgets[3] = new Button("Back", 550, 550);
	m_widgets[3]->Enter = std::bind(&DifficultyScreen::goToOptions, this);

	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);
	}
	m_gui.vertical = true;
}

void DifficultyScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

void DifficultyScreen::update()
{
	m_gui.update(m_selectedItem, MAX_ITEMS);
}

void DifficultyScreen::goToOptions()
{
	m_game->changeGameState(GameState::TheOptions);
}

void DifficultyScreen::setEasy()
{
	m_game->changeGameDifficulty(GameDifficulty::Easy);
}

void DifficultyScreen::setMedium()
{
	m_game->changeGameDifficulty(GameDifficulty::Medium);
}

void DifficultyScreen::setHard()
{
	m_game->changeGameDifficulty(GameDifficulty::Hard);
}
