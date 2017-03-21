#pragma once
#ifndef GARAGESCREEN
#define GARAGESCREEN

#include"GUI.h"
#include"Game.h"



//Garage is where upgrades and customisation on the players car is done
class GarageScreen {
public:
	GarageScreen(float x, float y, Game& game); //constructor
	void update(float time); //update loop
	void draw(sf::RenderWindow &window); //draw loop 
	void goBack();   //go to gamestate menu
	void goAccel();	 //go to gamestate acceleration
	void goTurbo();	 //go to gamestate turbo
	void goBrake();	 //go to gamestate braking
	void goSpeed();	 //go to gamestate speed
	void goSteer();	 //go to gamestate steering

private:
	int m_selectedItem = 0;
	static const int MAX_ITEMS = 6;
	Widget* m_widgets[MAX_ITEMS];
	Label* m_label;
	GUI m_gui;
	Game *m_game;
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
	std::string fragmentShader;

};
#endif // !GARAGESCREEN