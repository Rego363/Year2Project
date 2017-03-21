#pragma once

#ifndef DISPLAYSCREEN
#define DISPLAYSCREEN

#include "Game.h"

class Game;

class DisplayScreen
{
public:
	DisplayScreen(Game &game);
	~DisplayScreen();
	void update(float time);
	void render(sf::RenderWindow & window);

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;

	//Text animations
	CheckBox *m_animeOn;
	//Slider *m_animeSpeed;

	Button *m_backButton;

	float m_speed;
	int m_currentSelect;
	void setStateBack();
	void animationOn();
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
	std::string fragmentShader;
};

#endif