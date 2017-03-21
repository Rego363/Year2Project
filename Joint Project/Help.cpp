#include "Help.h"

HelpScreen::HelpScreen(Game & game):
	m_game(&game)
{
	m_label = new Label("You will get no help!", 1280 / 2, 720 / 4);

	m_backButton = new Button("Back", 1280 / 2, 720 / 2);
	m_backButton->getFocus();
	m_backButton->Enter = std::bind(&HelpScreen::goBack, this);
	
	m_gui.addButton(m_backButton);
	m_gui.addLabel(m_label);
	m_gui.vertical = true;

	if (!m_blankTexture.loadFromFile("blankBackground.png"))	// Load blank texture
	{
		std::cout << "blankTile failed to load" << std::endl;	//Error message
	}

	m_shaderSprite.setTexture(m_blankTexture);	// Set texture for the blank sprite

	if (!m_shader.loadFromFile("Shaders/Smoke.frag", sf::Shader::Fragment)) //Load shader
	{
		std::cout << "shader failed to load" << std::endl;	// Error message
	}

	m_shader.setParameter("time", 0.0f);
	m_shader.setParameter("resolution", 1280.0f, 720.0f);
	m_shaderSprite.setPosition(0.0f, 0.0f);
}

void HelpScreen::update(float dt)
{
	m_shader.setParameter("time", dt);
	m_gui.update(m_selectedItem, 1);
}

void HelpScreen::draw(sf::RenderWindow & window)
{
	window.draw(m_shaderSprite, &m_shader);
	m_gui.draw(window);
}

void HelpScreen::goBack()
{
	m_game->changeGameState(GameState::TheMenu);
}
