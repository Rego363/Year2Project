#include "levels.h"

//Dylan
//set textures in here for each level
Levels::Levels(LevelData &level, Player &player, worldSquares &squares, Game &game) : m_currentLevel(&level),
										m_currentPlayer(&player),
										m_squares(&squares),
										m_game(&game)
{
	loadImages();
	loadFont();
	m_currentPlayer->m_car.setCurrentTexture(m_lambo);
	m_countDownNumber.setPosition(m_currentPlayer->m_car.getPos().x + 100, m_currentPlayer->m_car.getPos().y );
	m_countDownNumber.setCharacterSize(100);
	m_countDownNumber.setString("Race Starts in \n        3");
	m_countDownNumber.setFont(m_Font);
}

Levels::~Levels()
{
}

//update game
void Levels::update(float dt, sf::View &view)
{
	if (m_raceStarted == false)
	{
		m_startRace.restart();
		m_raceStarted = true;
	}
	if (m_countDown)
	{
		if (m_startRace.getElapsedTime().asSeconds() > 1 && m_startRace.getElapsedTime().asSeconds() < 3)
		{
			m_countDownNumber.setString("Race Starts in \n        2");
		}

		if (m_startRace.getElapsedTime().asSeconds() > 2 && m_startRace.getElapsedTime().asSeconds() < 4)
		{
			m_countDownNumber.setString("Race Starts in \n        1");
		}

		if (m_startRace.getElapsedTime().asSeconds() > 3 && m_startRace.getElapsedTime().asSeconds() < 6)
		{
			m_countDownNumber.setString("Go!!");
		}
	}

	if (m_startRace.getElapsedTime().asSeconds() > 6)
	{
		m_countDown = false;
	}

	m_squares->update();
	m_currentPlayer->update(dt, view);
}

//draw game
void Levels::render(sf::RenderWindow & window)
{
	m_squares->render(window);
	m_currentPlayer->m_car.draw(window);
	if (m_countDown)
	{
		window.draw(m_countDownNumber);
	}
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
