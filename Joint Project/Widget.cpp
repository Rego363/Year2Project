#include"Widget.h"
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//widget base class, mostly virtual functions
Widget::Widget()
{
	isActive = true;
}
//widget get focus
void Widget::getFocus()
{
	m_hasFocus = true;
}
//widget lose focus
void Widget::loseFocus()
{
	m_hasFocus = false;
}
//check focus
bool Widget::checkFocus()
{
	return m_hasFocus;
}
//update loop
void Widget::update()
{
	

}
//draw loop
void Widget::draw(sf::RenderWindow &window)
{
	

}

//make widget active 
void Widget::getActive()
{
}
//lose widget active
void Widget::loseActive()
{
}
//check if widget is active
bool Widget::checkActive()
{
	return m_hasFocus;
}
//return id of the widget
std::string Widget::getID()
{
	return m_id;
}
//decrease the widgets value
void Widget::decreaseValue()
{

}
//set the widgets rectangle color
void Widget::setRectColor(sf::Color color)
{
}
//activate callback function
void Widget::activateCallBack()
{
	Enter();
}
//update the widgets text
void Widget::updateText(std::string s)
{
}
//check the tag of the widget
std::string Widget::checkTag()
{
	return m_tag;
}
//change the widgets text size
void Widget::changeTextSize(int size)
{
}
//animation for the widget
void Widget::endAnim()
{
}
//increase the value of the widget
void Widget::increaseValue()
{

}