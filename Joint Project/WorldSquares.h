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
	void mapZero();
	void mapOne();
	void mapTwo();
	void mapThree();

	void addStraight(sf::Vector2f pos , float rotation);
	void addCorner(sf::Vector2f pos , float rotation);
	void addUTurn(sf::Vector2f pos , float rotation);

	void clearTrack();

private: 

	GUI m_gui;
	sf::Texture m_texture;

	


	std::vector<sf::Sprite> m_straightTrack;
	std::vector<sf::Sprite> m_cornerTrack;
	std::vector<sf::Sprite> m_uTurnTrack;

	
	Game *m_game;



	//void mapOne();
};




#endif // !WORLDSQUARES