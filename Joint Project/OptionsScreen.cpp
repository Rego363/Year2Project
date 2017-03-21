#include "OptionsScreen.h"


/// <summary>
/// Constructor
/// </summary>
/// <param name="game"></param>
OptionsScreen::OptionsScreen(Game & game) :
	m_game(&game)
{
	m_title = new Label("Options", 475, 50);
	m_difficultyButton = new Button("Difficulty", 550, 250);
	m_difficultyButton->getFocus();
	m_difficultyButton->Enter = std::bind(&OptionsScreen::setStateDifficulty, this);
	m_soundButton = new Button("Sound", 570, 350);
	m_soundButton->Enter = std::bind(&OptionsScreen::setStateSound, this);
	m_displayButton = new Button("Display", 565, 450);
	m_displayButton->Enter = std::bind(&OptionsScreen::setStateDisplay, this);
	m_backButton = new Button("Back", 575, 550);
	m_backButton->Enter = std::bind(&OptionsScreen::setStateBack, this);
	m_gui.addButton(m_difficultyButton);
	m_gui.addButton(m_soundButton);
	m_gui.addButton(m_displayButton);
	m_gui.addButton(m_backButton);
	m_gui.addLabel(m_title);
	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);

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

/// <summary>
/// Deconstructor
/// </summary>
OptionsScreen::~OptionsScreen()
{
}

/// <summary>
/// Update loop
/// </summary>
/// <param name="window"></param>
void OptionsScreen::render(sf::RenderWindow & window)
{
	window.draw(m_shaderSprite, &m_shader);
	m_gui. draw(window);
}

/// <summary>
/// Draw loop
/// </summary>
void OptionsScreen::update(float dt)
{
	m_shader.setParameter("time", dt);
	m_gui.update(m_currentSelect,4);
}

/// <summary>
/// When the difficulty button is pressed
/// Bring the user to the difficulty screen
/// </summary>
void OptionsScreen::setStateDifficulty()
{
	m_game->changeGameState(GameState::Difficulty);
}

/// <summary>
/// When the display button is pressed
/// Bring the user to the display screen
/// </summary>
void OptionsScreen::setStateDisplay()
{
	m_game->changeGameState(GameState::Display);
}

/// <summary>
/// When the sound button is pressed
/// Bring the user to the sound screen
/// </summary>
void OptionsScreen::setStateSound()
{
	m_game->changeGameState(GameState::Sound);
}

/// <summary>
/// When the back button is pressed
/// Bring the player back to the main menu
/// </summary>
void OptionsScreen::setStateBack()
{
	m_game->changeGameState(GameState::TheMenu);
}