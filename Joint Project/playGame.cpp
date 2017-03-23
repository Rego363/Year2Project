#include "playGame.h"




playGame::playGame(Game &game): 
	m_game(&game)
{
	// This is where buttons are created and assigned positions
	m_title = new Label("Map Select", 450, 30);
	m_mapSelection = new Button("Map **", 450, 250);
	// I assign each button to bring the player to a different gamestate when pressed
	moveRight = new Button("Map One", 200, 200);
	moveRight->getFocus();
	moveRight->Enter = std::bind(&playGame::goToSpecs, this);
	moveDowner = new Button("Map Two", 200, 250);
	moveDowner->Enter = std::bind(&playGame::goToSpecsMap2, this);
	goBack = new Button("Back", 200, 500);
	goBack->Enter = std::bind(&playGame::goToMenu, this);


	if (!m_texture.loadFromFile(m_game->m_currentLevel.m_map1.m_fileName))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	
	if (!m_texture2.loadFromFile(m_game->m_currentLevel.m_map2.m_fileName))
	{
		//handle
	}
	m_sprite2.setTexture(m_texture2);
	m_sprite2.setPosition(0, 0);


	m_gui.addButton(moveRight);
	m_gui.addButton(moveDowner);
	m_gui.addButton(goBack);
	m_gui.addLabel(m_title);
	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);
	m_sprite.setPosition(400, 200);
	m_sprite.setScale(0.5, 0.5);
	m_sprite2.setPosition(400, 200);
	m_sprite2.setScale(0.5, 0.5);

}

playGame::~playGame()
{
}





void playGame::render(sf::RenderWindow & window)
 {

	if (m_currentSelect == 0)
	{
		window.draw(m_sprite);
	}

	if (m_currentSelect == 1)
	{
		window.draw(m_sprite2);
	}

	m_gui.draw(window);


}

void playGame::update()
{ 	
	m_gui.update(m_currentSelect, 3);
}


//Method that returns the player to the main menu
void playGame::goToMenu()
{
	m_game->changeGameState(GameState::TheMenu);
	
}
//Method that sends the player to the spec menu
void playGame::goToSpecs()
{
	m_game->m_nightMode->activateTheShader(false);
	m_game->changeGameState(GameState::Thespecs);

 }

void playGame::goToSpecsMap2()
{
	m_game->m_nightMode->activateTheShader(true);
	m_game->changeGameState(GameState::Thespecs);
}
