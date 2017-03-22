#pragma once
#include<SFML\Graphics.hpp>
#include<math.h>
#include "Animation.h"
#include "Label.h"
#include <iostream>

#ifndef CAR
#define CAR

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

	void turbo(float MaxturboSpeed);
	bool useTurbo = false;

	sf::Vector2f getPos(); //returns player position
	float getRot(); //returns player rotation
	void slowDown();
	bool isCarMoving();
	void breaks();
	void offTrack();
	void setMaxSpeed(float i);
	void setCurrentTexture(sf::Texture carTex);
	void collision();
	void setAiPosition(sf::Vector2f);
	void scaleAi();
	void resetPosition();
	sf::Sprite getSprite() const;
	float m_speed; //speed of car
	float m_rotation; //rotation of car
private:
	
	float m_maxSpeed;
	sf::Clock shaderclock;
	sf::Texture m_texture; //car texture
	sf::Texture m_blankTexture;
	sf::Sprite m_sprite2;
	sf::Vector2u textureSize;
	sf::Sprite m_sprite; //car sprite
	sf::Texture m_blankTexture2;
	sf::Texture m_Icar;
	sf::Sprite m_IcarS;
	sf::Vector2f m_position; //cars position on screen
	bool isMoving;
	float m_acceleration;
	float m_deacceleration;

	Label *currentPos;


	Animation *animation;

	sf::Shader m_shader;
	sf::Shader m_Nshader;
};
#endif