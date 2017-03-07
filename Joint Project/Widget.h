#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#include<SFML\Graphics.hpp>
#include"XBOX360CONTROLLER.h"
#include<functional>


//base class for all the UI elements
//nearly all functions will be virtual
class Widget {

public:
	Widget();
	virtual void getFocus(); //gain highlight
	virtual void loseFocus(); //lose highlight
	virtual bool checkFocus(); //check for focus

	virtual void update(); //update

	virtual void getActive();
	virtual void loseActive();
	virtual bool checkActive(); //check if active

	virtual void draw(sf::RenderWindow &window); //draw
	std::string getID(); //check the UI elements ID

	virtual void increaseValue();
	virtual void decreaseValue(); //for sliders

	virtual void setRectColor(sf::Color color); //change rectangle color

	void activateCallBack();

	virtual void updateText(std::string s); //update text of an element

	std::string checkTag(); //check tag, mainly useful in match game gameplay

	virtual void changeTextSize(int size); //adjust text size

	typedef std::function<void()> Callback; 
	Callback Enter;
	Callback AdjustAdd;
	Callback AdjustMinus; //callback functions

	bool isActive; //is element active
	virtual void endAnim(); //animation
	bool animEnd; //bool to signify animation is over
protected:
	sf::RectangleShape m_rect; //rectangle surrounding the element
	bool m_hasFocus; //bool for focus
	std::string m_id; //id of the element eg(button, slider, etc)
	std::string m_tag; //tag of element, can be any word, useful for pairing elements
	
	
};