#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#include "Controller.h"

using namespace std;


/// <summary>
/// Game class
/// </summary>
class Game
{
public:

	Game();
	void init();
	void run();

private:
	void processInput();
	void update(sf::Time);
	void render();
	sf::RenderWindow m_window;

	X360Controller controller;

};

#endif
