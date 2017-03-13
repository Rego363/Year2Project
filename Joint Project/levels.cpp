#include "levels.h"

//Dylan
//set textures in here for each level
Levels::Levels(LevelData level, Car & car) : m_currentLevel(level),
										m_currentCar(car)
{
	m_currentCar.setTexture(m_background);
}

Levels::~Levels()
{
}

//update game
void Levels::update(float dt)
{
	m_currentCar.update(dt);
}

//draw game
void Levels::render(sf::RenderWindow & window)
{
	m_currentCar.draw(window);
}

//load images in for cars/background/etc..
void Levels::loadImages()
{
	if (!m_background.loadFromFile(m_currentLevel.m_background.m_fileName))
	{
		std::cout << "failed to load font" << std::endl;
	}
}

void Levels::loadFont()
{
	if (!m_Font.loadFromFile(m_currentLevel.m_Font.m_fileNameFont))
	{
		std::cout << "failed to load font" << std::endl;
	}
}
