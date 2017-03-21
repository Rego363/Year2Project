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

	m_optionsScreen = make_unique<OptionsScreen>(*this);
	m_mapSelect = make_unique<playGame>(*this);
	m_soundScreen = make_unique<SoundScreen>(*this);
	m_displayScreen = make_unique<DisplayScreen>(*this);
	m_garageScreen = make_unique<GarageScreen>(m_window.getSize().x / 4, m_window.getSize().y / 2, *this);
	m_MainMenu = make_unique<MainMenu>(*this);
	m_helpScreen = make_unique<HelpScreen>(*this);
	m_Splash = make_unique<Splash>(*this);
	m_diffScreen = make_unique<DifficultyScreen>(*this);

	m_steeringScreen = make_unique<SteeringScreen>(*this);
	m_turboScreen = make_unique<TurboScreen>(*this);
	m_brakingScreen = make_unique<BrakingScreen>(*this);
	m_speedScreen = make_unique<SpeedScreen>(*this);
	m_accelerationScreen = make_unique<AccelerationScreen>(*this);
	m_Liscence = make_unique<Liscence>(*this);
	m_enterName = make_unique<EnterNameScreen>(*this);
	m_credits = make_unique<Credits>(*this, m_currentLevel);
	m_gameOverScreen = make_unique<GameOverScreen>(*this);

	m_startPos = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 4);
	m_car = make_unique<Car>(m_startCar, m_startPos);
	m_aiCar = make_unique<Car>(m_startCar, sf::Vector2f(0.0f, 0.0f));
	
	m_player = make_unique<Player>(0, 0, m_startCar, m_window, *this);
	if(!m_buffer.loadFromFile("music.wav"))
	{
		std::cout << "NO MUSIC" << std::endl;
	}

	music.setBuffer(m_buffer);
	music.setLoop(true);
	music.setVolume(100);
	//music.play();

	/*  FOR TESTING*/
	/*******************************************************************************/

	m_view = sf::View(sf::Vector2f(0, 0), sf::Vector2f(1280, 720));
	m_view2 = sf::View(sf::Vector2f(0, 0), sf::Vector2f(1280, 720));
	m_view2.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);

	/*******************************************************************************/

	m_specs = make_unique< specs>(*this);
	m_diffScreen = make_unique<DifficultyScreen>(*this);

	m_steeringScreen = make_unique<SteeringScreen>(*this);
	m_turboScreen = make_unique<TurboScreen>(*this);
	m_brakingScreen = make_unique<BrakingScreen>(*this);
	m_speedScreen = make_unique<SpeedScreen>(*this);
	m_accelerationScreen = make_unique<AccelerationScreen>(*this);
	m_changeProfile = make_unique<changeProfile>(*this);

	for (int i = 0; i < m_currentLevel.m_track.size(); i++)
	{
		sf::CircleShape circle(0,30);		
		circle.setRadius(m_currentLevel.m_track[i].m_size);
		circle.setPosition(m_currentLevel.m_track[i].m_position);
		m_track.push_back(circle);
	}

	m_ai = make_unique< Ai>(m_car->getPos().x, m_car->getPos().y + 100, m_aistartCar, m_track);

	m_background = make_unique<Background>( *this);
	
	m_level = make_unique< Levels>(m_currentLevel, *m_player, *m_ai, *this);

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

	rect = sf::FloatRect(m_view.getCenter().x - (m_view.getSize().x/2), m_view.getCenter().y - (m_view.getSize().y/2), m_view.getSize().x, m_view.getSize().y);
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
	case GameState::TheLicense:
		if (hasName == false)
		{
			m_player->setName(m_enterName->getEnteredName());
			//m_player->save("Dave");
			hasName = true;
		}
		m_Liscence->update();
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
	case GameState::GameOver:
		m_gameOverScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::ChangeP:
		m_changeProfile->update();
	
	//	m_player->update();
		break;
	case GameState::EnterName:
		m_enterName->update();
		break;
	case GameState::TheCredits:
		m_credits->update();
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
	case GameState::TheLicense:
		m_window.clear();
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
		m_player->draw(m_window);
		m_level->render(m_window);
		m_window.display();
		break;
	case GameState::GameOver:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(sprBack);
		m_gameOverScreen->draw(m_window);
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
	case GameState::TheCredits:
		m_window.clear();
		m_credits->render(m_window);
		m_window.display();
		break;
	default:
		break;
	}


}

//function to change the games current gamestate
void Game::changeGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

//function to change the difficulty of the game
void Game::changeGameDifficulty(GameDifficulty gameDiff)
{
	m_currentDifficulty = gameDiff;
}

string Game::nameDisplay()
{
	return m_player->getName();
	/*m_name.setString("Profile");*/
}


int Game::playerMoney()
{
	return m_player->getMoney();
}

void Game::chargePlayer(int amount)
{
	m_player->cost(amount);
}

std::string Game::getGarageTexture()
{
	return m_currentLevel.m_garage.m_fileName;
}