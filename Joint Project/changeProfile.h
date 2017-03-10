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
	void update();
private:
	GUI m_gui;
	Button *m_profileOne;
	Button *m_profileTwo;
	Button *m_profileThree;
	Button *m_Back;
	Button *m_Delete;
	Button *m_New;

	int m_currentSelect;
	Game *m_game;
	void goToMenu();
//	void goToSpecs();

};

#endif // !CHANGEPROFILE