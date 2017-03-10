#include "Car.h"

double const DEG_TO_RAD = 3.14 / 180.0f;

Car::Car(sf::Texture const & texture, sf::Vector2f const & pos):
	m_texture(texture), m_position(pos)
{
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setScale(0.10, 0.10);
	m_sprite.setOrigin(m_sprite.getTextureRect().width/2.0, m_sprite.getTextureRect().height / 2.0);
	m_speed = 0;
	m_rotation = 0;
}

void Car::update()
{
	m_sprite.setPosition((m_sprite.getPosition().x + cos(m_rotation*DEG_TO_RAD)*m_speed), (m_sprite.getPosition().y + sin(m_rotation*DEG_TO_RAD)*m_speed));
	m_sprite.setRotation(m_rotation);
}

void Car::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Car::increaseSpeed()
{
	if (m_speed < 5.0)
	{
		m_speed += 0.2;
	}
}

void Car::decreaseSpeed()
{
	if (m_speed > -5.0)
	{
		m_speed -= 0.2;
	}
}

void Car::increaseRotation()
{
	m_rotation += 2;
	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

void Car::decreaseRotation()
{
	m_rotation -= 2;
	if (m_rotation == 0.0)
	{
		m_rotation = 359.0;
	}
}

void Car::setRotation(float rot)
{
	if (m_rotation < rot)
	{
		increaseRotation();
	}
	if (m_rotation > rot)
	{
		decreaseRotation();
	}
}

sf::Vector2f Car::getPos()
{
	return m_position;
}
