#include "Cutscene.h"


// cutscene constructor
Cutscene::Cutscene(Game & game) :
	m_game(&game)
{
	load();
	sf::Texture& shaderTexture = m_game->m_manager->m_textureHolder["blankBackground"];
	m_shaderSprite.setTexture(shaderTexture);	// Set texture for the blank sprite
	
	if (!m_waveShader.loadFromFile("Shaders/wave.frag", sf::Shader::Fragment)) //Load shader
	{
		std::cout << "shader failed to load" << std::endl;	// Error message
	}

	m_waveShader.setParameter("time", 0.0f);
	m_waveShader.setParameter("mouse", 1280, 720);
	m_waveShader.setParameter("resolution", 1280.0f, 720.0f);
	m_shaderSprite.setPosition(0.0f, 0.0f);
}

//destructor
Cutscene::~Cutscene()
{
}

/// <summary>
/// update loop
/// </summary>
void Cutscene::update(float dt)
{

	m_waveShader.setParameter("time", dt);

	m_cutscene.fit(sf::FloatRect(m_game->m_player->m_car.getPos().x - 639, m_game->m_player->m_car.getPos().y - 363, 1280, 720), true);
	m_shaderSprite.setPosition(m_game->m_player->m_car.getPos().x - 639, m_game->m_player->m_car.getPos().y - 363);
	m_play = true;

	if (m_play == true)
	{
		m_cutscene.play();
	}

	m_cutscene.update();

	if (m_cutscene.getStatus() == 0)
	{
		
		m_play = true;
		m_game->changeGameState(GameState::GameOver);
	}

	cout << to_string(m_cutscene.getStatus());
}

/// <summary>
/// Render loop
/// </summary>
void Cutscene::render(sf::RenderWindow & window)
{
	if (m_cutscene.getStatus() == 2)
	{
		window.draw(m_cutscene);
		window.draw(m_shaderSprite, &m_waveShader);
	}
}

/// <summary>
/// load animation
/// </summary>
void Cutscene::load()
{
	if (!m_cutscene.openFromFile("cutscene.mp4"))
	{
		std::cout << "Cutscene animation not loaded" << std::endl;
	}
}
