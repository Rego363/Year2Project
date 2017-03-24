#pragma once

#include <Thor\Resources.hpp>
#include <SFML\Graphics.hpp>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	thor::ResourceHolder<sf::Texture, std::string> m_textureHolder;	//Resource manager to hold textures
	thor::ResourceHolder<sf::Font, std::string> m_fontHolder;		//Resource manager to hold fonts
};