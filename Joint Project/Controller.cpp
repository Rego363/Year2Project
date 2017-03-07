#include "controller.h"

X360Controller::X360Controller()
{

}

//function for updating controller
void X360Controller::update()
{
	m_previous = m_current;
	sf::Joystick::update();
	m_current.A = sf::Joystick::isButtonPressed(0, 0);
	m_current.B = sf::Joystick::isButtonPressed(0, 1);
	m_current.X = sf::Joystick::isButtonPressed(0, 2);
	m_current.Y = sf::Joystick::isButtonPressed(0, 3);
	m_current.LB = sf::Joystick::isButtonPressed(0, 4);
	m_current.RB = sf::Joystick::isButtonPressed(0, 5);
	m_current.Start = sf::Joystick::isButtonPressed(0, 7);
	m_current.End = sf::Joystick::isButtonPressed(0, 6);
	m_current.LeftThumbstickClick = sf::Joystick::isButtonPressed(0, 8);
	m_current.RightThumbstickClick = sf::Joystick::isButtonPressed(0, 9);

	m_current.RightThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));
	m_current.LeftThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y));
	m_current.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	m_current.RTrigger = -sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);


	//cannot get this to work
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > 50)
	{
		m_current.DpadUp = true;
	}
	else
	{
		m_current.DpadUp = false;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -50)
	{
		m_current.DpadDown = true;
	}
	else
	{
		m_current.DpadDown = false;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 50)
	{
		m_current.DpadRight = true;
	}
	else
	{
		m_current.DpadRight = false;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < -50)
	{
		m_current.DpadLeft = true;
	}
	else
	{
		m_current.DpadLeft = false;
	}
}

//connection function for controller
bool X360Controller::connect()
{
	return true;
}

//how many controllers are connected
bool X360Controller::isConnected()
{
	return true;
}

//destroys controller
X360Controller::~X360Controller()
{

}