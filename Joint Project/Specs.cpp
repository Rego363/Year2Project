#include "Specs.h"
#include "playGame.h"

specs::specs(Game &game, Levels &level):
	m_game(&game),
	m_currentLevel(&level)
{
	m_EnemiesNum = 100.0f;
	m_title = new Label("Specifications", 400, 30);
	m_Time = new Button("Duration of Race", 300, 400);
	m_laps = new Button("No. Laps", 300, 200);
	m_Race = new Button("Play", 300, 450);
	m_Race->Enter = std::bind(&specs::goToMapRacing, this);
	m_Back = new Button("Back", 100, 500);
	m_Back->Enter = std::bind(&specs::goToMapSelect, this);

	m_3 = new RadioButton("3 Laps", 300, 150,"music");
	m_5 = new RadioButton("5 Laps", 300, 200,"music");
	m_7 = new RadioButton("7 Laps", 300, 250,"music");


	m_EnemiesNo = new Slider(300.0f, 100.0f, m_EnemiesNum, "Enemies");
	m_EnemiesNo->getFocus();

	m_title->changeTextSize(100);
	m_gui.addSlider(m_EnemiesNo);
	m_gui.addRadioButton(m_3);
	m_gui.addRadioButton(m_5);
	m_gui.addRadioButton(m_7);
	m_gui.addButton(m_Time);
	m_gui.addButton(m_Race);
	m_gui.addButton(m_Back);
	
	m_currentSelect = 0;
	m_gui.vertical = true;


}

specs::~specs()
{
}



void specs::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

void specs::update()
{

	m_gui.update(m_currentSelect, 7);
}

void specs::goToMapSelect()
{
	m_game->changeGameState(GameState::MapSelect);

}

void specs::goToMapRacing()
{
	if (m_3)
	{
		m_currentLevel->m_maxLaps = 3;
	}
	else if (m_5)
	{
		m_currentLevel->m_maxLaps = 5;
	}
	else if (m_7)
	{
		m_currentLevel->m_maxLaps = 7;
	}
	m_game->resetMap();
	m_game->changeGameState(GameState::Racing);

}


