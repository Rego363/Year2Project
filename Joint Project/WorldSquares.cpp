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

	m_Flat.setTexture(m_texture);
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
	m_Flat5.rotate(90);



	//m_Bend.setTexture(m_texture);
	//m_Bend.setTextureRect(sf::IntRect(433, 571, 280, 410));
	//m_Bend.setPosition(250, 100);
	//m_Bend.rotate(60);

	//m_Bend2.setTexture(m_texture);
	//m_Bend2.setTextureRect(sf::IntRect(433, 571, 280, 410));
	//m_Bend2.setPosition(250, 100);
	////m_Bend2.rotate();


	m_Uturn.setTexture(m_texture);
	m_Uturn.setTextureRect(sf::IntRect(1307, 49, 600, 486));
	m_Uturn.setPosition(600, 100);
	m_Uturn.rotate(90);

	m_Uturn2.setTexture(m_texture);
	m_Uturn2.setTextureRect(sf::IntRect(1307, 49, 600, 486));
	m_Uturn2.setPosition(600, 100);
	m_Uturn2.rotate(270);


	m_Corner2.setTexture(m_texture);
	m_Corner2.setTextureRect(sf::IntRect(169, 109, 333, 337));
	m_Corner2.setPosition(250, 100);

	m_Corner3.setTexture(m_texture);
	m_Corner3.setTextureRect(sf::IntRect(169, 109, 333, 337));
	m_Corner3.setPosition(250, 100);
	m_Corner3.rotate(180);

	m_Corner4.setTexture(m_texture);
	m_Corner4.setTextureRect(sf::IntRect(169, 109, 333, 337));
	m_Corner4.setPosition(250, 100);
	m_Corner4.rotate(180);
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

	window.draw(m_Flat);
	window.draw(m_Flat2);
	window.draw(m_Flat3);
	window.draw(m_Flat4);
	window.draw(m_Flat5);

	//window.draw(m_Bend);
	//window.draw(m_Bend2);
	window.draw(m_Uturn);
	window.draw(m_Uturn2);

	

	m_gui.draw(window);


}


void worldSquares::update()
{

	mapZero();
	

}






void worldSquares::mapZero()
{
	m_Straight.setPosition(250, 425);
	m_Straight2.setPosition(1650, -80);

	m_Corner.setPosition(250, 100);
	m_Corner2.setPosition(530, 420);
	m_Corner3.setPosition(1820, 590);
	m_Corner4.setPosition(1550, 260);

	m_Flat.setPosition(930, 95);
	m_Flat2.setPosition(1100, 95);
	m_Flat3.setPosition(1400, 95);
	m_Flat4.setPosition(1520, 420);
	m_Flat5.setPosition(1200, 420);

	/*m_Bend.setPosition(1250, -120);
	m_Bend2.setPosition(1250, -350);*/
	m_Uturn.setPosition(725, 750);
	m_Uturn2.setPosition(1350, -70);




}

void worldSquares::mapOne()
{



}