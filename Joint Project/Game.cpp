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

	if (!m_aistartCar.loadFromFile(m_currentLevel.m_aiLambo.m_fileName))
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
	m_car = new Car(m_startCar, m_startPos);
	m_aiCar = new Car(m_startCar, sf::Vector2f(0.0f, 0.0f));
	m_player = new Player(0, 0, m_startCar, m_window, *this);

	if(!m_buffer.loadFromFile("music.wav"))
	{
		std::cout << "NO MUSIC" << std::endl;
	}

	music.setBuffer(m_buffer);
	music.setLoop(true);
	music.setVolume(100);
	music.play();

	/*  FOR TESTING*/
	/*******************************************************************************/

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

	for (int i = 0; i < m_currentLevel.m_track.size(); i++)
	{
		sf::CircleShape circle(0,30);		
		circle.setRadius(m_currentLevel.m_track[i].m_size);
		circle.setPosition(m_currentLevel.m_track[i].m_position);
		m_track.push_back(circle);
	}

	m_ai = new Ai(m_car->getPos().x, m_car->getPos().y + 100, m_aistartCar, m_track);

	m_background = new Background( *this);
	
	m_level = new Levels(m_currentLevel, *m_player, *m_worldSquares, *m_ai, *this);

	if (!m_backgroundImage.loadFromFile("backgroundBlue.png"))
	{

	}
	sprBack.setTexture(m_backgroundImage);
	sprBack.setPosition(0, 0);


	
}

/// <summary>
/// Initialise function
/// </summary>
void Game::init()
{
	// Display the list of all the video modes available for fullscreen
	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	timePerFrame = sf::seconds(1.0f / 60.0f);
}


/// <summary>
/// Game loop
/// </summary>
void Game::run()
{
	timeSinceLastUpdate = sf::Time::Zero;

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
		m_window.setView(m_view);
		m_level->update(time.asSeconds(), m_view);

		
		m_xbox.update();
		if (m_xbox.m_currentState.Back&& !m_xbox.m_previousState.Back)
		{
			m_background->activateTheShader();
		}

		
		break;
	case GameState::ChangeP:
		m_changeProfile->update();
	
	//	m_player->update();
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
	switch (m_currentGameState)
	{

	case GameState::TheOptions:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_optionsScreen->render(m_window);
		m_window.display();
		break;
	case GameState::TheMenu:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_MainMenu->render(m_window);
		m_window.display();
		break;
	case GameState::Difficulty:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_diffScreen->render(m_window);
		m_window.display();
		break;
	case GameState::Garage:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
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
		m_window.draw(sprBack);
		m_Liscence->render(m_window);
		m_window.display();
		break;
	case GameState::TheSplash:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_Splash->render(m_window);
		m_window.display();
		break;
	case GameState::Sound:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_soundScreen->render(m_window);
		m_window.display();
		break;
	case GameState::Display:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_displayScreen->render(m_window);
		m_window.display();
		break;
	case GameState::MapSelect:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_mapSelect->render(m_window);
		m_window.display();
		break;
	case GameState::Help:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_helpScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Thespecs:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_specs->render(m_window);
		m_window.display();
		break;
	case GameState::Acceleration:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_accelerationScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Braking:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_brakingScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Speed:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_speedScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Steering:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_steeringScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Turbo:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_turboScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Racing:   //put in levels
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_background->draw(m_window);
		m_level->render(m_window);
		m_window.display();
		break;
	case GameState::ChangeP:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		//nameDisplay(m_currentName);
		m_changeProfile->render(m_window);
	//	m_player->getName(m_name);

		m_window.display();
		break;
	case GameState::EnterName:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
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


string Game::nameDisplay()
{
	return m_player->getName();
	/*m_name.setString("Profile");*/
}
