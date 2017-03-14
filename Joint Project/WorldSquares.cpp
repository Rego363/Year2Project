#include "WorldSquares.h"


worldSquares::worldSquares(Game &game, LevelData &level):
	m_game(&game),
	m_currentLevel(&level)
{
	if (!m_texture.loadFromFile(m_currentLevel->m_Tiles.m_fileName))
	{
		std::cout << "failed to load tile Texture" << std::endl;
	}


	

	m_Straight.setTexture(m_texture);
	m_Straight.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Straight.setPosition(150, 200);
//	m_Straight.setScale(5,5);

	m_Straight2.setTexture(m_texture);
	m_Straight2.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Straight2.setPosition(150, 200);

	m_Corner.setTexture(m_texture);
	m_Corner.setTextureRect(sf::IntRect(169, 109, 333, 337));
	m_Corner.setPosition(250, 100);


	for (int i = 0; i < flat[i]; i++)
	{
		m_Flat[i].setTexture(m_texture);
		m_Flat[i].setTextureRect(sf::IntRect(605, 107, 172, 348));
		m_Flat[i].setPosition(250, 100);
		m_Flat[i].rotate(90);


	}


	/*m_Flat.setTexture(m_texture);
	m_Flat.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Flat.setPosition(250, 100);
	m_Flat.rotate(90);

	m_Flat2.setTexture(m_texture);
	m_Flat2.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Flat2.setPosition(250, 100);
	m_Flat2.rotate(90);

	m_Flat3.setTexture(m_texture);
	m_Flat3.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Flat3.setPosition(250, 100);
	m_Flat3.rotate(90);

	m_Flat4.setTexture(m_texture);
	m_Flat4.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Flat4.setPosition(250, 100);
	 m_Flat4.rotate(90);

	m_Flat5.setTexture(m_texture);
	m_Flat5.setTextureRect(sf::IntRect(605, 107, 172, 348));
	m_Flat5.setPosition(250, 100);
	m_Flat5.rotate(90);*/





//	m_Straight.setTexture(m_texture);
//	m_Straight.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Straight.setPosition(150, 200);
////	m_Straight.setScale(5,5);
//
//	m_Straight2.setTexture(m_texture);
//	m_Straight2.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Straight2.setPosition(150, 200);
//
//	m_Corner.setTexture(m_texture);
//	m_Corner.setTextureRect(sf::IntRect(169, 109, 333, 337));
//	m_Corner.setPosition(250, 100);
//
//	m_Flat.setTexture(m_texture);
//	m_Flat.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Flat.setPosition(250, 100);
//	m_Flat.rotate(90);
//
//	m_Flat2.setTexture(m_texture);
//	m_Flat2.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Flat2.setPosition(250, 100);
//	m_Flat2.rotate(90);
//
//	m_Flat3.setTexture(m_texture);
//	m_Flat3.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Flat3.setPosition(250, 100);
//	m_Flat3.rotate(90);
//
//	m_Flat4.setTexture(m_texture);
//	m_Flat4.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Flat4.setPosition(250, 100);
//	 m_Flat4.rotate(90);
//
//	m_Flat5.setTexture(m_texture);
//	m_Flat5.setTextureRect(sf::IntRect(605, 107, 172, 348));
//	m_Flat5.setPosition(250, 100);
//	m_Flat5.rotate(90);
//
//
//
//	//m_Bend.setTexture(m_texture);
//	//m_Bend.setTextureRect(sf::IntRect(433, 571, 280, 410));
//	//m_Bend.setPosition(250, 100);
//	//m_Bend.rotate(60);
//
//	//m_Bend2.setTexture(m_texture);
//	//m_Bend2.setTextureRect(sf::IntRect(433, 571, 280, 410));
//	//m_Bend2.setPosition(250, 100);
//	////m_Bend2.rotate();
//
//
//	m_Uturn.setTexture(m_texture);
//	m_Uturn.setTextureRect(sf::IntRect(1307, 49, 600, 486));
//	m_Uturn.setPosition(600, 100);
//	m_Uturn.rotate(90);
//
//	m_Uturn2.setTexture(m_texture);
//	m_Uturn2.setTextureRect(sf::IntRect(1307, 49, 600, 486));
//	m_Uturn2.setPosition(600, 100);
//	m_Uturn2.rotate(270);
//
//
//	m_Corner2.setTexture(m_texture);
//	m_Corner2.setTextureRect(sf::IntRect(169, 109, 333, 337));
//	m_Corner2.setPosition(250, 100);
//
//	m_Corner3.setTexture(m_texture);
//	m_Corner3.setTextureRect(sf::IntRect(169, 109, 333, 337));
//	m_Corner3.setPosition(250, 100);
//	m_Corner3.rotate(180);
//
//	m_Corner4.setTexture(m_texture);
//	m_Corner4.setTextureRect(sf::IntRect(169, 109, 333, 337));
//	m_Corner4.setPosition(250, 100);
//	m_Corner4.rotate(180);


	mapZero();
}

worldSquares::~worldSquares()
{
}

void worldSquares::render(sf::RenderWindow & window)
{




	//window.draw(m_rect);
	window.draw(m_Straight);
	window.draw(m_Straight2);

	window.draw(m_Corner);
	window.draw(m_Corner2);
	window.draw(m_Corner3);
	window.draw(m_Corner4);


	for (int i = 0; i < flat[i]; i++)
	{

		window.draw(m_Flat[i]);
	}
	window.draw(m_Flat2);
	window.draw(m_Flat3);
	window.draw(m_Flat4);
	window.draw(m_Flat5);

	//window.draw(m_Bend);
	//window.draw(m_Bend2);
	window.draw(m_Uturn);
	window.draw(m_Uturn2);


	for each (sf::Sprite var in m_cornerTrack)
	{
		if (m_game->isInView(var))
		{
			window.draw(var);
		}
	}

	
	for each (sf::Sprite var in m_straightTrack)
	{
		if (m_game->isInView(var))
		{
			window.draw(var);
		}
	}
	for each (sf::Sprite var in m_uTurnTrack)
	{
		if (m_game->isInView(var))
		{
			window.draw(var);
		}
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
	addStraight(sf::Vector2f(2300 + (500), -400 + (-1400)), 90);
	addStraight(sf::Vector2f(2600 + (500), -400 + (-1400)), 90);
	addStraight(sf::Vector2f(2800 + (500), -400 + (-1400)), 90);
	addStraight(sf::Vector2f(3000 + (500), -400 + (-1400)), 90);
	addStraight(sf::Vector2f(2750 + (500), -1835 + (-1400)), 90);
	addStraight(sf::Vector2f(3050 + (500), -1835 + (-1400)), 90);
	addStraight(sf::Vector2f(3130 + (500), -1535 + (-1400)), 0);
	addStraight(sf::Vector2f(3130 + (500), -1200 + (-1400)), 0);
	addStraight(sf::Vector2f(3130 + (500), -860 + (-1400)), 0);


	m_Corner.setPosition(250, 100);
	m_Corner2.setPosition(530, 420);
	m_Corner3.setPosition(1820, 590);
	m_Corner4.setPosition(1550, 260);
//	for(int i = 0; i  )
	m_Flat[1].setPosition(930, 95);
	m_Flat[2].setPosition(1100, 95);
	m_Flat[3].setPosition(1400, 95);
	m_Flat[4].setPosition(1520, 420);
	m_Flat[5].setPosition(1200, 420);

	addStraight(sf::Vector2f(900 + (500), -600 + (-1400)), 0); // out of place
	addStraight(sf::Vector2f(900 + (500), -900 + (-1400)), 0);      //
	addStraight(sf::Vector2f(1850 + (500), -715 + (-1400)), 90);	//    DO NOT TOUCH
	addStraight(sf::Vector2f(2190 + (500), -715 + (-1400)), 90);    //  
	addStraight(sf::Vector2f(2500 + (500), -715 + (-1400)), 90);


	addCorner(sf::Vector2f(250 + (500), 100 + (-1400)), 0);
	addCorner(sf::Vector2f(530 + (500), 420 + (-1400)), 0);
	addCorner(sf::Vector2f(1820 + (500), 590 + (-1400)), 180);
	addCorner(sf::Vector2f(1550 + (500), 260 + (-1400)), 180);
	addCorner(sf::Vector2f(1550 + (500), -200 + (-1400)), 90 );
	addCorner(sf::Vector2f(900 + (500), -30 + (-1400)), 270 );
	addCorner(sf::Vector2f(1190 + (500), -500 + (-1440)), 270);
	addCorner(sf::Vector2f(1650 + (500), -360 + (-1440)), 0);
	addCorner(sf::Vector2f(3300 + (500), -190 + (-1440)), 180);
	addCorner(sf::Vector2f(3300 + (500), -1800 + (-1440)), 90);



	addUTurn(sf::Vector2f(725 + (500), 750 + (-1400)), 90);
	addUTurn(sf::Vector2f(880 + (500), -850 + (-1400)), 270);
	addUTurn(sf::Vector2f(2390 + (500), -1020 + (-1400)), 0);
	addUTurn(sf::Vector2f(2500 + (500), -800 + (-1400)), 180);
	addUTurn(sf::Vector2f(2450 + (500), -1580 + (-1400)), 0);
	addUTurn(sf::Vector2f(2500 + (500), -1360 + (-1400)), 180);
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
