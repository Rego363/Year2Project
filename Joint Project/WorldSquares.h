#pragma once

#ifndef WORLDSQUARES
#define WORLDSQUARES


class Game;

#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Widget.h"
#include "GUI.h"
#include "ResourceManager.h"


class worldSquares {


public:
	worldSquares(Game &game, LevelData &level);
	~worldSquares();

	void render(sf::RenderWindow& window);
	void update();
	void mapZero();
	void mapOne();
	void mapTwo();
	void mapThree();

private: 

	LevelData *m_currentLevel;
	GUI m_gui;
	sf::Texture m_texture;

	sf::Sprite m_Straight;
	sf::Sprite m_Straight2;

	sf::Sprite m_Flat;
	sf::Sprite m_Flat2;
	sf::Sprite m_Flat3;
	sf::Sprite m_Flat4;
	sf::Sprite m_Flat5;

	//sf::Sprite m_Bend;
	//sf::Sprite m_Bend2;


	sf::Sprite m_Corner;
	sf::Sprite m_Corner2;
	sf::Sprite m_Corner3;
	sf::Sprite m_Corner4;

	sf::Sprite m_Uturn;
	sf::Sprite m_Uturn2;
	//sf::Sprite m_Bend;

	sf::RectangleShape m_StraightRect;
	sf::RectangleShape m_CornerRect;
	sf::RectangleShape m_BendRect;
	sf::RectangleShape m_FlatRect;
	sf::RectangleShape m_UturnRect;
	Game *m_game;



	//void mapOne();
};




#endif // !WORLDSQUARES