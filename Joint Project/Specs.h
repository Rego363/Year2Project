#pragma once
#ifndef SPECS
#define SPECS

#include<SFML\Graphics.hpp>
#include"Button.h"
#include "Widget.h"
#include "GUI.h"
#include "Game.h"
#include "levels.h"

class Game;
class Levels;

class specs {

public :

	specs(Game &game, Levels &level);
	~specs();

	void render(sf::RenderWindow & window);
	void update(float time);


private:

	GUI m_gui;
	Label  *m_title;
	Button *m_Enemies;
	Button *m_Race;
	Slider *m_EnemiesNo;
	Button *m_Time;
	Button *m_laps;
	Button *m_Back;
	RadioButton *m_3;
	RadioButton *m_5;
	RadioButton *m_7;


	Game *m_game;
	Levels *m_currentLevel;
	void goToMapSelect();
	void goToMapRacing();
	int m_currentSelect;

	float m_EnemiesNum;
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
	std::string fragmentShader;
};
#endif