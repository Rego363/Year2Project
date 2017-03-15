#include "background.h"
#include <iostream>

Background::Background( Game &game):
	m_game(&game)
{
	
	/*m_texture = texture;
	

	m_image = m_texture.copyToImage();
	

	m_sprites[0].setTexture(m_texture);
	m_sprites[0].setTextureRect(sf::IntRect(m_sprites[0].getTextureRect().left, m_sprites[0].getTextureRect().top, m_sprites[0].getTextureRect().width / 2, m_sprites[0].getTextureRect().height));
	m_sprites[0].setPosition(0, 0);
	
	m_sprites[1].setTexture(m_texture);
	m_sprites[1].setPosition(m_sprites[0].getGlobalBounds().width, 0);
	m_sprites[1].setTextureRect(sf::IntRect(m_sprites[0].getGlobalBounds().width, 0, m_sprites[0].getTextureRect().width , m_sprites[0].getTextureRect().height));*/

	loadCounter = sf::Vector2i(0, 0);

	openFile = std::ifstream("Map1.txt");
	if (openFile.is_open())
	{
		std::string tileLocation;
		openFile >> tileLocation;
		m_tileTexture.loadFromFile(tileLocation);
		spr.setTexture(m_tileTexture);

		//m_image = m_tileTexture.copyToImage();

		while (!openFile.eof())
		{
			std::string str;
			openFile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			}
			else
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			}
			if (openFile.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else {
				loadCounter.x++;
			}
		}
		loadCounter.y++;
	}


}

sf::Color Background::getPixelColor(sf::Vector2f pos)
{
		//m_image = tiles.getTexture()->copyToImage();
		return m_image.getPixel(pos.x, pos.y);
}

void Background::draw(sf::RenderWindow &window)
{
	static int visible = 0;

	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j<loadCounter.y; j++)
		{
			spr.setPosition(i * 100, j * 100);
			spr.setTextureRect(sf::IntRect(map[i][j].x * 100, map[i][j].y * 100, 100, 100));
			if (m_game->isInView(spr))
			{
				window.draw(spr);
				visible++;
			}
		}
	}
	std::cout << "Total visible tiles: " << visible << std::endl;
	visible = 0;
	system("cls");

}

