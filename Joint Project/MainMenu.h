

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
	void update(float dt);
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
	Button *m_Play;
	Button *m_Garage;
	Button *m_ChangeProfile;
	Button *m_Options;
	Button *m_Help;
	Button *m_Exit;
	Button *m_Credits;
	int m_currentSelect;
	Game *m_game;
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	sf::Shader m_shader; // Shader for triangle affect
};
#endif // !MAINMENU