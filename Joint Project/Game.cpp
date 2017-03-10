#include <iostream>

#include "Game.h"

static double const MS_PER_UPDATE = 10.0;

/// <summary>
/// Game is constructed
/// </summary>
Game::Game() :
	m_window(sf::VideoMode(1280, 720), "Joint Project, Team C")
{
	if (!m_font.loadFromFile("Fonts/American Captain.ttf"))
	{
		std::cout << "failed to load font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString("RACING GAME");
	m_text.setPosition(m_window.getSize().x / 4, m_window.getSize().y / 2);
	m_text.setCharacterSize(70);
	m_player = new Player();
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





	/*  FOR TESTING*/
	/*******************************************************************************/

	if (!m_testText.loadFromFile("lambo.png"))
	{

	}
	m_startPos = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 4);
	m_car = new Car(m_testText, m_startPos);



	if (!m_testTextBack.loadFromFile("ground.png"))
	{

	}
	for (int i = 0; i < 10; i++)
	{
		m_testSprite[i].setTexture(m_testTextBack);
		m_testSprite[i].setScale(1.22, 1.22);
		m_testSprite[i].setPosition(i*m_testSprite[i].getGlobalBounds().width, 0);
		
	}


	m_view = sf::View(sf::Vector2f( 0, 0), sf::Vector2f(1280, 720));
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
	sf::Vector2f playerPos = m_car->getPos();

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

		
		m_view.setCenter(playerPos);

		m_window.setView(m_view);
		
		m_car->update();

		m_xbox.update();
		if (m_xbox.m_currentState.RTtrigger<-10.0)
		{
			m_car->increaseSpeed();
		}
		else if (m_xbox.m_currentState.RTtrigger < 0.0&& m_xbox.m_currentState.RTtrigger > -10.0)
		{
			m_car->slowDown();
		}

		if (m_xbox.m_currentState.LTtrigger>10.0)
		{
			m_car->decreaseSpeed();
		}
		if (m_car->isCarMoving() == true)
		{
			if (m_xbox.m_currentState.LeftThumbStick.x > 75)
			{
				m_car->increaseRotation();
			}
			if (m_xbox.m_currentState.LeftThumbStick.x < -75)
			{
				m_car->decreaseRotation();
			}
		}
		if (m_xbox.m_currentState.Back)
		{
			m_currentGameState = GameState::TheMenu;
		}
		if (m_xbox.m_currentState.A)
		{
			m_car->breaks();
		}

	default:

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
	case GameState::Racing:
		m_window.clear(sf::Color(0, 0, 0, 255));

		for (int i = 0; i < 10; i++)
		{


			m_window.draw(m_testSprite[i]);
		}

		//m_window.draw(m_testSprite);
		m_car->draw(m_window);
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
