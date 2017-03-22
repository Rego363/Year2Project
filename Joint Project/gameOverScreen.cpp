#include "gameOverScreen.h"

GameOverScreen::GameOverScreen(Game & game):
	m_game(&game)
{
	m_label = new Label("Game Over", 10, -80);
	m_label->changeTextSize(350);
	m_moneyEarned = new Label("Money earned: ", 60, 450);
	m_time = new Label("Time: ", 450, 450);
	m_placement = new Label("Place: ", 1000, 450);
	m_button = new Button("Return", 550, 650);
	m_button->Enter = std::bind(&GameOverScreen::goToGame, this);
	m_button->getFocus();
	
	m_gui.addLabel(m_label);
	m_gui.addLabel(m_moneyEarned);
	m_gui.addLabel(m_time);
	m_gui.addLabel(m_placement);
	m_gui.addButton(m_button);
	m_gui.vertical = true;
}

void GameOverScreen::draw(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

void GameOverScreen::update()
{
	m_gui.update(m_selectedItem, 1);
	m_time->updateText(m_game->getBestLapTime()+ " seconds");
}

void GameOverScreen::goToGame()
{
	m_game->changeGameState(GameState::TheMenu);
}
