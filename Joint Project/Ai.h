#pragma once
#include <SFML\Graphics.hpp>
#include "Car.h"
#include <Thor/Vectors.hpp>
#include "Math.h"

class Ai
{
public:
	Ai(float carX, float carY, sf::Texture &carTexture, std::vector<sf::CircleShape> const & track);
	~Ai();
	void update();	// Update loop
	void render(sf::RenderWindow &window);	// Draw loop

private:
	Car m_car;
	sf::Vector2f m_steering;
	sf::Vector2f m_velocity;
	sf::Vector2f m_ahead;
	sf::Vector2f m_halfAhead;
	const float MAX_FORCE = 10.0f;
	float MAX_SPEED = 50.0f;
	sf::Vector2f seekTrack(std::vector<sf::CircleShape> track, sf::Vector2f pos);
	const float MAX_SEE_AHEAD = 50.0f;
	int m_target;
	std::vector<sf::CircleShape> const & m_track;
};
