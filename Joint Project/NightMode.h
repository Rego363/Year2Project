#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#include<iostream>
#include<fstream>
#include<cctype>

#ifndef NIGHTMODE
#define NIGHTMODE

class NightMode {

public:
	NightMode(Game &m_game); //constructor
	void draw(sf::RenderWindow &window); //draw function
	void activateTheShader(); //activate blur shader

private:

	sf::Clock elapsedTime;
	std::ifstream openFile; //for file reading

	std::string tileLocation; //texture name
	int visible;

	sf::Texture m_tileTexture; //texture
	sf::Texture m_noiseTexture; //blurryness of nightvision
	sf::Texture m_mask; //goggles effect
	sf::Sprite spr; //sprite for tiles
	bool isOnTrack; //bool to indicate on track
	bool hitWall; //bool to indicate if wall is hit
	sf::Vector2i map[2000][2000]; //the map size
	sf::Vector2i loadCounter; //the amount of tiles

	Game *m_game; //pointer to game class

	sf::Shader m_shader;

	static bool activateShader; //turn on the blur shader

};
#endif