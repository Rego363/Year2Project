#include "WorldSquares.h"


worldSquares::worldSquares(Game &game):
	m_game(&game)
{

	if (!m_texture.loadFromFile("Road-Tile.png"))
	{
		//handle
	}
	mapZero();
}

worldSquares::~worldSquares()
{
}

void worldSquares::render(sf::RenderWindow & window)
{

	for each (sf::Sprite var in m_cornerTrack)
	{
		window.draw(var);
	}
	
	for each (sf::Sprite var in m_straightTrack)
	{
		window.draw(var);
	}
	for each (sf::Sprite var in m_uTurnTrack)
	{
		window.draw(var);
	}

	m_gui.draw(window);


}


void worldSquares::update()
{

}






void worldSquares::mapZero()
{
	addStraight(sf::Vector2f(250+(500), 425 + (-1400)), 0);
	addStraight(sf::Vector2f(1650 + (500), -80 + (-1400)), 0);
	addStraight(sf::Vector2f(930 + (500), 95 + (-1400)), 90);
	addStraight(sf::Vector2f(1100 + (500), 95 + (-1400)), 90);
	addStraight(sf::Vector2f(1400 + (500), 95 + (-1400)), 90);
	addStraight(sf::Vector2f(1520 + (500), 420 + (-1400)), 90);
	addStraight(sf::Vector2f(1200 + (500), 420 + (-1400)), 90);

	addCorner(sf::Vector2f(250 + (500), 100 + (-1400)), 0);
	addCorner(sf::Vector2f(530 + (500), 420 + (-1400)), 0);
	addCorner(sf::Vector2f(1820 + (500), 590 + (-1400)), 180);
	addCorner(sf::Vector2f(1550 + (500), 260 + (-1400)), 180);

	addUTurn(sf::Vector2f(725 + (500), 750 + (-1400)), 90);
	addUTurn(sf::Vector2f(1350 + (500), -70 + (-1400)), 270);
}

void worldSquares::mapOne()
{
	addStraight(sf::Vector2f(350 + (500), 425 + (-1400)),90);
	addStraight(sf::Vector2f(650 + (500), 425 + (-1400)),90);
	addStraight(sf::Vector2f(950 + (500), 425 + (-1400)),90);
	addStraight(sf::Vector2f(1250 + (500), 425 + (-1400)),90);
	addStraight(sf::Vector2f(1550 + (500), 425 + (-1400)),90);
	addStraight(sf::Vector2f(1850 + (500), 425 + (-1400)),90);
	addStraight(sf::Vector2f(2150 + (500), 425 + (-1400)),90);


}

void worldSquares::addStraight(sf::Vector2f pos,  float rotation)
{
	sf::Sprite sprite;
	sprite.setTexture(m_texture);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(605, 107, 172, 348));
	sprite.setRotation(rotation);
	//sprite.scale(2, 1);
	m_straightTrack.push_back(sprite);

}

void worldSquares::addCorner(sf::Vector2f pos , float rotation)
{
	sf::Sprite sprite;
	sprite.setTexture(m_texture);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(169, 109, 333, 337));
	sprite.setRotation(rotation);
	//sprite.scale(2, 1);
	m_cornerTrack.push_back(sprite);
}

void worldSquares::addUTurn(sf::Vector2f pos,  float rotation)
{
	sf::Sprite sprite;
	sprite.setTexture(m_texture);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(1307, 49, 600, 486));
	sprite.setRotation(rotation);
	//sprite.scale(2, 1);
	m_uTurnTrack.push_back(sprite);
}

void worldSquares::clearTrack()
{
	m_straightTrack.clear();
	m_cornerTrack.clear();
	m_uTurnTrack.clear();
}
