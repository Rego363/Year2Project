#ifndef CUTSCENE
#define CUTSCENE

#include "Game.h"

class Game;

class Cutscene
{
public:
	Cutscene(Game &game);
	~Cutscene();

	void update(float dt);
	void render(sf::RenderWindow & window);
	void load();

private:
	Game *m_game;
	sfe::Movie m_cutscene;
	bool m_play;

	// Shader 
	sf::Sprite m_shaderSprite;
	sf::Shader m_waveShader;
};

#endif