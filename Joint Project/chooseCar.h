#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include "GUI.h"
#ifndef CHOOSECAR
#define CHOOSECAR

class Game;

class ChooseCar {
public:
	ChooseCar(Game &game);
	void draw(sf::RenderWindow &window);
	void update();
	sf::Texture getCar();
	void chooseCar();

private:
	Game *m_game;
	GUI m_gui;
	int m_selectedItem = 0;
	Button *m_cars[9];
	sf::Texture m_textures[9];
	sf::Sprite m_spr;
	float m_rotation = 0;
};
#endif