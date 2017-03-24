#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	// Textures
	m_textureHolder.acquire("garage", thor::Resources::fromFile<sf::Texture>("./all.png"));
	m_textureHolder.acquire("blueBackground", thor::Resources::fromFile<sf::Texture>("./backgroundBlue.png"));
	m_textureHolder.acquire("blankBackground", thor::Resources::fromFile<sf::Texture>("./blankBackground.png"));
	m_textureHolder.acquire("blankCar", thor::Resources::fromFile<sf::Texture>("./blankNeon.png"));
	m_textureHolder.acquire("skidMark", thor::Resources::fromFile<sf::Texture>("./Skidmark2.png"));
	m_textureHolder.acquire("yellowCar", thor::Resources::fromFile<sf::Texture>("./lambo.png"));
	m_textureHolder.acquire("greenCar", thor::Resources::fromFile<sf::Texture>("./greenlambo.png"));
	m_textureHolder.acquire("blueCar", thor::Resources::fromFile<sf::Texture>("./bluelambo.png"));
	m_textureHolder.acquire("redCar", thor::Resources::fromFile<sf::Texture>("./redlambo.png"));
	m_textureHolder.acquire("greyCar", thor::Resources::fromFile<sf::Texture>("./greylambo.png"));
	m_textureHolder.acquire("whiteCar", thor::Resources::fromFile<sf::Texture>("./whitelambo.png"));
	m_textureHolder.acquire("policeCar", thor::Resources::fromFile<sf::Texture>("./police.png"));
	m_textureHolder.acquire("ambulance", thor::Resources::fromFile<sf::Texture>("./ambulance.png"));
	m_textureHolder.acquire("bus", thor::Resources::fromFile<sf::Texture>("./bus.png"));
	m_textureHolder.acquire("noise", thor::Resources::fromFile<sf::Texture>("./noisetexture.jpg"));
	m_textureHolder.acquire("mask", thor::Resources::fromFile<sf::Texture>("./mask.png"));
	m_textureHolder.acquire("blueBall", thor::Resources::fromFile<sf::Texture>("./blueBall.png"));
	m_textureHolder.acquire("raceBackground", thor::Resources::fromFile<sf::Texture>("./testTiles.png"));
	
	//Fonts
	m_fontHolder.acquire("americanCap", thor::Resources::fromFile<sf::Font>("./Fonts/AmericanCaptain.ttf"));
	//m_fontHolder.acquire("Figurativative", thor::Resources::fromFile<sf::Font>("Figurativative.ttf"));
}

ResourceManager::~ResourceManager()
{
	m_textureHolder.release("Garage");
	m_textureHolder.release("blueBackground");
	m_textureHolder.release("blankBackground");
	m_textureHolder.release("blankCar");
	m_textureHolder.release("skidMark");
	m_textureHolder.release("yellowCar");
	m_textureHolder.release("greenCar");
	m_textureHolder.release("blueCar");
	m_textureHolder.release("redCar");
	m_textureHolder.release("greyCar");
	m_textureHolder.release("whiteCar");
	m_textureHolder.release("policeCar");
	m_textureHolder.release("ambulance");
	m_textureHolder.release("bus");
	m_textureHolder.release("noise");
	m_textureHolder.release("mask");
	m_textureHolder.release("blueBall");
	m_textureHolder.release("raceBackground");
	
	m_fontHolder.release("americanCap");
	//m_fontHolder.release("Figurativative");
}
