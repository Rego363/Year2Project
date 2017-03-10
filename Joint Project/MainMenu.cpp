#include "MainMenu.h"

MainMenu::MainMenu(Game &game):
	m_game(&game)
{
	m_title = new Label("Main Menu", 475, 50);
	m_gui.addLabel(m_title);
	m_Play = new Button("Play", 550, 250);
	m_Play->getFocus();
	m_Play->Enter = std::bind(&MainMenu::goToPlay, this);
	m_Garage = new Button("Garage", 550, 300);
	m_Garage->Enter = std::bind(&MainMenu::GotoGarage, this);
	m_ChangeProfile = new Button("Change Profile", 550, 350);
	m_Options = new Button("Options", 550, 400);
	m_Options->Enter = std::bind(&MainMenu::goToOptions, this);
	m_Help = new Button("Help", 550, 450);
	m_Help->Enter = std::bind(&MainMenu::goToHelp, this);
	m_Exit = new Button("Quit", 550, 500);
	m_Exit->Enter = std::bind(&MainMenu::quit, this);

	m_gui.addButton(m_Play);
	m_gui.addButton(m_Garage);
	m_gui.addButton(m_ChangeProfile);
	m_gui.addButton(m_Options);
	m_gui.addButton(m_Help);
	m_gui.addButton(m_Exit);

	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);
};


MainMenu::~MainMenu()
{
}


void MainMenu::render(sf::RenderWindow & window)
{

	m_gui.draw(window);
}

void MainMenu::update()
{
	m_gui.update(m_currentSelect, 6);
}

void MainMenu::GotoGarage()
{
	m_game->changeGameState(GameState::Garage);
}

void MainMenu::quit()
{
	m_game->m_window.close();
}

void MainMenu::goToOptions()
{
	m_game->changeGameState(GameState::TheOptions);
}

void MainMenu::goToPlay()
{
	m_game->changeGameState(GameState::MapSelect);
}

void MainMenu::goToHelp()
{
	m_game->changeGameState(GameState::Help);
}

void MainMenu::goToSpecs()
{

	m_game->changeGameState(GameState::Thespecs);

}