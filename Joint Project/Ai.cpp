#include "Ai.h"



Ai::Ai(float carX, float carY, sf::Texture &carTexture, std::vector<sf::CircleShape> const & track) :
	m_car(carTexture, sf::Vector2f(carX, carY)), 
	m_track(track)
{

}


Ai::~Ai()
{
}

void Ai::update()
{
	sf::Vector2f vectorToNode = seekTrack(m_track, m_car.getPos());
	m_steering += thor::unitVector(vectorToNode);
	//m_steering += collisionAvoidance(aiId, entities);
	m_steering = Math::truncate(m_steering, MAX_FORCE);
	m_velocity = Math::truncate(m_velocity + m_steering, MAX_SPEED);
}

void Ai::render(sf::RenderWindow &window)
{
	m_car.draw(window);
}

sf::Vector2f Ai::seekTrack(std::vector<sf::CircleShape> track, sf::Vector2f pos)
{
	sf::Vector2f trackDisVector = track[m_target].getPosition();

	sf::Vector2f aiDisVector = pos;

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
