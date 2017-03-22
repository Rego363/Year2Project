#pragma once
#ifndef ENTERNAME
#define ENTERNAME

#include "Game.h"
#include "GUI.h"
class Game;


class EnterNameScreen {
public:
	EnterNameScreen(Game &game, Player &player);
	std::string getEnteredName();
	void update();
	void draw(sf::RenderWindow &window);

	void addQ();
	void addW();
	void addE();
	void addR();
	void addT();
	void addY();
	void addU();
	void addI();
	void addO();
	void addP();
	void addA();
	void addS();
	void addD();
	void addF();
	void addG();
	void addH();
	void addJ();
	void addK();
	void addL();
	void addZ();
	void addX();
	void addC();
	void addV();
	void addB();
	void addN();
	void addM();
	void addChar();
	void Space();
	void deleteLetter();
	void changeGameState();
private:
	static const int MAX_ITEMS = 30;
	GUI m_gui;
	Widget* m_widgets[MAX_ITEMS];
	Label *m_label;
	std::string m_enteredName;
	int m_selectedItem = 0;
	Game *m_game;
	Player *m_player;
	Xbox360Controller m_xbox;
};
#endif // !ENTERNAME