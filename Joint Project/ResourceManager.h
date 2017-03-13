#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML\Graphics.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "ResourcePath.hpp"


///<summary>
/// Dylan
/// loads information from yaml file
/// images, music and font files
///<summary>
struct FontData
{
	std::string m_fileNameFont;
};

struct BackgroundData
{
	std::string m_fileName;
};


struct LevelData
{
	BackgroundData m_background;
	FontData m_Font;

};

class LevelLoader
{
public:
	LevelLoader();

	static bool load(LevelData& level);
};