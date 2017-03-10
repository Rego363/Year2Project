#include "playGame.h"




playGame::playGame(Game &game): 
	m_game(&game)
{

	m_title = new Label("Map Select", 450, 30);
	m_mapSelection = new Button("Map **", 450, 250);
	moveLeft = new Button("Map Zero", 250, 150);
	moveLeft->Enter = std::bind(&playGame::goToSpecs, this);
	moveLeft->getFocus();
	moveRight = new Button("Map One", 250, 200);
	moveRight->Enter = std::bind(&playGame::goToSpecs, this);
	moveDowner = new Button("Map Two", 250, 250);
	moveDowner->Enter = std::bind(&playGame::goToSpecs, this);
	moveDownest = new Button("Map Three", 250, 300);
	moveDownest->Enter = std::bind(&playGame::goToSpecs, this);
	goBack = new Button("Back", 100, 500);
	goBack->Enter = std::bind(&playGame::goToMenu, this);

	if (!m_texture.loadFromFile("09RoadCourseMap.jpg"))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	
	if (!m_texture2.loadFromFile("mapsmall.jpg"))
	{
		//handle
	}
	m_sprite2.setTexture(m_texture2);
	m_sprite2.setPosition(0, 0);



	m_gui.addButton(moveLeft);
//	m_gui.addButton(m_mapSelection);
	m_gui.addButton(moveRight);
	m_gui.addButton(moveDowner);
	m_gui.addButton(moveDownest);
	m_gui.addButton(goBack);
	m_gui.addLabel(m_title);
//	m_gui.addButton(m_rectB);
	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);
	m_sprite.setPosition(360, 140);
	m_sprite.setScale(0.5, 0.5);
	m_sprite2.setPosition(360, 140);
	m_sprite2.setScale(0.5, 0.5);

	m_rect.setPosition(520, 140);
	m_rect.setSize(sf::Vector2f(200,200));//dynamic rectangle sizing based on text


		m_rect.setFillColor(sf::Color::Red);
	
	
	//	m_rect.setFillColor(sf::Color::Blue);
	

	m_rect.setOutlineColor(sf::Color::Blue); //set to transparent
	m_rect.setOutlineThickness(2);
//	posX = 0;
}

playGame::~playGame()
{
}





void playGame::render(sf::RenderWindow & window)
 {

	
	
		window.draw(m_rect);
	

	m_gui.draw(window);


}

void playGame::update()
{
	if (m_currentSelect == 0)
	{
		m_rect.setFillColor(sf::Color::Red);
		m_rect.setOutlineColor(sf::Color::Blue);
	}
	if (m_currentSelect == 1)
	{
		m_rect.setFillColor(sf::Color::Blue);
		m_rect.setOutlineColor(sf::Color::Red);
	}
	if (m_currentSelect == 2)
	{
		m_rect.setFillColor(sf::Color::Green);
		m_rect.setOutlineColor(sf::Color::Blue);
	}
	if (m_currentSelect == 3)
	{
		m_rect.setFillColor(sf::Color::Magenta);
		m_rect.setOutlineColor(sf::Color::Blue);
	}

	if (m_currentSelect == 4)
	{
		
		//	m_game->changeGameState(GameState::TheMenu);


	}
	
	
	m_gui.update(m_currentSelect, 5);
}

void playGame::goToMenu()
{
	m_game->changeGameState(GameState::TheMenu);
	
}

void playGame::goToSpecs()
{
	m_game->changeGameState(GameState::Thespecs);

 }
