#pragma once
#ifndef STEERINGSCREEN
#define STEERINGSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

class SteeringScreen {
public:
	SteeringScreen(Game &game);
	void draw(sf::RenderWindow &window);
	void update(float time);

	void goToGarage();
private:

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Label *m_label;
	Label *m_playerMoney;
	static const int MAX_ITEMS = 4;
	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem = 0;
	GUI m_gui;
	Game *m_game;
	void smallBuy();
	void mediumBuy();
	void largeBuy();
	bool m_smallBought;
	bool m_mediumBought;
	bool m_largeBought;
	bool m_smallEquipped;
	bool m_mediumEquipped;
	bool m_largeEquipped;
	const int SMALL_PRICE = 500;
	const int MEDIUM_PRICE = 2500;
	const int LARGE_PRICE = 5000;
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
	std::string fragmentShader;
};
#endif