#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#ifndef BACKGROUND
#define BACKGROUND
class Background {

public:
	Background(sf::Texture &texture,Game &m_game);
	sf::Color getPixelColor(sf::Vector2f pos);
	void draw(sf::RenderWindow &window);
	sf::Sprite getSprite(int i);
private:
	sf::Sprite m_sprites[2];
	//sf::Sprite m_sprite2;
	sf::Texture m_texture;
	sf::Image m_image;
	sf::Image m_image2;
	sf::Color m_color;
	Game *m_game;
	
};
#endif