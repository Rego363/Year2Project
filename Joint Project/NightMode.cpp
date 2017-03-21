#include "NightMode.h"
#include <iostream>



bool NightMode::activateShader = false;

//constructor
NightMode::NightMode(Game &game) :
	m_game(&game)
{

	elapsedTime.restart();
	loadCounter = sf::Vector2i(0, 0);

	openFile = std::ifstream("Map1.txt"); //file with the tile coords
	if (openFile.is_open())
	{
		openFile >> tileLocation;
		m_tileTexture.loadFromFile(tileLocation); //load texture from file

		spr.setTexture(m_tileTexture); //set texture for the sprite

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
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0'); //minus ascii value of 0
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

	if (!m_shader.loadFromFile("nightVision.frag", sf::Shader::Fragment))
	{
		std::cout << "frag shader failed to load" << std::endl;         //load shader
	}

	if (!m_noiseTexture.loadFromFile("noisetexture.jpg"))
	{
		std::cout << "noise failed to load" << std::endl;         //load shader
	}

	if (!m_mask.loadFromFile("mask.png"))
	{
		std::cout << "mask failed to load" << std::endl;         //load shader
	}

	m_shader.setParameter("sceneBuffer",m_tileTexture);
	m_shader.setParameter("noiseTex", m_noiseTexture);
	m_shader.setParameter("maskTex", m_mask);
	m_shader.setParameter("elapsedTime", elapsedTime.getElapsedTime().asSeconds());
	m_shader.setParameter("luminanceThreshold", 0.2);
	m_shader.setParameter("colorAmplification", 4.0);
	m_shader.setParameter("effectCoverage", 1.0);
}


//draw function where the texture to be drawn is set 
void NightMode::draw(sf::RenderWindow &window)
{
	visible = 0; //amount of tiles visible on screen

	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j<loadCounter.y; j++)
		{
			spr.setPosition(i * 200, j * 200); //set position of each tile
			spr.setTextureRect(sf::IntRect(map[i][j].x * 225, map[i][j].y * 220, 200, 200)); //texture rectangle

																							 //if its the road texture 
			if (map[i][j].x == 1 && map[i][j].y == 0)
			{
				isOnTrack = true;
				hitWall = false;
			}
			//if its the grass texture
			else if (map[i][j].x == 0 && map[i][j].y == 0)
			{
				isOnTrack = false;
				hitWall = false;
			}
			//if its the brick texture
			else if (map[i][j].x == 2 && map[i][j].y == 0)
			{
				hitWall = true;
			}

			//full speed if on road
			if (spr.getGlobalBounds().intersects(m_game->m_player->m_car.getSprite().getGlobalBounds()) && isOnTrack == true)
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
			//slow down if on grass
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
			//collision occurs with bricks
			if (spr.getGlobalBounds().intersects(m_game->m_player->m_car.getSprite().getGlobalBounds()) && hitWall == true)
			{
				m_game->m_player->m_car.collision();

			}

			//only draw if the tile is in the windows view
			if (m_game->isInView(spr))
			{
				if (activateShader == true)
				{
					m_shader.setParameter("elapsedTime", elapsedTime.getElapsedTime().asSeconds() * 10 );
					window.draw(spr, &m_shader);
				}
				else {
					window.draw(spr);
				}
				visible++;
			}
		}
	}
	std::cout << "Total visible tiles: " << visible << std::endl;
	visible = 0;
	system("cls");

}
//flip the bool for activating the shader
void NightMode::activateTheShader()
{
	activateShader = !(activateShader);
}