

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
	void goToCredits();

private:

	GUI m_gui;
	Label *m_title;
	Label *m_icons[2];
	Button *m_Play;
	Button *m_Garage;
	Button *m_ChangeProfile;
	Button *m_Options;
	Button *m_Help;
	Button *m_Exit;
	Button *m_Credits;
	int m_currentSelect;
	Game *m_game;
};
#endif // !MAINMENU