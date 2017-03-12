#include "DisplayScreen.h"


/// <summary>
/// Constructor
/// </summary>
/// <param name="game"></param>
DisplayScreen::DisplayScreen(Game & game) :
	m_game(&game)
{
	m_speed = 100.0f;
	m_currentSelect = 0;

	m_title = new Label("Display", 470, 50);
	m_title->changeTextSize(100);
	m_gui.addLabel(m_title);

	m_animeOn = new CheckBox("Animations On/Off", 50, 150);
	m_animeOn->getFocus();
	m_animeOn->getActive();
	m_gui.addCheckBox(m_animeOn);
	m_animeSpeed = new Slider(75.0f, 225.0f, m_speed, "Animation speed");
	m_gui.addSlider(m_animeSpeed);

	m_backButton = new Button("Back", 50, 600);
	m_backButton->Enter = std::bind(&DisplayScreen::setStateBack, this);
	m_gui.addButton(m_backButton);

	m_gui.vertical = true;

}

/// <summary>
/// Deconstructor
/// </summary>
DisplayScreen::~DisplayScreen()
{
}

/// <summary>
/// Update loop
/// </summary>
void DisplayScreen::update()
{
	m_gui.update(m_currentSelect, 3);
}

/// <summary>
/// Draw loop
/// </summary>
/// <param name="window"></param>
void DisplayScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

/// <summary>
/// When the back button is pressed this method wil run
/// It will set the current state back to the options menu
/// </summary>
void DisplayScreen::setStateBack()
{
	m_game->changeGameState(GameState::TheOptions);
}