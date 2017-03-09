#include "Player.h"



Player::Player()
{
	m_money = 500;
	m_carSelect = 0;
	m_secHighScore = 10;
	m_minHighScore = 2;
	m_name = "Naggers";
	filename = "players.txt";
}


Player::~Player()
{
}

void Player::load(std::string name)
{
	fileInput.open(filename);


	while (fileInput.is_open())
	{
		fileInput >> fileLine;
		if (fileLine == name)
		{
			m_name = name;
			fileInput >> fileLine;
			m_money = stoi(fileLine);
			fileInput >> fileLine;
			m_secHighScore = stoi(fileLine);
			fileInput >> fileLine;
			m_minHighScore = stoi(fileLine);
			fileInput.close();
		}
		else
		{

			fileInput >> fileLine;
			fileInput >> fileLine;
			fileInput >> fileLine;
		}

		if (fileInput.eof())
		{
			fileInput.close();
		}

	}
	
}

// https://www.youtube.com/watch?v=2pBVlpLM1Sc
// http://stackoverflow.com/questions/9505085/replace-a-line-in-text-file
void Player::save(std::string name)
{


	try {

		fileOutput.open(filename.c_str(), std::ios_base::app);
		
		fileOutput << m_name.c_str();
		fileOutput << "\n";
		fileOutput << std::to_string(m_money);
		fileOutput << "\n";
		fileOutput << std::to_string(m_secHighScore);
		fileOutput << "\n";
		fileOutput << std::to_string(m_minHighScore);
		fileOutput << "\n";
		fileOutput.close();
	}
	catch (std::exception e) {
		cout << "Exception opening/reading file";
	}
}

void Player::rewriteSave()
{
	std::string name;
	int money;
	int sec;
	int min;


	fileInput >> name;
	fileInput >> fileLine;
	money = stoi(fileLine);
	fileInput >> fileLine;
	sec = stoi(fileLine);
	fileInput >> fileLine;
	min = stoi(fileLine);

	
	fileOutput << name.c_str();
	fileOutput << "\n";
	fileOutput << std::to_string(money);
	fileOutput << "\n";
	fileOutput << std::to_string(sec);
	fileOutput << "\n";
	fileOutput << std::to_string(min);
	fileOutput << "\n";

}