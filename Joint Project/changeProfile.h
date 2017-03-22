#pragma once

#ifndef CHANGEPROFILE
#define CHANGEPROFILE

class Game;

#include<SFML\Graphics.hpp>
#include<math.h>
#include"Button.h"
#include "GUI.h"
#include"Game.h"
#include <fstream>

class changeProfile {

public:
	changeProfile(Game &game, Player &player);
	~changeProfile();
	void render(sf::RenderWindow &  window);
	void update(float time);
	void getProfileName();

private:

	std::string filename;
	std::ifstream fileInput;
	std::string fileLine;

	GUI m_gui;
	Button *m_profileOne;
	Button *m_profileTwo;
	Button *m_profileThree;
	Button *m_profileFour;
	Button *m_profileFive;
	Button *m_profileSix;
	Button *m_profileSeven;
	Button *m_profileEight;
	Button *m_profileNine;
	Button *m_profileTen;
	Button *m_Back;
	Button *m_Save;
	Button *m_New;

	Label *m_currentName;
	int m_currentSelect;
	Game *m_game;
	Player *m_player;
	void goToMenu();
	void save();
	void goToNewProfile();
	void loadFirstProfile();
	void loadSecondProfile();
	void loadThirdProfile();
	void loadFourthProfile();
	void loadFifthProfile();
	void loadSixthProfile();
	void loadSeventhProfile();
	void loadEighthProfile();
	void loadNinethProfile();
	void loadTenProfile();
//	void goToSpecs();
	std::string m_playerNames[10];
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
};

#endif // !CHANGEPROFILE