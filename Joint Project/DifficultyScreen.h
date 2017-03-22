#pragma once

#ifndef DIFFICULTYSCREEN
#define DIFFICULTYSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

class DifficultyScreen {

public:
	DifficultyScreen(Game &game);
	void render(sf::RenderWindow & window);
	void update(float time);
	void goToOptions();
	void setEasy();
	void setMedium();
	void setHard();
private:
	Game *m_game;
	GUI m_gui;
	static const int MAX_ITEMS = 4;

	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem;

	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect


};
#endif // !DIFFICULTYSCREEN