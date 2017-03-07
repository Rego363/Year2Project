#include <iostream>

#include "Game.h"

static sf::Int32 MS_PER_UPDATE = 10.0;

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
	
}

/// <summary>
/// Render function
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 255));
	m_window.draw(m_text);
	m_window.display();

}