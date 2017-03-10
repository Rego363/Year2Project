#pragma once
#ifndef SPECS
#define SPECS

#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Widget.h"
#include "GUI.h"
#include"Game.h"

class Game;

class specs {

public :

	specs(Game &game);
	~specs();

	void render(sf::RenderWindow & window);
	void update();


private:

	GUI m_gui;
	Label  *m_title;
	Button *m_Enemies;
	Slider *m_EnemiesNo;
	Button *m_Time;
	Button *m_laps;
	Button *m_Back;
	RadioButton *m_3;
	RadioButton *m_5;
	RadioButton *m_7;


	Game *m_game;
	void goToMapSelect();
	int m_currentSelect;

	float m_EnemiesNum;
};
#endif