#pragma once

#include "Car.h"
#include "ResourceManager.h"

class Levels
{
public:
	Levels(LevelData level, Car & car);
	~Levels();

	void update(float dt);
	void render(sf::RenderWindow & window);
	void loadImages();
	void loadFont();
	LevelData m_currentLevel;
private:
	Car m_currentCar;
	sf::Texture m_background;
	sf::Font m_Font;

};
