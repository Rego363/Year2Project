#include "background.h"
#include <iostream>



bool Background::activateShader = false;

Background::Background( Game &game):
	m_game(&game)
{
	
	

	loadCounter = sf::Vector2i(0, 0);

	openFile = std::ifstream("Map1.txt");
	if (openFile.is_open())
	{
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








	/*if (!m_texture.loadFromFile("blankTile.png"))
	{

	}
	m_blankSprite.setTexture(m_texture);*/

	if (!m_shader.loadFromFile("blur.frag", sf::Shader::Fragment))
	{
		std::cout << "shader failed to load" << std::endl;
	}

	//m_shader.setParameter("texture", sf::Shader::CurrentTexture);
	m_shader.setParameter("texture", m_tileTexture);
	m_shader.setParameter("blur_radius", 0.008f);

	if (!m_shader2.loadFromFile("edge.frag", sf::Shader::Fragment))
	{
		std::cout << "shader failed to load" << std::endl;
	}

	//m_shader.setParameter("texture", sf::Shader::CurrentTexture);
	m_shader2.setParameter("texture", m_tileTexture);
	m_shader2.setParameter("edge_threshold", 500);

}

sf::Color Background::getPixelColor(sf::Vector2f pos)
{
		//m_image = tiles.getTexture()->copyToImage();
		return m_image.getPixel(pos.x, pos.y);
}

void Background::draw(sf::RenderWindow &window)
{
	visible = 0;

	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j<loadCounter.y; j++)
		{
			spr.setPosition(i * 200, j * 200);
			//m_blankSprite.setPosition(spr.getPosition());
			spr.setTextureRect(sf::IntRect(map[i][j].x * 225, map[i][j].y * 220, 200, 200));
			//m_blankSprite.setTextureRect(sf::IntRect(map[i][j].x * 200, map[i][j].y * 200, 200, 200));

			if (map[i][j].x == 1 && map[i][j].y == 0)
			{
				isOnTrack = true;
				hitWall = false;
			}
			else if (map[i][j].x == 0 && map[i][j].y == 0)
			{
				isOnTrack = false;
				hitWall = false;
			}
			else if (map[i][j].x == 2 && map[i][j].y == 0)
			{
				hitWall = true;
			}
			

			if (spr.getGlobalBounds().intersects(m_game->m_player->m_car.getSprite().getGlobalBounds())&& isOnTrack==true)
			{
				if (m_game->m_player->m_car.useTurbo == false)
				{
					m_game->m_player->m_car.setMaxSpeed(10);
				}
				else
				{
					m_game->m_player->m_car.setMaxSpeed(20);
				}
			}
			else if (spr.getGlobalBounds().intersects(m_game->m_player->m_car.getSprite().getGlobalBounds()) && isOnTrack == false)
			{
				if (m_game->m_player->m_car.useTurbo == false)
				{
					m_game->m_player->m_car.setMaxSpeed(4);
				}
				else
				{
					m_game->m_player->m_car.setMaxSpeed(10);
				}
			}
			if (spr.getGlobalBounds().intersects(m_game->m_player->m_car.getSprite().getGlobalBounds()) && hitWall == true)
			{
				m_game->m_player->m_car.collision();

			}

			if (m_game->isInView(spr))
			{
				
				//window.draw(spr, &m_shader);
				if (activateShader==true)
				{
					window.draw(spr, &m_shader);
				}
				else {
					window.draw(spr);
				}
				//window.draw(m_blankSprite, &m_shader2);
				
				visible++;
			}
		}
	}
	std::cout << "Total visible tiles: " << visible << std::endl;
	visible = 0;
	system("cls");

}

void Background::activateTheShader()
{
	activateShader = !(activateShader);
}

