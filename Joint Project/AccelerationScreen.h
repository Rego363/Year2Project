#pragma once
#ifndef ACCELERATIONSCREEN
#define ACCELERATIONSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

//screen where acceleration of the players car can be upgraded
class AccelerationScreen {
public:
	AccelerationScreen(Game &game); //constructor
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop 
	void goToGarage(); //go to garage gamestate

private:
	sf::Texture m_texture; //car part image
	sf::Sprite m_sprite; //sprite to display on screen
	Label *m_label; //label heading
	Label *m_playerMoney;  //the players balance
	static const int MAX_ITEMS = 4; //number of ui elements
	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem = 0;
	GUI m_gui;
	Game *m_game; //game object
	void smallBuy(); //buy the small upgrade
	void mediumBuy(); //medium upgrade
	void largeBuy(); //large upgrade

	bool m_smallBought;
	bool m_mediumBought;
	bool m_largeBought;
	bool m_smallEquipped;
	bool m_mediumEquipped;
	bool m_largeEquipped;

	const int SMALL_PRICE = 500;
	const int MEDIUM_PRICE = 2500; //prices
	const int LARGE_PRICE = 5000;
};
#endif