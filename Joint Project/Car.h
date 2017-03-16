#pragma once
#include<SFML\Graphics.hpp>
#include<math.h>
#include "Animation.h"
#include "Label.h"
#include <iostream>

/*
Cars to be used by both the player and the Ai racers
*/
class Car {
public:
	
	Car(sf::Texture const &texture, sf::Vector2f const & pos); //constructor
	void update(float dt); //update loop
	void aiUpdate(sf::Vector2f velocity);	// Ai update loop
	void draw(sf::RenderWindow &window); //draw loop
	void increaseSpeed(); //increase cars speed
	void decreaseSpeed(); //decrease cars speed

	void increaseRotation();
	void decreaseRotation(); //turning/rotating car

	void increaseAiRotation();
	void decreaseAiRotation(); //turning/rotating ai car

	void drift(float rotation);
	void setRotation(float rotation);

	sf::Vector2f getPos(); //returns player position
	float getRot(); //returns player rotation
	void slowDown();
	bool isCarMoving();
	void breaks();
	void offTrack();
	void setMaxSpeed(float i);
	void setCurrentTexture(sf::Texture carTex);
	sf::Sprite getSprite() const;
private:
	
	float m_maxSpeed;

	sf::Texture m_texture; //car texture
	sf::Vector2u textureSize;
	sf::Sprite m_sprite; //car sprite
	float m_speed; //speed of car
	float m_rotation; //rotation of car
	sf::Vector2f m_position; //cars position on screen
	bool isMoving;
	float m_acceleration;

	Label *currentPos;


	Animation *animation;

};