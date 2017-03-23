#include "AccelerationScreen.h"

//construct the screen
AccelerationScreen::AccelerationScreen(Game & game):
	m_game(&game)
{
	sf::Texture& texture = m_game->m_manager->m_textureHolder["garage"];
	m_sprite.setTexture(texture);
	
	m_sprite.setTextureRect(sf::IntRect(1113, 764, 146, 145));
	m_sprite.setPosition(600, 300);

	//setup widgets
	m_label = new Label("Acceleration", 100, 50);
	m_label->setUnderLined();
	m_label->changeTextSize(70);
	m_gui.addLabel(m_label);
	m_playerMoney = new Label("Money: ", 750, 50);
	m_playerMoney->setUnderLined();
	m_playerMoney->changeTextSize(30);
	m_gui.addLabel(m_playerMoney);
	m_widgets[0] = new Button("Small (500)", 100, 150);
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&AccelerationScreen::smallBuy, this);
	m_widgets[1] = new Button("Medium (2500)", 100, 250);
	m_widgets[1]->Enter = std::bind(&AccelerationScreen::mediumBuy, this);
	m_widgets[2] = new Button("Large (5000)", 100, 350);
	m_widgets[2]->Enter = std::bind(&AccelerationScreen::largeBuy, this);
	m_widgets[3] = new Button("Back", 100, 450);
	m_widgets[3]->Enter = std::bind(&AccelerationScreen::goToGarage, this); //bind the functions

	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);  //put the widgets in the gui object
	}
	m_gui.vertical = true;
}

//draw the assets & Gui to the screen
void AccelerationScreen::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
	m_gui.draw(window);
}

//update the gui and the players balance
void AccelerationScreen::update()
{
	m_playerMoney->updateText("Money: " + std::to_string(m_game->playerMoney()));
	m_gui.update(m_selectedItem, MAX_ITEMS);
}

//for purchasing small upgrade, charge applied and money removed from the player
void AccelerationScreen::smallBuy()
{
	if (m_game->playerMoney() >= SMALL_PRICE && !m_smallBought)
	{
		m_smallBought = true;
		m_game->chargePlayer(SMALL_PRICE);
	}

	if (m_smallBought)
	{
		m_smallEquipped = true;
		m_mediumEquipped = false;
		m_largeEquipped = false;
		m_sprite.setScale(1.25, 1.25);
	}
	currentUpgrade();
}
//for purchasing medium upgrade, charge applied and money removed from the player
void AccelerationScreen::mediumBuy()
{
	if (m_game->playerMoney() >= MEDIUM_PRICE && !m_mediumBought)
	{
		m_mediumBought = true;
		m_game->chargePlayer(MEDIUM_PRICE);
	}

	if (m_mediumBought)
	{
		m_smallEquipped = false;
		m_mediumEquipped = true;
		m_largeEquipped = false;
		m_sprite.setScale(1.5, 1.5);
	}
	currentUpgrade();
}
//for purchasing large upgrade, charge applied and money removed from the player
void AccelerationScreen::largeBuy()
{
	if (m_game->playerMoney() >= LARGE_PRICE && !m_largeBought)
	{
		m_largeBought = true;
		m_game->chargePlayer(LARGE_PRICE);
	}

	if (m_largeBought)
	{
		m_smallEquipped = false;
		m_mediumEquipped = false;
		m_largeEquipped = true;
		m_sprite.setScale(1.75, 1.75);
	}
	currentUpgrade();
}
//change the gamestate to garage
void AccelerationScreen::goToGarage()
{
	m_game->changeGameState(GameState::Garage);
}

void AccelerationScreen::currentUpgrade()
{
	if (m_smallEquipped)
	{
		m_game->m_player->m_car.setAcceleration(2.25f);
	}
	else if (m_mediumEquipped)
	{
		m_game->m_player->m_car.setAcceleration(2.5f);
	}
	else if (m_largeEquipped)
	{
		m_game->m_player->m_car.setAcceleration(2.75f);
	}
}
