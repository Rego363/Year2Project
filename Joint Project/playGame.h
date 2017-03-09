#pragma once

#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Widget.h"
#include "GUI.h"

class playGame  {


public:
		playGame();
		~playGame();

		void render(sf::RenderWindow & window);
		void update();

private:

	GUI m_gui;
	Label *m_title;
	Button *m_mapSelection;
	Button *moveLeft;
	Button *m_rectB;
	Button *moveRight;
	Button *moveDowner;
	Button *moveDownest;
	sf::Texture m_texture;
	sf::Sprite m_sprite; 
	sf::Texture m_texture2;
	sf::Sprite m_sprite2;
	int m_currentSelect;
	//void setRectColor(sf::Color color);
	sf::RectangleShape m_rect;
	bool maptrue = false;

};