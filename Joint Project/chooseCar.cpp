#include "chooseCar.h"

ChooseCar::ChooseCar(Game & game):
	m_game(&game)
{
	m_cars[0] = new Button("Lambo Yellow", 100, 50);
	m_cars[0]->getFocus();
	m_cars[0]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[1] = new Button("Lambo Green", 100, 100);
	m_cars[1]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[2]= new Button("Lambo Blue", 100, 150);
	m_cars[2]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[3] = new Button("Lambo Red", 100, 200);
	m_cars[3]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[4] = new Button("Lambo Grey", 100, 250);
	m_cars[4]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[5] = new Button("Lambo White", 100, 300);
	m_cars[5]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[6] = new Button("Police", 100, 350);
	m_cars[6]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[7] = new Button("Ambulance", 100, 400);
	m_cars[7]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_cars[8] = new Button("Bus", 100, 450);
	m_cars[8]->Enter = std::bind(&ChooseCar::chooseCar, this);
	m_gui.vertical = true;

	for each  (Button* var in m_cars)
	{
		m_gui.addButton(var);
	}

	if (!m_textures[0].loadFromFile("lambo.png"))
	{

	}
	if (!m_textures[1].loadFromFile("greenlambo.png"))
	{

	}
	if (!m_textures[2].loadFromFile("bluelambo.png"))
	{

	}
	if (!m_textures[3].loadFromFile("redlambo.png"))
	{

	}
	if (!m_textures[4].loadFromFile("greylambo.png"))
	{

	}
	if (!m_textures[5].loadFromFile("whitelambo.png"))
	{

	}
	if (!m_textures[6].loadFromFile("police.png"))
	{

	}
	if (!m_textures[7].loadFromFile("ambulance.png"))
	{

	}
	if (!m_textures[8].loadFromFile("bus.png"))
	{

	}
	m_spr.setTexture(m_textures[0]);
	m_spr.setPosition(700, 300);
	m_spr.setOrigin(m_spr.getTextureRect().width / 2.0, m_spr.getTextureRect().height / 2.0);
	m_spr.setRotation(m_rotation);

	
}

void ChooseCar::draw(sf::RenderWindow & window)
{
	m_gui.draw(window);
	window.draw(m_spr);

}

void ChooseCar::update()
{
	m_gui.update(m_selectedItem, 9);
	if (m_cars[0]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[0]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[1]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[1]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[2]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[2]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[3]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[3]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[4]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[4]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[5]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[5]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[6]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[6]);
		m_spr.setScale(1, 1);
	}
	if (m_cars[7]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[7]);
		m_spr.setScale(1.25, 1);
	}
	if (m_cars[8]->checkFocus() == true)
	{
		m_spr.setTexture(m_textures[8]);
		m_spr.setScale(1.5, 1);
		
	}

	m_rotation += 0.5;
	if (m_rotation >= 360)
	{
		m_rotation = 0;
	}
	m_spr.setRotation(m_rotation);

}

sf::Texture ChooseCar::getCar()
{
	return sf::Texture();
}

void ChooseCar::chooseCar()
{
	m_game->m_player->m_car.setTexture(m_textures[m_selectedItem], m_spr.getScale().x, m_spr.getScale().y);
	m_game->changeGameState(GameState::Garage);
}
