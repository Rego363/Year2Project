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
	Background(Game &m_game);
	sf::Color getPixelColor(sf::Vector2f pos);
	void draw(sf::RenderWindow &window);
	void activateTheShader();
	
private:
	

	std::ifstream openFile;

	
	sf::Texture m_tileTexture;
	sf::Sprite spr;
	sf::Image m_image;
	bool isOnTrack;
	bool hitWall;
	sf::Vector2i map[2000][2000];
	sf::Vector2i loadCounter;

	Game *m_game;

	sf::Shader m_shader;
	sf::Shader m_shader2;
	sf::Texture m_texture;
	sf::Sprite m_blankSprite;


	
	static bool activateShader;
	
};
#endif