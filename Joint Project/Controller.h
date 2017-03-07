#ifndef CONTROLLER
#define CONTROLLER

#include <sfml/Graphics.hpp>

/// <summary>
/// data to store the current state of controller
/// </summary>
/// 

struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbstick;
	bool RightThumbstick;
	bool LeftThumbstickClick;
	bool RightThumbstickClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadLeft;
	bool DpadRight;
	bool Start;
	bool End;
	bool Xbox;
	float RTrigger;
	float LTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

/// <summary>
/// Xbox controller class to query current state
/// mimic controller like xna
/// </summary>
class X360Controller
{
private:
	//deadzone for dpad(really a joystick)
	const int dpadThreshold = 50;

public:
	//index count for multiple controllers
	int sf_Joystick_index;
	// the current state of buttons
	GamePadState m_current;
	// previous
	GamePadState m_previous;

	X360Controller();
	~X360Controller();
	void update();
	bool isConnected();
	bool connect();
};

#endif
