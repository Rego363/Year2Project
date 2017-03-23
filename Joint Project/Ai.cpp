#include "Ai.h"



Ai::Ai(Game &game, float carX, float carY, sf::Texture &carTexture, std::vector<sf::CircleShape> & track) :
	m_car(game, carTexture, sf::Vector2f(carX, carY)), 
	m_track(track),
	m_game(&game)
{
	//m_car.setAiPosition(sf::Vector2f(carX, carY));
}


Ai::~Ai()
{
}

void Ai::update()
{
	auto dest = atan2(-1 * m_velocity.y, -1 * m_velocity.x) / 3.14159265359 * 180 + 180;

	auto currentRotation = m_car.getRot();

	// Find the shortest way to rotate towards the player (clockwise or anti-clockwise)
	if (std::round(currentRotation - dest) == 0.0)
	{
		m_steering.x = 0;
		m_steering.y = 0;
	}
	else if ((static_cast<int>(std::round(dest - currentRotation + 360))) % 360 < 180)
	{
		// rotate clockwise
		m_car.increaseAiRotation();

	}
	else
	{
		// rotate anti-clockwise
		m_car.decreaseAiRotation();
	}

	vectorToNode = seekTrack(m_track, m_car.getPos());
	m_steering += thor::unitVector(vectorToNode);
	//m_steering += collisionAvoidance(aiId, entities);
	m_steering = Math::truncate(m_steering, MAX_FORCE);
	m_velocity = Math::truncate(m_velocity + m_steering, MAX_SPEED);

	m_car.aiUpdate(m_velocity);
}

void Ai::render(sf::RenderWindow &window)
{
	m_car.draw(window);
}

void Ai::resetNode()
{
	m_target = 0;
}

sf::Vector2f Ai::seekTrack(std::vector<sf::CircleShape> track, sf::Vector2f pos)
{
	trackDisVector = track[m_target].getPosition();

	aiDisVector = pos;

	
	//	if (track[m_target].getPosition().x - aiDisVector.x < 1 && track[m_target].getPosition().y - aiDisVector.y < 1)
	if (Math::distance(aiDisVector, trackDisVector) < track[m_target].getRadius() + 40)
	{
		m_target++;
	}

	if (m_target >= track.size())
	{
		m_target = 0;
	}

	return sf::Vector2f(trackDisVector.x - aiDisVector.x, trackDisVector.y - aiDisVector.y);
}
