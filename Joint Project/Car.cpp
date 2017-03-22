#include "Car.h"

double const DEG_TO_RAD = 3.14 / 180.0f;  //calculation for angle degrees to radians

//constructor for car object
Car::Car(sf::Texture const & texture, sf::Vector2f const & pos):
	m_texture(texture), m_position(pos)
{
	shaderclock.restart();

	if (!m_Nshader.loadFromFile("Neon.frag", sf::Shader::Fragment))
	{
		std::cout << "shader failed to load" << std::endl;         //load shader
	}

	m_Nshader.setParameter("time", shaderclock.getElapsedTime().asSeconds());
	m_Nshader.setParameter("resolution", 50, 70); //set radius variable
	//m_Nshader.setParameter("mouse", m_position);

	m_position = sf::Vector2f(pos.x, pos.y);
	m_sprite.setTexture(m_texture); //set texture
	m_sprite.setPosition(m_position); //set pos

	//m_sprite.setTexture(m_Icar);

	m_sprite.setScale(0.10, 0.10); //scale texture down
	m_sprite.setScale(0.05, 0.05); //scale texture down
	m_sprite.setOrigin(m_sprite.getTextureRect().width/1.5, m_sprite.getTextureRect().height / 2.0); //origin set to centre for rotations


	m_speed = 0; 
	m_rotation = 0;
	m_acceleration = 2.25;
	m_deacceleration = 0.45;
	m_maxSpeed = 200;
	isMoving = false;

	if (!m_blankTexture .loadFromFile("blankNeon.png"))
	{

		std::cout << "sprite failed to load" << std::endl;

	}
	
	m_blankTexture.setSmooth(true);

}

//in this update loop the movement formula is implemented and also the cars rotation is set
void Car::update(float dt)
{
	m_Nshader.setParameter("time", shaderclock.getElapsedTime().asSeconds());
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
	m_sprite.setRotation(m_rotation);  //car rotation 
	
}


//draw the car to the screen
void Car::draw(sf::RenderWindow & window)
{


	//window.draw(m_sprite2, &m_shader);
	window.draw(m_sprite);

	if (useTurbo == true)
	{
		window.draw(m_sprite, &m_Nshader);
	}

	//currentPos->draw(window);
}

//when called the speed of the car increases
void Car::increaseSpeed()
{
	if (m_speed > m_maxSpeed)
	{
		m_speed = m_maxSpeed;
	}
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
		m_speed -= m_deacceleration;
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

//when called the rotation of the car increases
void Car::increaseAiRotation()
{
	
	m_rotation = static_cast<int>((m_rotation) + 5) % 360;
}

//when called the rotation of the car decreases
void Car::decreaseAiRotation()
{
	m_rotation = static_cast<int>((m_rotation) - 5) % 360;
}

//function to rotate the texture to simulate a drift
void Car::drift(float rotation)
{
	m_sprite.rotate(rotation);
}

//set permenant rotation of the car
void Car::setRotation(float rotation)
{
	m_rotation = m_rotation + rotation;
	m_sprite.setRotation(m_rotation);
}

void Car::turbo(float MaxturboSpeed)
{
	if (m_speed > MaxturboSpeed)
	{
		m_speed = m_maxSpeed;
	}
	if (m_speed < MaxturboSpeed)
	{
		m_speed += m_acceleration;
	}

	turboFlame = true;
}

//return the vector that represents the cars position on screen
sf::Vector2f Car::getPos()
{
	return m_sprite.getPosition();
}

//return the vector that represents the cars position on screen
float Car::getRot()
{
	return m_sprite.getRotation();
}

//slows down the car
void Car::slowDown()
{
	if(m_speed > 0.0)
	{
		m_speed -= m_deacceleration;
	} 
	else if (m_speed < 0.0)
	{
		m_speed += m_deacceleration;
	}
	
}

bool Car::isCarMoving()
{
	return isMoving;
}

void Car::breaks()
{
	m_speed *= 0.8;
	if (m_speed < 0.0&& m_speed>-0.8)
	{
		m_speed = 0;
	}
}

void Car::offTrack()
{
	m_speed /= 1.2;
	/*if (m_speed < 0.0&& m_speed>-0.8)
	{
		m_speed = 0;
	}*/

}

//sets max speed
void Car::setMaxSpeed(float i)
{
	m_maxSpeed = i;
}

void Car::setCurrentTexture(sf::Texture carTex)
{
	m_texture = carTex;
	m_sprite.setTexture(m_texture);
}

//Function for when car collides with brick wall
void Car::collision()
{
	m_rotation -= 180;
	m_sprite.setRotation(m_rotation);


}

// sets the ai position on startup
void Car::setAiPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void Car::scaleAi()
{
	m_sprite.scale(2.25, 2.25);
}

void Car::resetPosition()
{
	m_sprite.setPosition(sf::Vector2f(760, 1100));
}

//gets the sprite
sf::Sprite Car::getSprite() const
{
	return m_sprite;
}

