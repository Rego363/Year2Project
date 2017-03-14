#pragma once
#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Widget.h"
#include "GUI.h"
#include "ResourceManager.h"
#include "Game.h"
#ifndef WORLDSQUARES
#define WORLDSQUARES


class Game;




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

	void addStraight(sf::Vector2f pos , float rotation);
	void addCorner(sf::Vector2f pos , float rotation);
	void addUTurn(sf::Vector2f pos , float rotation);

	void clearTrack();

private: 

	LevelData *m_currentLevel;
	GUI m_gui;
	sf::Texture m_texture;

	std::vector<sf::Sprite> m_straightTrack;
	std::vector<sf::Sprite> m_cornerTrack;
	std::vector<sf::Sprite> m_uTurnTrack;

	Game *m_game;

	/*void mapOne();*/
};




#endif // !WORLDSQUARES