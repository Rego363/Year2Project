#include "SoundScreen.h"


/// <summary>
/// Constructor
/// </summary>
/// <param name="game"></param>
SoundScreen::SoundScreen(Game & game) :
	m_game(&game)
{
	m_volume = 100.0f;
	m_title = new Label("Sound", 475, 50);
	m_title->changeTextSize(100);

	m_musicOn = new RadioButton("Music On/Off", 50, 150, "music");
	m_musicOn->getFocus();
	m_musicVolume = new Slider(75.0f, 225.0f, m_volume, "Music volume");

	m_soundEffectOn = new RadioButton("Sound effects On/Off", 50, 300, "effects");
	m_soundEffectVolume = new Slider(75.0f, 375.0f, m_volume, "Sound effects volume");

	m_carSoundOn = new RadioButton("Car sounds On/Off", 50, 450, "Car");
	m_carSoundVolume = new Slider(75.0f, 525.0f, m_volume, "Car sounds volume");

	m_backButton = new Button("Back", 50, 600);
	m_backButton->Enter= std::bind(&SoundScreen::setStateBack, this);
	
	m_gui.addLabel(m_title);
	m_gui.addRadioButton(m_musicOn);
	m_gui.addSlider(m_musicVolume);
	m_gui.addRadioButton(m_soundEffectOn);
	m_gui.addSlider(m_soundEffectVolume);
	m_gui.addRadioButton(m_carSoundOn);
	m_gui.addSlider(m_carSoundVolume);
	m_gui.addButton(m_backButton);
	m_currentSelect = 0;
	m_gui.vertical = true;
	
}

/// <summary>
/// Deconstructor
/// </summary>
SoundScreen::~SoundScreen()
{
}

/// <summary>
/// Update loop
/// </summary>
void SoundScreen::update()
{
	m_gui.update(m_currentSelect, 7);
}

/// <summary>
/// Draw loop
/// </summary>
/// <param name="window"></param>
void SoundScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

/// <summary>
/// When the back button is pressed this method will run
/// It will set the current state back to the options menu
/// </summary>
void SoundScreen::setStateBack()
{
	m_game->changeGameState(GameState::TheOptions);
}