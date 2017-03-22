#include "GarageScreen.h"

GarageScreen::GarageScreen(float x, float y, Game &game):
	m_game(&game)
{
	m_label = new Label("Garage", (x / 2), float(y / MAX_ITEMS + 0.2f)*0.1f);
	m_label->changeTextSize(70);
	m_label->setUnderLined();
	m_gui.addLabel(m_label);
	m_widgets[0] = new Button("Acceleration", (x / 2), float(y / MAX_ITEMS + 0.2f)*2.5f);
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&GarageScreen::goAccel, this);
	m_widgets[1] = new Button("Speed", (x / 2), float(y / MAX_ITEMS + 0.2f)*3.5f);
	m_widgets[1]->Enter = std::bind(&GarageScreen::goSpeed, this);
	m_widgets[2] = new Button("Braking", (x / 2), float(y / MAX_ITEMS + 0.2f)*4.5f);
	m_widgets[2]->Enter = std::bind(&GarageScreen::goBrake, this);
	m_widgets[3] = new Button("Turbo", (x / 2), float(y / MAX_ITEMS + 0.2f)*5.5f);
	m_widgets[3]->Enter = std::bind(&GarageScreen::goTurbo, this);
	m_widgets[4] = new Button("Steering", (x / 2), float(y / MAX_ITEMS + 0.2f)*6.5f);
	m_widgets[4]->Enter = std::bind(&GarageScreen::goSteer, this);
	m_widgets[5] = new Button("Back", (x / 2), float(y / MAX_ITEMS + 0.2f)*7.5f);
	m_widgets[5]->Enter = std::bind(&GarageScreen::goBack, this);
	
	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);
	}
	m_gui.vertical = true;


	
}

void GarageScreen::update()
{
	m_gui.update(m_selectedItem, MAX_ITEMS);
}

void GarageScreen::draw(sf::RenderWindow &window)
{
	m_gui.draw(window);
}

void GarageScreen::goBack()
{
	m_game->changeGameState(GameState::TheMenu);
}

void GarageScreen::goAccel()
{
	m_game->changeGameState(GameState::Acceleration);
}

void GarageScreen::goTurbo()
{
	m_game->changeGameState(GameState::Turbo);
}

void GarageScreen::goBrake()
{
	m_game->changeGameState(GameState::Braking);
}

void GarageScreen::goSpeed()
{
	m_game->changeGameState(GameState::Speed);
}

void GarageScreen::goSteer()
{
	m_game->changeGameState(GameState::Steering);
}
