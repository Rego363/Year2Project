#pragma once
#include<SFML\Graphics.hpp>
#include<math.h>


/*
Cars to be used by both the player and the Ai racers
*/
class Car {
public:
	
	Car(sf::Texture const &texture, sf::Vector2f const & pos); //constructor
	void update(); //update loop
	void draw(sf::RenderWindow &window); //draw loop
	void increaseSpeed(); //increase cars speed
	void decreaseSpeed(); //decrease cars speed

	void increaseRotation(); 
	void decreaseRotation(); //turning/rotating car


	sf::Vector2f getPos(); //returns player position
	void slowDown();
	bool isCarMoving();
	void breaks();
private:
	
	float m_maxSpeed;

	sf::Texture m_texture; //car texture
	sf::Sprite m_sprite; //car sprite
	float m_speed; //speed of car
	float m_rotation; //rotation of car
	sf::Vector2f m_position; //cars position on screen
	bool isMoving;
	float m_acceleration;

};