#include "levels.h"

//Dylan
//set textures in here for each level
Levels::Levels(LevelData &level, Player &player,  Ai &ai, Ai &aiTwo, Ai &aiThree, Game &game) : m_currentLevel(&level),
										m_currentPlayer(&player),
										m_ai(&ai),
										m_aiTwo(&aiTwo),
										m_aiThree(&aiThree),
										m_game(&game)
{
	loadImages();
	loadFont();
	//m_currentPlayer->m_car.setCurrentTexture(m_lambo);
	setupTexts();

	m_startLine.setPosition(m_currentPlayer->m_car.getPos().x + 40, m_currentPlayer->m_car.getPos().y - 100);
	m_startLine.setSize(sf::Vector2f(5, 200));
	m_startLine.setFillColor(sf::Color::Red);


	//m_ai->m_car.scaleAi();
	/*m_ai->m_car.scaleAi();
	m_aiTwo->m_car.scaleAi();
	m_aiThree->m_car.scaleAi();*/


	m_currentSelect = 0;
	m_credits = new Button("Press A to end", m_startLine.getPosition().x - 192, m_startLine.getPosition().y);
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
		m_game->m_physicsBalls->update();
		if (m_raceStarted == false)
		{
		m_currentPlayer->update(dt, view);

			m_startRace.restart();
			m_raceStarted = true;
		}

		startTimes();
		m_Lap.setString("Lap: " + to_string(currentlap) + "/" + to_string(m_maxLaps));

		if (m_startRace.getElapsedTime().asSeconds() > 3 && m_startRace.getElapsedTime().asSeconds())
		{
			m_currentPlayer->update(dt, view);
			m_ai->update();
			m_aiTwo->update();
			m_aiThree->update();
			

			m_currentLapTime.setPosition(m_currentPlayer->m_car.getPos().x + 300, m_currentPlayer->m_car.getPos().y - 350);
			m_currentLapTime.setString("Time: " + to_string(m_raceTime.getElapsedTime().asSeconds()));
			m_currentSpeed.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 230);
			m_currentSpeed.setString("Speed: " + to_string((int)m_currentPlayer->m_car.m_speed));
			m_bestLap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 350);
			m_lastLap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 310);
			m_Lap.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 270);

			m_turbos.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 190);
			m_turbos.setString("turbos: " + to_string((int)m_game->m_player->m_car.getTurbos()));
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
					m_currentPlayer->m_car.m_speed = 0;
					m_currentPlayer->m_car.m_soundEffect.stop();
					game_on = false;
				}

				m_raceTime.restart();
			}
		}
	}
	else
	{
		m_gui.update(m_currentSelect, 1);
		m_currentPlayer->m_car.m_speed = 0;
	}
}

//draw game
void Levels::render(sf::RenderWindow & window)
{
	if (game_on)
	{
		m_currentPlayer->draw(window);
		m_ai->render(window);
		m_game->m_physicsBalls->render(window);
		m_aiTwo->render(window);
		m_aiThree->render(window);
		window.draw(m_currentLapTime);
		window.draw(m_startLine);
		window.draw(m_bestLap);
		window.draw(m_lastLap);
		window.draw(easterEgg);
		window.draw(m_Lap);
		window.draw(m_turbos);
		m_currentPlayer->draw(window);
		window.draw(m_currentSpeed);
		if (m_countDown)
		{
			window.draw(m_countDownNumber);
		}
	}
	else
	{
		m_currentPlayer->m_car.draw(window);
		m_ai->render(window);
		m_aiTwo->render(window);
		m_aiThree->render(window);
		window.draw(m_currentLapTime);
		window.draw(m_startLine);
		window.draw(m_bestLap);
		window.draw(m_lastLap);
		window.draw(m_Lap);
		window.draw(m_currentSpeed);
		window.draw(m_turbos);
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

	m_turbos.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 190);
	m_turbos.setCharacterSize(50);
	m_turbos.setString("turbos: " + to_string((int)m_game->m_player->m_car.getTurbos()));
	m_turbos.setFont(m_Font);

	easterEgg.setPosition(5700, 215);
	easterEgg.setCharacterSize(50);
	easterEgg.setString("Pete is cool");
	easterEgg.setFont(m_Font);
	easterEgg.setColor(sf::Color::Red);
	
	m_currentSpeed.setPosition(m_currentPlayer->m_car.getPos().x - 620, m_currentPlayer->m_car.getPos().y - 230);
	m_currentSpeed.setCharacterSize(50);
	m_currentSpeed.setString("Speed: " + to_string(m_currentPlayer->m_car.m_speed));
	m_currentSpeed.setFont(m_Font);
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

/// <summary>
/// resets everything in the level so it can ber replayed
/// </summary>
void Levels::resetLevel()
{
	loadImages();
	loadFont();
	m_currentPlayer->m_car.resetPosition();
	m_currentPlayer->m_car.m_rotation = 0;
	m_currentPlayer->m_car.setRotation(0);
	setupTexts();
	m_startLine.setPosition(m_currentPlayer->m_car.getPos().x + 40, m_currentPlayer->m_car.getPos().y - 100);
	m_startLine.setSize(sf::Vector2f(5, 200));
	m_startLine.setFillColor(sf::Color::Red);
	m_currentSelect = 0;
	m_gui.vertical = true;
	game_on = true;
	m_countDown = true;
	m_raceStarted = false;
	currentlap = 1;
	m_ai->m_car.setAiPosition(sf::Vector2f(760, 1050));
	m_aiTwo->m_car.setAiPosition(sf::Vector2f(660.0f, 1050.0f));
	m_aiThree->m_car.setAiPosition(sf::Vector2f(660.0f, 1100.0f));
	m_ai->m_car.m_rotation = 0;
	m_aiTwo->m_car.m_rotation = 0;
	m_aiThree->m_car.m_rotation = 0;
	m_ai->m_car.setRotation(0);
	m_aiTwo->m_car.setRotation(0);
	m_aiThree->m_car.setRotation(0);
	m_ai->resetNode();
	m_aiTwo->resetNode();
	m_aiThree->resetNode();
	m_credits = new Button("Press A to end", m_startLine.getPosition().x - 192, m_startLine.getPosition().y);

	if (m_game->m_turboScreen->m_smallEquipped == true)
	{
		m_currentPlayer->m_car.setTurbo(1);
	}
	else if (m_game->m_turboScreen->m_mediumEquipped == true)
	{
		m_currentPlayer->m_car.setTurbo(2);
	}
	else if (m_game->m_turboScreen->m_largeEquipped == true)
	{
		m_currentPlayer->m_car.setTurbo(3);
	}
}
