#pragma once

#include <SFML\Graphics.hpp>
#include "Car.h"
#include <Thor/Vectors.hpp>
#include "PhysicsBalls.h"

#include "Math.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

class Ai
{
public:
	Ai(Game &game, float carX, float carY, sf::Texture &carTexture, std::vector<sf::CircleShape> & const track);
	~Ai();
	void update();	// Update loop
	void render(sf::RenderWindow &window);	// Draw loop
	void resetNode();

	Car m_car;

private:
	Game *m_game;
	sf::Vector2f trackDisVector;
	sf::Vector2f aiDisVector;
	sf::Vector2f vectorToNode;
	sf::Vector2f m_steering;
	sf::Vector2f m_velocity;
	
	
	sf::Vector2f m_ahead;
	sf::Vector2f m_halfAhead;
	const float MAX_FORCE = 10.0f;
	float MAX_SPEED = 10.0f;
	const float MAX_AVOID_FORCE = 5.0f;
	sf::Vector2f seekTrack(std::vector<sf::CircleShape> track, sf::Vector2f pos);
	const float MAX_SEE_AHEAD = 5.0f;
	int m_target;
	std::vector<sf::CircleShape> & m_track;
	sf::Sprite Ai::findMostThreateningObstacle();
	sf::Vector2f collisionAvoidance();
	/*sf::Vector2f m_ahead;
	sf::Vector2f m_halfAhead;*/
	std::vector<sf::Sprite> m_obstacles;

};

