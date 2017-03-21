#include "changeProfile.h"
#include "player.h"




changeProfile::changeProfile(Game &game) :
	m_game(&game)
{

	m_profileOne = new Button("Profile One", 450, 100);
	m_profileOne->Enter = std::bind(&changeProfile::goToMenu, this);
	m_profileOne->getFocus();
	m_profileTwo = new Button("Profile Two", 450, 150);
	m_profileTwo->Enter = std::bind(&changeProfile::goToMenu, this);
	m_profileThree = new Button("Profile Three", 450, 200);
	m_profileThree->Enter = std::bind(&changeProfile::goToMenu, this);
	m_Back = new Button("Back", 100, 500);
	m_Back->Enter = std::bind(&changeProfile::goToMenu, this);
	m_Delete = new Button ("Delete", 100, 550);
	m_New = new Button("New Profile", 100, 600);
	//m_currentName = new Label(name, 50, 30);

	m_gui.addButton(m_profileOne);
	m_gui.addButton(m_profileTwo);
	m_gui.addButton(m_profileThree);
	m_gui.addButton(m_Back);
	m_gui.addButton(m_Delete);
	m_gui.addButton(m_New);
	m_currentSelect = 0;
	m_gui.vertical = true;
//	m_gui.horizontal = true;


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


changeProfile::~changeProfile()
{

}


void changeProfile::render(sf::RenderWindow & window)
{
	window.draw(m_shaderSprite, &m_shader);
	m_gui.draw(window);

}


void changeProfile::update(float dt)
{
	m_shader.setParameter("time", dt);
	m_gui.update(m_currentSelect, 6);
}


void changeProfile::goToMenu()
{
	m_game->changeGameState(GameState::TheMenu);

}