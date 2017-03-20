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

struct LamboData
{
	std::string m_fileName;
};

struct blueLamboData
{
	std::string m_fileName;
};

struct TileData
{
	std::string m_fileName;
};

struct GroundData
{
	std::string m_fileName;
};

struct SandData
{
	std::string m_fileName;
};

struct TrackData
{
	std::string m_type;
	sf::Vector2f m_position;
	float m_size;
};


//contains all the levels data
struct LevelData
{
	LamboData m_lambo;
	FontData m_Font;
	TileData m_Tiles;
	GroundData m_ground;
	SandData m_sand;
	blueLamboData m_aiLambo;
	std::vector<TrackData> m_track;
};

//class to load in the level details
class LevelLoader
{
public:
	LevelLoader();

	static bool load(LevelData& level);
};