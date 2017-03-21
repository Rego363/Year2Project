#pragma once

#ifndef CHANGEPROFILE
#define CHANGEPROFILE



class Game;



#include<SFML\Graphics.hpp>
#include<math.h>
#include"Button.h"
#include "GUI.h"
#include"Game.h"


class changeProfile {

public:
	changeProfile(Game &game);
	~changeProfile();

	void render(sf::RenderWindow &  window);
	void update(float time);
private:
	GUI m_gui;
	Button *m_profileOne;
	Button *m_profileTwo;
	Button *m_profileThree;
	Button *m_Back;
	Button *m_Delete;
	Button *m_New;

	Label *m_currentName;
	int m_currentSelect;
	Game *m_game;
	void goToMenu();
//	void goToSpecs();

	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
	std::string fragmentShader;
};

#endif // !CHANGEPROFILE