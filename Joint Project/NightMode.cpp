#include "NightMode.h"
#include <iostream>



bool NightMode::activateShader = false;

/// <summary>
/// Dylan
/// Nightvision shader
/// Problem - needs to be applied to the window
/// </summary>
/// <param name="game"></param>
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


	sf::Texture& noiseTexture = m_game->m_manager->m_textureHolder["noise"]; //blurryness of nightvision
	sf::Texture& mask = m_game->m_manager->m_textureHolder["mask"]; //goggles effect

	m_shader.setParameter("sceneBuffer", m_tileTexture);
	m_shader.setParameter("noiseTex", noiseTexture);
	m_shader.setParameter("maskTex", mask);
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

			//only draw if the tile is in the windows view
			if (m_game->isInView(spr))
			{
				if (activateShader == true)
				{
					m_shader.setParameter("elapsedTime", elapsedTime.getElapsedTime().asSeconds() * 10 );
					window.draw(spr, &m_shader);
				}
				
			}
		}
	}
}
//flip the bool for activating the shader
void NightMode::activateTheShader()
{
	activateShader = !(activateShader);
}