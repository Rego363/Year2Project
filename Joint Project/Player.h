#pragma once

#include "game.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

class Player
{
public:
	Player();
	~Player();
	void load(std::string name);
	void save(std::string name);

private:
	std::string filename;
	std::ifstream fileInput;

	std::ofstream fileOutput;
	std::stringstream fileStream;
	std::string fileLine;
	int m_money;
	int m_carSelect;
	int m_secHighScore;
	int m_minHighScore;
	std::string m_name;
	void rewriteSave();
	
};

