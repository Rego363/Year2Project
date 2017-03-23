#pragma once
#ifndef PHISICSBALLS
#define PHYSICSBALLS

#include "Game.h"

class Game;

/// <summary>
/// Class to create physics balls
/// Dylan.
/// </summary>
class PhysicsBalls
{
public:
	PhysicsBalls(Game &game);
	~PhysicsBalls();

	void update();
	void render(sf::RenderWindow &window);
	void collision();
	std::vector<sf::Sprite> m_ballSprite;

private:
	Game *m_game;
	sf::Vector2f m_velocity;
	sf::Vector2f m_Position;

	bool m_collision;

};

#endif