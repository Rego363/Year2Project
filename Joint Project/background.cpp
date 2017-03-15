#include "background.h"
#include <iostream>

Background::Background(sf::Texture &texture, Game &game):
	m_game(&game)
{
	
	m_texture = texture;
	

	m_image = m_texture.copyToImage();
	

	m_sprites[0].setTexture(m_texture);
	m_sprites[0].setTextureRect(sf::IntRect(m_sprites[0].getTextureRect().left, m_sprites[0].getTextureRect().top, m_sprites[0].getTextureRect().width / 2, m_sprites[0].getTextureRect().height));
	m_sprites[0].setPosition(0, 0);
	
	m_sprites[1].setTexture(m_texture);
	m_sprites[1].setPosition(m_sprites[0].getGlobalBounds().width, 0);
	m_sprites[1].setTextureRect(sf::IntRect(m_sprites[0].getGlobalBounds().width, 0, m_sprites[0].getTextureRect().width , m_sprites[0].getTextureRect().height));



}

sf::Color Background::getPixelColor(sf::Vector2f pos)
{
	return m_image.getPixel(pos.x, pos.y);
}

void Background::draw(sf::RenderWindow &window)
{
	static int visible = 0;
	for (int i = 0; i < 2; i++)
	{
		if (m_game->isInView(m_sprites[i]))
		{
			window.draw(m_sprites[i]);
			visible++;
		}
	}
	std::cout << "Total visible tiles: " << visible << std::endl;
	visible = 0;
	system("cls");
}

sf::Sprite Background::getSprite(int i)
{
	return m_sprites[i];
}
