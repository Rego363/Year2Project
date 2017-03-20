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

//find the car texture
void operator >> (const YAML::Node& lamboNode, blueLamboData& lambo)
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

void operator >> (const YAML::Node& garageNode, GarageData& garage)
{
	garage.m_fileName = garageNode["garagefile"].as<std::string>();
}

/// <summary>
/// Loading data for the track
/// </summary>
/// <param name="trackNode"></param>
/// <param name="track"></param>
void operator >> (const YAML::Node& trackNode, TrackData& track)
{
	track.m_type = trackNode["type"].as<std::string>();				// Loading the type of node
	track.m_position.x = trackNode["position"]["x"].as<float>();	// Loading the nodes x position
	track.m_position.y = trackNode["position"]["y"].as<float>();	// Loading the nodes y position
	track.m_size = trackNode["size"].as<float>();					// Loading the size of the node
}

//all levelData
void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["bluelambo"] >> level.m_aiLambo;
	levelNode["lambo"] >> level.m_lambo;
	levelNode["font"] >> level.m_Font;
	levelNode["maptile"] >> level.m_Tiles;
	levelNode["ground"] >> level.m_ground;
	levelNode["sand"] >> level.m_sand;
	levelNode["garage"] >> level.m_garage;

	// For loop to load track data into m_track 
	const YAML::Node& trackNode = levelNode["track"].as<YAML::Node>();
	for (unsigned i = 0; i < trackNode.size(); ++i)
	{
		TrackData track;
		trackNode[i] >> track;
		level.m_track.push_back(track);
	}
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
