#include "GUI.h"
#include "Button.h"

///<summary>
// This class will create and manage the main menu screen
///<summary>
class MainMenu
{
public:

	MainMenu();
	~MainMenu();
	void render(sf::RenderWindow & window);
	void update();

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

};
