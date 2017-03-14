#include "ResourceManager.h"

// find the font
void operator >> (const YAML::Node& FontNode, FontData& font)
{
	font.m_fileNameFont = FontNode["fontfile"].as<std::string>();
}

//find the car texture
void operator >> (const YAML::Node& lamboNode, LamboData& lambo)
{
	lambo.m_fileName = lamboNode["file"].as<std::string>();
}

//find the tile map texture
void operator >> (const YAML::Node& tileNode, TileData& maptile)
{
	maptile.m_fileName = tileNode["file"].as<std::string>();
}

///file for the normal background
void operator >> (const YAML::Node& groundNode, GroundData& ground)
{
	ground.m_fileName = groundNode["groundfile"].as<std::string>();
}

//file for the sand background
void operator >> (const YAML::Node& sandNode, SandData& sand)
{
	sand.m_fileName = sandNode["sandfile"].as<std::string>();
}

//all levelData
void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["lambo"] >> level.m_lambo;
	levelNode["font"] >> level.m_Font;
	levelNode["maptile"] >> level.m_Tiles;
	levelNode["ground"] >> level.m_ground;
	levelNode["sand"] >> level.m_sand;
}

LevelLoader::LevelLoader()
{
}

//Load in the yaml file
bool LevelLoader::load(LevelData& level)
{
	std::stringstream ss;
	//ss << resourcePath();
	ss << "level1.yaml";

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}
