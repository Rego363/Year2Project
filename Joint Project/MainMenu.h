

#ifndef MAINMENU
#define MAINMENU

#include "GUI.h"
#include "Button.h"
#include"Game.h"


class Game;
///<summary>
// This class will create and manage the main menu screen
///<summary>
class MainMenu
{
public:

	MainMenu(Game &game);
	~MainMenu();
	void render(sf::RenderWindow & window);
	void update();
	void GotoGarage();
	void quit();
	void goToOptions();
	void goToPlay();
	void goToHelp();
	void goToSpecs();
	void goToChangeP();

private:

	GUI m_gui;
	Label *m_title;
	Button *m_Play;
	Button *m_Garage;
	Button *m_ChangeProfile;
	Button *m_Options;
	Button *m_Help;
	Button *m_Exit;
	int m_currentSelect;
	Game *m_game;
};
#endif // !MAINMENU