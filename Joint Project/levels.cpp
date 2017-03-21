#include "levels.h"

//Dylan
//set textures in here for each level
Levels::Levels(LevelData &level, Player &player,  Ai &ai, Game &game) : m_currentLevel(&level),
										m_currentPlayer(&player),
										m_ai(&ai),
										m_game(&game)
{
	loadImages();
	loadFont();
	m_currentPlayer->m_car.setCurrentTexture(m_lambo);
	setupTexts();

	m_startLine.setPosition(m_currentPlayer->m_car.getPos().x + 40, m_currentPlayer->m_car.getPos().y - 100);
	m_startLine.setSize(sf::Vector2f(5, 200));
	m_startLine.setFillColor(sf::Color::Red);

	m_ai->m_car.scaleAi();

	m_currentSelect = 0;
	m_credits = new Button("Press A to end", m_currentPlayer->m_car.getPos().x , m_currentPlayer->m_car.getPos().y -300);
	m_credits->getFocus();
	m_credits->Enter = std::bind(&Levels::setStateBack, this);
	m_gui.addButton(m_credits);

	m_gui.vertical = true;
	game_on = true;
	m_countDown = true;
	m_raceStarted = false;
}

Levels::~Levels()
{
}

//update game
void Levels::update(float dt, sf::View &view)
{
	if (game_on)
	{
		if (m_raceStarted == false)
		{
		m_currentPlayer->update(dt, view);

			m_startRace.restart();
			m_raceStarted = true;
		}

		startTimes();

		if (m_startRace.getElapsedTime().asSeconds() > 3 && m_startRace.getElapsedTime().asSeconds())
		{
			m_currentPlayer->update(dt, view);
			m_ai->update();

			m_currentLapTime.setPosition(m_currentPlayer->m_car.getPos().x + 300, m_currentPlayer->m_car.getPos().y - 350);
			m_currentLapTime.setString("Time: " + to_string(m_raceTime.getElapsedTime().asSeconds()));
			m_bestLap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 350);
			m_lastLap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 310);
			m_Lap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 270);
			m_Lap.setString("Lap: " + to_string(currentlap) + "/" + to_string(m_maxLaps));
		}

		if ((sf::IntRect(m_currentPlayer->m_car.getSprite().getPosition().x, m_currentPlayer->m_car.getSprite().getPosition().y - 20,
			60, 60))
			.intersects(sf::IntRect(m_startLine.getPosition().x, m_startLine.getPosition().y, 5, 200)))
		{
			if (m_raceTime.getElapsedTime().asSeconds() > 10)
			{

				if (m_raceTime.getElapsedTime().asSeconds() < tempTime)
				{
					tempTime = m_raceTime.getElapsedTime().asSeconds();
					m_bestLap.setString("Best Lap Time: " + to_string((int)m_raceTime.getElapsedTime().asSeconds()));
				}
				else if (tempTime == 0)
				{
					tempTime = m_raceTime.getElapsedTime().asSeconds();
					m_bestLap.setString("Best Lap Time: " + to_string((int)m_raceTime.getElapsedTime().asSeconds()));
				}

				m_lastLap.setString("Last Lap Time: " + to_string((int)m_raceTime.getElapsedTime().asSeconds()));
				currentlap += 1;

				if (currentlap > m_maxLaps)
				{
					game_on = false;
				}

				m_raceTime.restart();
			}
		}
	}
	else
	{
		m_gui.update(m_currentSelect, 1);
	}
}

//draw game
void Levels::render(sf::RenderWindow & window)
{
	if (game_on)
	{
		//m_squares->render(window);
		m_currentPlayer->m_car.draw(window);
		m_ai->render(window);
		window.draw(m_currentLapTime);
		window.draw(m_startLine);
		window.draw(m_bestLap);
		window.draw(m_lastLap);
		window.draw(easterEgg);
		window.draw(m_Lap);
		if (m_countDown)
		{
			window.draw(m_countDownNumber);
		}
	}
	else
	{
		m_currentPlayer->m_car.draw(window);
		m_ai->render(window);
		window.draw(m_currentLapTime);
		window.draw(m_startLine);
		window.draw(m_bestLap);
		window.draw(m_lastLap);
		window.draw(m_Lap);
		m_gui.draw(window);
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

//Funtion for timers
void Levels::startTimes()
{
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


	if (m_startRace.getElapsedTime().asSeconds() < 3)
	{
		m_raceTime.restart();
	}

}

//Function to set up text
void Levels::setupTexts()
{
	m_countDownNumber.setPosition(m_currentPlayer->m_car.getPos().x + 100, m_currentPlayer->m_car.getPos().y);
	m_countDownNumber.setCharacterSize(100);
	m_countDownNumber.setString("Race Starts in \n        3");
	m_countDownNumber.setFont(m_Font);

	m_currentLapTime.setPosition(m_currentPlayer->m_car.getPos().x + 300, m_currentPlayer->m_car.getPos().y - 350);
	m_currentLapTime.setCharacterSize(50);
	m_currentLapTime.setString("Time: ");
	m_currentLapTime.setFont(m_Font);

	m_bestLap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 350);
	m_bestLap.setCharacterSize(50);
	m_bestLap.setString("Best Lap Time: ");
	m_bestLap.setFont(m_Font);

	m_lastLap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 310);
	m_lastLap.setCharacterSize(50);
	m_lastLap.setString("Last Lap Time: ");
	m_lastLap.setFont(m_Font);

	m_Lap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 270);
	m_Lap.setCharacterSize(50);
	m_Lap.setString("Lap: " + to_string(currentlap) + "/" + to_string(m_maxLaps));
	m_Lap.setFont(m_Font);

	easterEgg.setPosition(5700, 215);
	easterEgg.setCharacterSize(50);
	easterEgg.setString("Pete is cool");
	easterEgg.setFont(m_Font);
	easterEgg.setColor(sf::Color::Red);
	
}

// sets gamestate
void Levels::setStateBack()
{
	//m_game->m_window.setPosition(sf::Vector2i(0.0f, 0.0f));
	m_game->changeGameState(GameState::GameOver);
}

std::string Levels::getBestLapTime()
{
	return m_bestLap.getString();
}

void Levels::resetLevel()
{
	loadImages();
	loadFont();
	m_currentPlayer->m_car.setCurrentTexture(m_lambo);
	setupTexts();
	m_startLine.setPosition(m_currentPlayer->m_car.getPos().x + 40, m_currentPlayer->m_car.getPos().y - 100);
	m_startLine.setSize(sf::Vector2f(5, 200));
	m_startLine.setFillColor(sf::Color::Red);
	//m_ai->m_car.scaleAi();
	m_currentSelect = 0;
	m_gui.vertical = true;
	game_on = true;
	m_countDown = true;
	m_raceStarted = false;
	m_currentPlayer->m_car.setAiPosition(sf::Vector2f(760, 1100));
	m_currentPlayer->m_car.m_rotation = 0;
}
