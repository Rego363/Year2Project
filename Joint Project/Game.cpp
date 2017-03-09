#include <iostream>

#include "Game.h"

static double const MS_PER_UPDATE = 10.0;

/// <summary>
/// Game is constructed
/// </summary>
Game::Game() : m_window(sf::VideoMode(1280, 720), "Joint Project, Team C") 
{
	if (!m_font.loadFromFile("Fonts/American Captain.ttf"))
	{
		std::cout << "failed to load font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString("RACING GAME");
	m_text.setPosition(m_window.getSize().x / 4, m_window.getSize().y / 2);
	m_text.setCharacterSize(70);
	m_optionsScreen = new OptionsScreen(*this);
	m_mapSelect = new playGame();
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
		break;
	case GameState::TheMenu:
		m_MainMenu->update();
		break;
	case GameState::Difficulty:
		m_diffScreen->update();
		break;
	case GameState::Garage:
		m_garageScreen->update();
		break;
	case GameState::Playing:
		break;
	case GameState::TheLicense:
		m_Liscence->update(time);
		break;
	case GameState::TheSplash:
		m_Splash->update();
		break;
	case GameState::Sound:
		m_soundScreen->update();
		break;
	case GameState::Display:
		m_displayScreen->update();
		break;
	case GameState::MapSelect:
		m_mapSelect->update();
	default:
		break;
	case GameState::Help:
		m_helpScreen->update();
		break;

	case GameState::Acceleration:
		m_accelerationScreen->update();
		break;
	case GameState::Braking:
		m_brakingScreen->update();
		break;
	case GameState::Speed:
		m_speedScreen->update();
		break;
	case GameState::Steering:
		m_steeringScreen->update();
		break;
	case GameState::Turbo:
		m_turboScreen->update();
		break;
		
	}




	
}

/// <summary>
/// Render function
/// </summary>
void Game::render()
{

	switch (m_currentGameState)
	{
	default:
		break;

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
		//m_optionsScreen->render(m_window);
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
