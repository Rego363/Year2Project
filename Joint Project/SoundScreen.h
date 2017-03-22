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
	void increaseMusicVol();
	void decreaseMusicVol();

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;
	RadioButton *m_musicOn;
	Slider *m_musicVolume;


	Button *m_backButton;

	float m_volume;
	int m_currentSelect;
	void setStateBack();
	
};

#endif // !SOUNDSCREEN