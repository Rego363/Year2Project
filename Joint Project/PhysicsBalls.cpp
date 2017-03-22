#include "PhysicsBalls.h"

PhysicsBalls::PhysicsBalls(Game &game) : m_game(&game)
{
	m_ball.setFillColor(sf::Color(sf::Color::Blue));
	m_ball.setRadius(20);
	m_ball.setPosition(850, 1150);
}

PhysicsBalls::~PhysicsBalls()
{
}

void PhysicsBalls::update()
{
	
}

void PhysicsBalls::render(sf::RenderWindow &window)
{
	window.draw(m_ball);
}

void PhysicsBalls::collision()
{
}
