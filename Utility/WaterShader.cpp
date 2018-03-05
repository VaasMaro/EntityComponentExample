#include "WaterShader.h"
#include "log.h"
WaterShader::WaterShader()
{
	if (!m_shader.loadFromFile("Shaders/water.txt", sf::Shader::Fragment))
	{
		std::cout << "Error while shaders" << std::endl;
	}
	if (!m_distortionMap.loadFromFile("Shaders/noiseWater.png"))
	{
		std::cout << "Error while loading distortion map" << std::endl;
	}
	m_distortionMap.setSmooth(true);
	m_distortionMap.setRepeated(true);
	m_shader.setUniform("currentTexture", sf::Shader::CurrentTexture);
	m_shader.setUniform("distortionMapTexture", m_distortionMap);
	clock = new sf::Clock();
}

WaterShader::~WaterShader()
{
}

void WaterShader::update()
{
	in clock->getElapsedTime().asSeconds() ed;
	m_shader.setUniform("time", clock->getElapsedTime().asSeconds()/14);
}

void WaterShader::bind()
{
	sf::Shader::bind(&m_shader);
}

void WaterShader::unbind()
{
	sf::Shader::bind(NULL);
}
