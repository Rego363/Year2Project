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
	m_ChangeProfile->Enter = std::bind(&MainMenu::goToChangeP, this);
	m_Options = new Button("Options", 550, 400);
	m_Options->Enter = std::bind(&MainMenu::goToOptions, this);
	m_Help = new Button("Help", 550, 450);
	m_Help->Enter = std::bind(&MainMenu::goToHelp, this);
	m_Credits = new Button("Credits", 550, 500);
	m_Credits->Enter = std::bind(&MainMenu::goToCredits, this);
	m_Exit = new Button("Quit", 550, 550);
	m_Exit->Enter = std::bind(&MainMenu::quit, this);

	m_gui.addButton(m_Play);
	m_gui.addButton(m_Garage);
	m_gui.addButton(m_ChangeProfile);
	m_gui.addButton(m_Options);
	m_gui.addButton(m_Help);
	m_gui.addButton(m_Credits);
	m_gui.addButton(m_Exit);

	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);

	if (!m_blankTexture.loadFromFile("blankBackground.png"))	// Load blank texture
	{
		std::cout << "blankTile failed to load" << std::endl;	//Error message
	}

	m_shaderSprite.setTexture(m_blankTexture);	// Set texture for the blank sprite

	if (!m_shader.loadFromFile("Shaders/Smoke.frag", sf::Shader::Fragment)) //Load shader
	{
		std::cout << "shader failed to load" << std::endl;	// Error message
	}

	m_shader.setParameter("time", 0.0f);
	m_shader.setParameter("resolution", 1280.0f, 720.0f);
	m_shaderSprite.setPosition(0.0f, 0.0f);

};


MainMenu::~MainMenu()
{
}


void MainMenu::render(sf::RenderWindow & window)
{
	window.draw(m_shaderSprite, &m_shader);
	m_gui.draw(window);
}

void MainMenu::update(float dt)
{

	m_shader.setParameter("time", dt);
	m_gui.update(m_currentSelect, 7);
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

void MainMenu::goToChangeP()
{

	m_game->changeGameState(GameState::ChangeP);

}

void MainMenu::goToCredits()
{
	m_game->changeGameState(GameState::TheCredits);
}
