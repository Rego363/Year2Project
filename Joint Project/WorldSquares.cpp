#include "WorldSquares.h"


worldSquares::worldSquares(Game &game):
	m_game(&game)
{



	if (!m_texture.loadFromFile("Capture.JPG"))
	{
		//handle
	}
	m_Straight.setTexture(m_texture);
	m_Straight.setTextureRect(sf::IntRect(605, 107, 172, 348));

}

worldSquares::~worldSquares()
{
}

void worldSquares::render(sf::RenderWindow & window)
{



	//window.draw(m_rect);


	m_gui.draw(window);


}


void worldSquares::update()
{






}