#include "Ai.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>



Ai::Ai(Game &game, float carX, float carY, sf::Texture &carTexture, std::vector<sf::CircleShape> & const track) :
	m_game(&game),
	m_car(game, carTexture, sf::Vector2f(carX, carY)), 
	m_track(track)
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
	//m_steering += collisionAvoidance();
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


///method created for Ai to avoid crashing into obstacles 
sf::Vector2f Ai::collisionAvoidance()
{

	sf::Vector2f avoidence(0, 0);

	auto headingRadians = thor::toRadian(m_car.getRot());
	sf::Vector2f headingVector(std::cos(headingRadians) * MAX_SEE_AHEAD, std::sin(headingRadians) * MAX_SEE_AHEAD);
	m_ahead = m_car.getPos() + headingVector;
	m_halfAhead = m_car.getPos() + (headingVector * 0.5f);

	sf::Sprite mostThreatening = findMostThreateningObstacle();
	sf::Vector2f avoidance(0, 0);

	if (Math::distance(m_car.getPos(), mostThreatening.getPosition()) <= Math::distance(m_car.getPos(), mostThreatening.getPosition()))
	{
		auto threatPos = mostThreatening.getPosition();
		auto mypos = m_car.getPos();
		avoidance.x = m_ahead.x - mostThreatening.getPosition().x;
		avoidance.y = m_ahead.y - mostThreatening.getPosition().y;
		avoidance = thor::unitVector(avoidance);
		avoidance *= MAX_AVOID_FORCE;
	}
	else
	{
		avoidance *= 0.0f;
	}
	return avoidance;



}
//Finds the closest obatacle to the car 
sf::Sprite Ai::findMostThreateningObstacle()
{
	
	m_obstacles = m_game->m_physicsBalls->m_ballSprite;
		int size = m_obstacles.size();
		sf::Sprite closest;

		for (int i = 0; i < size; i++)
		{
			if (Math::distance(m_car.getPos(), m_obstacles.at(i).getPosition()) <= Math::distance(m_car.getPos(), closest.getPosition()))
			{

				closest = m_obstacles[i];
			}
		}
		return closest;
	
}
