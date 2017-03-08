#pragma once

#ifndef SOUNDSCREEN
#define SOUNDSCREEN

#include "Game.h"

class Game;

class SoundScreen
{
public:
	SoundScreen(Game &game);
	~SoundScreen();
	void render(sf::RenderWindow & window);
	void update();

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;

	// Background
	RadioButton *m_musicOn;
	Slider *m_musicVolume;

	// Sound for when 
	RadioButton *m_soundEffectOn;
	Slider *m_soundEffectVolume;

	// Car engine noises
	RadioButton *m_carSoundOn;
	Slider *m_carSoundVolume;

	Button *m_backButton;

	float m_volume;
	int m_currentSelect;
	void setStateBack();
	
};

#endif // !SOUNDSCREEN