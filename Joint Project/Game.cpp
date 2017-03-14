#include <iostream>

#include "Game.h"


static double const MS_PER_UPDATE = 10.0;

/// <summary>
/// Game is constructed
/// </summary>
Game::Game() :
	m_window(sf::VideoMode(1280, 720), "Joint Project, Team C")
{

	if (!LevelLoader::load(m_currentLevel))
	{
		return;
	}

	if (!m_startCar.loadFromFile(m_currentLevel.m_lambo.m_fileName))
	{
		cout << "car setup" << endl;
	}

	m_text.setFont(m_font);
	m_text.setString("RACING GAME");
	m_text.setPosition(m_window.getSize().x / 4, m_window.getSize().y / 2);
	m_text.setCharacterSize(70);

	m_optionsScreen = new OptionsScreen(*this);
	m_mapSelect = new playGame(*this);
	m_soundScreen = new SoundScreen(*this);
	m_displayScreen = new DisplayScreen(*this);
	m_garageScreen = new GarageScreen(m_window.getSize().x / 4, m_window.getSize().y / 2, *this);
	m_MainMenu = new MainMenu(*this);
	m_helpScreen = new HelpScreen(*this);
	m_Liscence = new Liscence(*this);
	m_Splash = new Splash(*this);
	m_diffScreen = new DifficultyScreen(*this);

	m_steeringScreen = new SteeringScreen(*this);
	m_turboScreen = new TurboScreen(*this);
	m_brakingScreen = new BrakingScreen(*this);
	m_speedScreen = new SpeedScreen(*this);
	m_accelerationScreen = new AccelerationScreen(*this);
	m_worldSquares = new worldSquares(*this, m_currentLevel);
	m_enterName = new EnterNameScreen(*this);

	m_startPos = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 4);
	m_player = new Player((float)m_window.getSize().x / 2, (float)m_window.getSize().y / 4, m_startCar, m_window);

	if(!m_buffer.loadFromFile("hobbits.wav"))
	{

	}
	music.setBuffer(m_buffer);
	music.setLoop(true);
	//music.play();

	/*  FOR TESTING*/
	/*******************************************************************************/

	///to be moved
	/*if (!m_ground.loadFromFile(m_currentLevel.m_ground.m_fileName))
	{

	}*/

	if (!m_ground.loadFromFile(m_currentLevel.m_sand.m_fileName))
	{
	}

	for (int i = 0; i < 10; i++)
	{
		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(0, -i*m_groundSprite[i].getGlobalBounds().height);
	}
	for (int i = 10; i < 20; i++)
	{

		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(1 * m_groundSprite[i].getGlobalBounds().width, (-i + 10)*m_groundSprite[i].getGlobalBounds().height);
	}
	for (int i = 20; i < 30; i++)
	{

		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(2 * m_groundSprite[i].getGlobalBounds().width, (-i + 20)*m_groundSprite[i].getGlobalBounds().height);
	}
	for (int i = 30; i < 40; i++)
	{
		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(3 * m_groundSprite[i].getGlobalBounds().width, (-i + 30)*m_groundSprite[i].getGlobalBounds().height);
	}

	for (int i = 40; i < 50; i++)
	{

		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(4 * m_groundSprite[i].getGlobalBounds().width, (-i + 40)*m_groundSprite[i].getGlobalBounds().height);
	}

	for (int i = 50; i < 60; i++)
	{

		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(5 * m_groundSprite[i].getGlobalBounds().width, (-i + 50)*m_groundSprite[i].getGlobalBounds().height);
	}
	for (int i = 60; i < 70; i++)
	{
		m_groundSprite[i].setTexture(m_ground);
		m_groundSprite[i].setScale(1.22, 1.22);
		m_groundSprite[i].setPosition(6 * m_groundSprite[i].getGlobalBounds().width, (-i + 60)*m_groundSprite[i].getGlobalBounds().height);
	}
	m_view = sf::View(sf::Vector2f(0, 0), sf::Vector2f(1280, 720));
	m_view2 = sf::View(sf::Vector2f(0, 0), sf::Vector2f(1280, 720));
	m_view2.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);

	/*******************************************************************************/

	m_specs = new specs(*this);

	m_Liscence = new Liscence(*this);
	m_Splash = new Splash(*this);
	m_diffScreen = new DifficultyScreen(*this);

	m_steeringScreen = new SteeringScreen(*this);
	m_turboScreen = new TurboScreen(*this);
	m_brakingScreen = new BrakingScreen(*this);
	m_speedScreen = new SpeedScreen(*this);
	m_accelerationScreen = new AccelerationScreen(*this);
	m_changeProfile = new changeProfile(*this);

	m_level = new Levels(m_currentLevel, *m_player, *m_worldSquares, *this);

}

/// <summary>
/// Initialise function
/// </summary>
void Game::init()
{
	// Display the list of all the video modes available for fullscreen
	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
}


/// <summary>
/// Game loop
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	while (m_window.isOpen())
	{
		processInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();

	}
}


//check if sprites in view, return false if sprite not in view
bool Game::isInView(sf::Sprite sprite)
{

	sf::FloatRect rect(m_view.getCenter().x - (m_view.getSize().x/2), m_view.getCenter().y - (m_view.getSize().y/2), m_view.getSize().x, m_view.getSize().y);
	if (rect.intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}




/// <summary>
/// Process Game inputs
/// </summary>
void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// Update function
/// </summary>
void Game::update(sf::Time time)
{

	switch (m_currentGameState)
	{

	case GameState::TheOptions:
		m_optionsScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::TheMenu:
		m_MainMenu->update();
		m_window.setView(m_view2);
		break;
	case GameState::Difficulty:
		m_diffScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Garage:
		m_garageScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Playing:
		m_window.setView(m_view2);
		break;
	case GameState::TheLicense:
		if (hasName == false)
		{
			m_player->setName(m_enterName->getEnteredName());
			//m_player->save("Dave");
			hasName = true;
		}
		m_Liscence->update(time);
		m_window.setView(m_view2);
		break;
	case GameState::TheSplash:
		m_Splash->update();
		m_window.setView(m_view2);
		break;
	case GameState::Sound:
		m_soundScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Display:
		m_displayScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::MapSelect:
		m_mapSelect->update();
		m_window.setView(m_view2);
		break;
	case GameState::Help:
		m_helpScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Thespecs:
		m_specs->update();
		m_window.setView(m_view2);
		break;
	case GameState::Acceleration:
		m_accelerationScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Braking:
		m_brakingScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Speed:
		m_speedScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Steering:
		m_steeringScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Turbo:
		m_turboScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::Racing:
		//m_view.setCenter(playerPos);
		m_window.setView(m_view);
		m_level->update(time.asSeconds(), m_view);
		break;
	case GameState::ChangeP:
		m_changeProfile->update();
		break;
	case GameState::EnterName:
		m_enterName->update();
		break;
	default:
		break;

	}

}

/// <summary>
/// Render function
/// </summary>
void Game::render()
{
	static int visible = 0;
	switch (m_currentGameState)
	{

	case GameState::TheOptions:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_optionsScreen->render(m_window);
		m_window.display();
		break;
	case GameState::TheMenu:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_MainMenu->render(m_window);
		m_window.display();
		break;
	case GameState::Difficulty:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_diffScreen->render(m_window);
		m_window.display();
		break;
	case GameState::Garage:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_garageScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Playing:
		m_window.clear(sf::Color(0, 0, 0, 255));
		//m_optionsScreen->render(m_window);
		m_window.display();
		break;
	case GameState::TheLicense:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_Liscence->render(m_window);
		m_window.display();
		break;
	case GameState::TheSplash:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_Splash->render(m_window);
		m_window.display();
		break;
	case GameState::Sound:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_soundScreen->render(m_window);
		m_window.display();
		break;
	case GameState::Display:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_displayScreen->render(m_window);
		m_window.display();
		break;
	case GameState::MapSelect:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_mapSelect->render(m_window);
		m_window.display();
		break;
	case GameState::Help:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_helpScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Thespecs:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_specs->render(m_window);
		m_window.display();
		break;
	case GameState::Acceleration:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_accelerationScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Braking:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_brakingScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Speed:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_speedScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Steering:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_steeringScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Turbo:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_turboScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Racing:   //put in levels
		m_window.clear(sf::Color(0, 0, 0, 255));
		for (int i = 0; i < 70; i++)
		{
			if (isInView(m_groundSprite[i]) == true)
			{
				visible++;
				m_window.draw(m_groundSprite[i]);
			}
		}
		std::cout << "Total visible tiles: " << visible << std::endl;
		visible = 0;
		system("cls");
		
		m_level->render(m_window);
		m_window.display();
		break;
	case GameState::ChangeP:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_changeProfile->render(m_window);
		m_window.display();
		break;
	case GameState::EnterName:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_enterName->draw(m_window);
		m_window.display();
		break;
	default:
		break;
	}


}

void Game::changeGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

void Game::changeGameDifficulty(GameDifficulty gameDiff)
{
	m_currentDifficulty = gameDiff;
}

