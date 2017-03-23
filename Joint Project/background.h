#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#include<iostream>
#include<fstream>
#include<cctype>

#ifndef BACKGROUND
#define BACKGROUND

class Background {

public:
	Background(Game &m_game); //constructor
	void draw(sf::RenderWindow &window); //draw function
	void activateTheShader(); //activate blur shader
	
private:
	

	std::ifstream openFile; //for file reading

	std::string tileLocation; //texture name
	int visible; 
	
	sf::Texture m_tileTexture; //texture
	sf::Sprite spr; //sprite for tiles
	bool isOnTrack; //bool to indicate on track
	bool hitWall; //bool to indicate if wall is hit
	sf::Vector2i map[2000][2000]; //the map size
	sf::Vector2i loadCounter; //the amount of tiles

	Game *m_game; //pointer to game class

	sf::Shader m_shader; 
	sf::Shader m_shader2; //shaders



	
	static bool activateShader; //turn on the blur shader

	sf::RenderTexture m_renderTexture;
	sf::Sprite m_renderSprite;
	sf::Image m_image;
	sf::Color color;
	
};
#endif