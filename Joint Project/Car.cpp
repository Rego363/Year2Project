#include "Car.h"

double const DEG_TO_RAD = 3.14 / 180.0f;  //calculation for angle degrees to radians

//constructor for car object
Car::Car(sf::Texture const & texture, sf::Vector2f const & pos):
	m_texture(texture), m_position(pos)
{

	m_position = sf::Vector2f(3755, -2153);
	m_sprite.setTexture(m_texture); //set texture
	m_sprite.setPosition(m_position); //set pos
	m_sprite.setScale(0.10, 0.10); //scale texture down
	m_sprite.setScale(0.05, 0.05); //scale texture down
	m_sprite.setOrigin(m_sprite.getTextureRect().width/1.5, m_sprite.getTextureRect().height / 2.0); //origin set to centre for rotations
	m_sprite.setRotation(-90);
	//m_sprite.setTextureRect(sf::IntRect(m_sprite.getPosition().x, m_sprite.getPosition().y, m_texture.getSize().x, m_texture.getSize().y));

	m_speed = 0; 
	m_rotation = 0;
	m_acceleration = 0.45;
	m_maxSpeed = 10;
	isMoving = false;

	m_rotation = -90;
}

//in this update loop the movement formula is implemented and also the cars rotation is set
void Car::update(float dt)
{
	if (m_speed == 0.0f ||m_speed<0.9 &&m_speed>0.0)
	{
		isMoving = false;
	}
	else
	{
		isMoving = true;
	}
	

	if (isMoving == true)
	{
		m_sprite.setPosition((m_sprite.getPosition().x + cos(m_rotation*DEG_TO_RAD)*m_speed), (m_sprite.getPosition().y + sin(m_rotation*DEG_TO_RAD)*m_speed));   //car movement
		m_sprite.setRotation(m_rotation);  //car rotation 

		if (m_speed < 0.0&& m_speed>-0.99)
		{
			m_speed = 0;
		}
	}

}


void Car::aiUpdate(sf::Vector2f velocity)
{
	m_sprite.setPosition((m_sprite.getPosition().x + velocity.x), (m_sprite.getPosition().y + velocity.y));   //car movement
}


//draw the car to the screen
void Car::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

//when called the speed of the car increases
void Car::increaseSpeed()
{
	if (m_speed < m_maxSpeed)
	{
		m_speed += m_acceleration;
	}
}

//when called the speed of the car decreases
void Car::decreaseSpeed()
{
	if (m_speed > -(m_maxSpeed))
	{
		m_speed -= m_acceleration;
	}
}

//when called the rotation of the car increases
void Car::increaseRotation()
{
	m_rotation += 2;
	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

//when called the rotation of the car decreases
void Car::decreaseRotation()
{
	m_rotation -= 2;
	if (m_rotation == 0.0)
	{
		m_rotation = 359.0;
	}
}

//function to rotate the texture to simulate a drift
void Car::drift(float rotation)
{
	m_sprite.rotate(rotation);
}

void Car::setRotation(float rotation)
{
	m_rotation = m_rotation + rotation;
	m_sprite.setRotation(m_rotation);
}

//return the vector that represents the cars position on screen
sf::Vector2f Car::getPos()
{
	return m_sprite.getPosition();
}

void Car::slowDown()
{
	if(m_speed > 0.0)
	{
		m_speed -= m_acceleration;
	} 
	else if (m_speed < 0.0)
	{
		m_speed += m_acceleration;
	}
	//m_speed = 0;
	
}

bool Car::isCarMoving()
{
	return isMoving;
}

void Car::breaks()
{
	m_speed /= 1.08;
	if (m_speed < 0.0&& m_speed>-0.8)
	{
		m_speed = 0;
	}
}

void Car::setCurrentTexture(sf::Texture carTex)
{
	m_texture = carTex;
	m_sprite.setTexture(m_texture);
}

