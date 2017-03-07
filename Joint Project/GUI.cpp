#include "GUI.h"
#include<iostream>
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//constructor for gui
GUI::GUI()
{
	vertical = false;
	horizontal = false;
	both = false;
	animating = false;	
	if (!m_buffer.loadFromFile("Gui transition.wav"))
	{
	}
	m_guiSound.setBuffer(m_buffer); //sound effect
}

GUI::~GUI()
{
}
//add label to container
void GUI::addLabel(Label *label)
{
	m_labels.push_back(label);
}
//add button to container
void GUI::addButton(Button * button)
{
	m_elements.push_back(button);
}
//add slider to container
void GUI::addSlider(Slider * slider)
{
	m_elements.push_back(slider);
}
//add radioButton to container
void GUI::addRadioButton(RadioButton * radioButton)
{
	m_elements.push_back(radioButton);
}

//can be used instead of all above adds
void GUI::addWidget(Widget * widget)
{
	m_elements.push_back(widget);
}

//update, where all elements updates are handled
void GUI::update(int &index, int maxItems)
{
	m_xbox.update(); //update controller
	for each (Widget* var in m_elements)
	{
		var->update();           //update the elements
	}


	if (m_elements[index]->getID() == "slider") //if element is a slider the these can be performed
	{
		if (m_xbox.m_currentState.DpadLeft == true || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			decreaseSliderValue(index);
		}
		if (m_xbox.m_currentState.DpadRight == true || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			increaseSliderValue(index);
		}
	}
	

	//control schemes
	if (vertical)
	{
		verticalControls(index, maxItems);
	}
	else if (horizontal)
	{
		horizontalControls(index, maxItems);
	}
	else {
		vertAndHorControls(index, maxItems);
	}


	//animation undergoeing
	if (animating)
	{
		m_elements[index]->endAnim(); //play the animation
		if (m_elements[index]->animEnd) 
		{
			animating = false;
			m_elements[index]->animEnd = false; //animation over
			activate(index); //activate callback
		}
	}

}

//draws all the elements to the screen
void GUI::draw(sf::RenderWindow & window)
{

	for each (Label* var in m_labels)
	{
		var->draw(window);
	}

	for each (Widget* var in m_elements)
	{
		var->draw(window);
	}
}

//for moving up a element in the gui
void GUI::moveUp(int &index)
{
		if (index - 1 >= 0)
		{
			m_guiSound.play();
			
			if (m_elements[index - 1]->isActive == false) 
			{
				if (index - 2 >= 0) //skip inactive element
				{
					m_elements[index]->loseFocus();
					index -= 2;
					m_elements[index]->getFocus();
				}
			}
			else
			{
				m_elements[index]->loseFocus();
				index--;
				m_elements[index]->getFocus();
			}
			

		}
}

//for moving down an element in the gui
void GUI::moveDown(int &index, int maxItems)
{
		if (index + 1 < maxItems)
		{
			m_guiSound.play();
			
			if (m_elements[index + 1]->isActive == false)
			{
				if (index + 2 < maxItems) //skip inactive
				{
					m_elements[index]->loseFocus();
					index += 2;
					m_elements[index]->getFocus();
				}
			}
			else
			{
				m_elements[index]->loseFocus();
				index++;
				m_elements[index]->getFocus();
			}
			
		}
}

//alternative for moving up a row of elements
void GUI::moveUp2(int & index)
{
	if (index - 4 >= 0)
	{

		m_guiSound.play();

		if (m_elements[index - 4]->isActive == false)
		{
			
		}
		else
		{
			m_elements[index]->loseFocus();
			index-=4;
			m_elements[index]->getFocus();
		}


	}
}

//alternative for moving down a row of elements
void GUI::moveDown2(int & index, int maxItems)
{
	if (index + 4 < maxItems)
	{
		m_guiSound.play();

		if (m_elements[index + 4]->isActive == false)
		{
		
		}
		else
		{
			m_elements[index]->loseFocus();
			index+=4;
			m_elements[index]->getFocus();
		}

	}
}

//activate the callback of the element
void GUI::activate(int &index)
{
	bool linked = false;

	if (m_elements[index]->getID() == "button")
	{
		try
		{
			m_elements[index]->Enter();
			
		}
		catch (std::bad_function_call)
		{
			std::cout << "Bad Function Call" << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < m_elements.size();i++)
		{
			//if linked then deactivate 
			if (m_elements[index]->checkTag() == m_elements[i]->checkTag()&& m_elements[index]->getID() == m_elements[i]->getID())
			{
				m_elements[i]->loseActive();
				linked = true;
			}

			if (m_elements[index]->checkActive() == true && !linked)
			{
				m_elements[index]->loseActive();
			}
			else {
				m_elements[index]->getActive();
				try {
					m_elements[index]->Enter();
				}
				catch (std::bad_function_call)
				{
					std::cout << "Bad Function Call" << std::endl;
				}
			}
		}

		

		


		
	}
}

//use callback functions of slider that are used to increase values
void GUI::increaseSliderValue(int &index)
{
	try {
		m_elements[index]->AdjustAdd();
		m_elements[index]->increaseValue();
	}
	catch (std::bad_function_call)
	{
		std::cout << "Bad Function Call" << std::endl;
	}
}

//use calback functions of slider that are used to decrease values
void GUI::decreaseSliderValue(int &index)
{
	try {
		m_elements[index]->AdjustMinus();
		m_elements[index]->decreaseValue();
	}
	catch (std::bad_function_call)
	{
		std::cout << "Bad Function Call" << std::endl;
	}
}

//vertical control scheme for xbox controller, dpad vertical use only
void GUI::verticalControls(int &index, int maxItems)
{
	if (m_xbox.m_currentState.DpadUp == true && !m_xbox.m_previousState.DpadUp || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp(index);
	}
	if (m_xbox.m_currentState.DpadDown == true && !m_xbox.m_previousState.DpadDown || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown(index, maxItems);
	}
	if (m_xbox.m_currentState.A == true && !m_xbox.m_previousState.A || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (m_elements[index]->getID() == "button")
		{
			animating = true;
		}
		if (m_elements[index]->getID() == "radiobutton")
		{
			activate(index);
		}
		
	}
}

//horizontal control scheme for xbox controller, dpad horizontal use only
void GUI::horizontalControls(int & index, int maxItems)
{
	if (m_xbox.m_currentState.DpadLeft == true && !m_xbox.m_previousState.DpadLeft || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp(index);
	}
	if (m_xbox.m_currentState.DpadRight == true && !m_xbox.m_previousState.DpadRight || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown(index, maxItems);
	}
	if (m_xbox.m_currentState.A == true && !m_xbox.m_previousState.A || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		activate(index);
	}
}

//vertical and horizontal control scheme for xbox controller, dpad vertical and horizontal
void GUI::vertAndHorControls(int & index, int maxItems)
{
	if (m_xbox.m_currentState.DpadLeft == true && !m_xbox.m_previousState.DpadLeft || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp(index);
	}
	if (m_xbox.m_currentState.DpadRight == true && !m_xbox.m_previousState.DpadRight || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown(index, maxItems);
	}
	if (m_xbox.m_currentState.DpadUp == true && !m_xbox.m_previousState.DpadUp || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp2(index);
	}
	if (m_xbox.m_currentState.DpadDown == true && !m_xbox.m_previousState.DpadDown || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown2(index, maxItems);
	}
	if (m_xbox.m_currentState.A == true && !m_xbox.m_previousState.A || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		activate(index);
	}
}

//clear out all the elements 
void GUI::removeAllElements()
{
	m_elements.clear();
	m_labels.clear();
}






