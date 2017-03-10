#pragma once

#ifndef WORLDSQUARES
#define WORLDSQUARES


class Game;

#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Widget.h"
#include "GUI.h"
#include"Game.h"


class worldSquares {


public:
	worldSquares(Game &game);
	~worldSquares();

	void render(sf::RenderWindow& window);
	void update();

private: 

	GUI m_gui;
	sf::Texture m_texture;
	sf::Sprite m_Straight;
	sf::Sprite m_Corner;
	sf::Sprite m_Bend;

	sf::RectangleShape m_StraightRect;
	sf::RectangleShape m_CornerRect;
	sf::RectangleShape m_BendRect;
	Game *m_game;

};




#endif // !WORLDSQUARES