#include "levels.h"

//Dylan
//set textures in here for each level
Levels::Levels(LevelData &level, Player &player, worldSquares &squares) : m_currentLevel(&level),
										m_currentPlayer(&player),
										m_squares(&squares)
{
	loadImages();
	m_currentPlayer->m_car.setCurrentTexture(m_lambo);
}

Levels::~Levels()
{
}

//update game
void Levels::update(float dt, sf::View &view)
{
	m_squares->update();
	m_currentPlayer->update(dt, view);
}

//draw game
void Levels::render(sf::RenderWindow & window)
{
	m_squares->render(window);
	m_currentPlayer->m_car.draw(window);
}

//load images in for cars/background/etc..
void Levels::loadImages()
{
	if (!m_lambo.loadFromFile(m_currentLevel->m_lambo.m_fileName))
	{
		std::cout << "failed to load font" << std::endl;
	}
}

//load in fonts
void Levels::loadFont()
{
	if (!m_Font.loadFromFile(m_currentLevel->m_Font.m_fileNameFont))
	{
		std::cout << "failed to load font" << std::endl;
	}
}
