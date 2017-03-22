#include "EnterNameScreen.h"

EnterNameScreen::EnterNameScreen(Game &game, Player &player):
	m_game(&game),
	m_player(&player)
{
	m_enteredName = "";

	m_label = new Label("Your Name:  "+ m_enteredName, 450, 100);
	m_gui.addLabel(m_label);

	// Top line
	m_widgets[0] = new Button("Q", 450, 300, 50);
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&EnterNameScreen::addQ, this);
	m_widgets[1] = new Button("W", 500, 300, 50);
	m_widgets[1]->Enter = std::bind(&EnterNameScreen::addW, this);
	m_widgets[2] = new Button("E", 550, 300, 50);
	m_widgets[2]->Enter = std::bind(&EnterNameScreen::addE, this);
	m_widgets[3] = new Button("R", 600, 300, 50);
	m_widgets[3]->Enter = std::bind(&EnterNameScreen::addR, this);
	m_widgets[4] = new Button("T", 650, 300, 50);
	m_widgets[4]->Enter = std::bind(&EnterNameScreen::addT, this);
	m_widgets[5] = new Button("Y", 700, 300, 50);
	m_widgets[5]->Enter = std::bind(&EnterNameScreen::addY, this);
	m_widgets[6] = new Button("U", 750, 300, 50);
	m_widgets[6]->Enter = std::bind(&EnterNameScreen::addU, this);
	m_widgets[7] = new Button("I", 800, 300, 50);
	m_widgets[7]->Enter = std::bind(&EnterNameScreen::addI, this);
	m_widgets[8] = new Button("O", 850, 300, 50);
	m_widgets[8]->Enter = std::bind(&EnterNameScreen::addO, this);
	m_widgets[9] = new Button("P", 900, 300, 50);
	m_widgets[9]->Enter = std::bind(&EnterNameScreen::addP, this);

	// Middle line
	m_widgets[10] = new Button("A", 450, 350, 50);
	m_widgets[10]->Enter = std::bind(&EnterNameScreen::addA, this);
	m_widgets[11] = new Button("S", 500, 350, 50);
	m_widgets[11]->Enter = std::bind(&EnterNameScreen::addS, this);
	m_widgets[12] = new Button("D", 550, 350, 50);
	m_widgets[12]->Enter = std::bind(&EnterNameScreen::addD, this);
	m_widgets[13] = new Button("F", 600, 350, 50);
	m_widgets[13]->Enter = std::bind(&EnterNameScreen::addF, this);
	m_widgets[14] = new Button("G", 650, 350, 50);
	m_widgets[14]->Enter = std::bind(&EnterNameScreen::addG, this);
	m_widgets[15] = new Button("H", 700, 350, 50);
	m_widgets[15]->Enter = std::bind(&EnterNameScreen::addH, this);
	m_widgets[16] = new Button("J", 750, 350, 50);
	m_widgets[16]->Enter = std::bind(&EnterNameScreen::addJ, this);
	m_widgets[17] = new Button("K", 800, 350, 50);
	m_widgets[17]->Enter = std::bind(&EnterNameScreen::addK, this);
	m_widgets[18] = new Button("L", 850, 350, 50);
	m_widgets[18]->Enter = std::bind(&EnterNameScreen::addL, this);
	m_widgets[19] = new Button("Enter", 900, 350, 50);
	m_widgets[19]->Enter = std::bind(&EnterNameScreen::changeGameState, this);

	// Bottom line
	m_widgets[20] = new Button("Z", 450, 400, 50);
	m_widgets[20]->Enter = std::bind(&EnterNameScreen::addZ, this);
	m_widgets[21] = new Button("X", 500, 400, 50);
	m_widgets[21]->Enter = std::bind(&EnterNameScreen::addX, this);
	m_widgets[22] = new Button("C", 550, 400, 50);
	m_widgets[22]->Enter = std::bind(&EnterNameScreen::addC, this);
	m_widgets[23] = new Button("V", 600, 400, 50);
	m_widgets[23]->Enter = std::bind(&EnterNameScreen::addV, this);
	m_widgets[24] = new Button("B", 650, 400, 50);
	m_widgets[24]->Enter = std::bind(&EnterNameScreen::addB, this);
	m_widgets[25] = new Button("N", 700, 400, 50);
	m_widgets[25]->Enter = std::bind(&EnterNameScreen::addN, this);
	m_widgets[26] = new Button("M", 750, 400, 50);
	m_widgets[26]->Enter = std::bind(&EnterNameScreen::addM, this);
	m_widgets[27] = new Button("'", 800, 420);
	m_widgets[27]->Enter = std::bind(&EnterNameScreen::addChar, this);
	m_widgets[28] = new Button("Space", 850, 400, 50);
	m_widgets[28]->Enter = std::bind(&EnterNameScreen::Space, this);
	m_widgets[29] = new Button("Delete", 970, 400, 50);
	m_widgets[29]->Enter = std::bind(&EnterNameScreen::deleteLetter, this);
	



	for each (Widget* var in m_widgets)
	{
		
		m_gui.addWidget(var);
	}
	m_gui.both = true;


	if (!m_blankTexture.loadFromFile("blankBackground.png"))	// Load blank texture
	{
		std::cout << "blankTile failed to load" << std::endl;	//Error message
	}

	m_shaderSprite.setTexture(m_blankTexture);	// Set texture for the blank sprite

	if (!m_shader.loadFromFile("Shaders/Smoke.frag", sf::Shader::Fragment)) //Load shader
	{
		std::cout << "shader failed to load" << std::endl;	// Error message
	}

	m_shader.setParameter("time", 0.0f);
	m_shader.setParameter("resolution", 1280.0f, 720.0f);
	m_shaderSprite.setPosition(0.0f, 0.0f);
}

std::string EnterNameScreen::getEnteredName()
{
	return m_enteredName;
}

void EnterNameScreen::update(float dt)
{
	m_shader.setParameter("time", dt);
	m_gui.update(m_selectedItem, MAX_ITEMS);	
}

void EnterNameScreen::draw(sf::RenderWindow & window)
{
	window.draw(m_shaderSprite, &m_shader);
	m_gui.draw(window);
}

void EnterNameScreen::addQ()
{
	m_enteredName += "Q";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addW()
{
	m_enteredName += "W";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addE()
{
	m_enteredName += "E";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addR()
{
	m_enteredName += "R";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addT()
{
	m_enteredName += "T";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addY()
{
	m_enteredName += "Y";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addU()
{
	m_enteredName += "U";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addI()
{
	m_enteredName += "I";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addO()
{
	m_enteredName += "O";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addP()
{
	m_enteredName += "P";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addA()
{
	m_enteredName += "A";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addS()
{
	m_enteredName += "S";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addD()
{
	m_enteredName += "D";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addF()
{
	m_enteredName += "F";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addG()
{
	m_enteredName += "G";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addH()
{
	m_enteredName += "H";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addJ()
{
	m_enteredName += "J";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addK()
{
	m_enteredName += "K";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addL()
{
	m_enteredName += "L";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addZ()
{
	m_enteredName += "Z";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addX()
{
	m_enteredName += "X";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addC()
{
	m_enteredName += "C";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addV()
{
	m_enteredName += "V";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addB()
{
	m_enteredName += "B";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addN()
{
	m_enteredName += "N";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addM()
{
	m_enteredName += "M";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::addChar()
{
	m_enteredName += "'";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::Space()
{
	m_enteredName += " ";
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::deleteLetter()
{
	if (m_enteredName.size() > 0)
	{
		m_enteredName.pop_back();
	}
	m_label->updateText("Your Name:  " + m_enteredName);
}

void EnterNameScreen::changeGameState()
{
	m_player->newPlayer(m_enteredName);
	m_game->changeGameState(GameState::TheLicense);
}
