#pragma once


#include<SFML\Graphics.hpp>
#include<math.h>

class Car {
public:
	
	Car(sf::Texture const &texture, sf::Vector2f const & pos);
	void update();
	void draw(sf::RenderWindow &window);
	void increaseSpeed();
	void decreaseSpeed();

	void increaseRotation();
	void decreaseRotation();
	void setRotation(float rot);

	sf::Vector2f getPos();
private:
	
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_speed;
	float m_rotation;
	sf::Vector2f m_position;
	//double static const DEG_TO_RAD = 3.14f / 180.0f;

};