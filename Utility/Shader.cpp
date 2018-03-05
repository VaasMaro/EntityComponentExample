#include "Shader.h"

Shader::Shader(const std::string & inFileName) 
	: m_shaderFile(inFileName)
{
	initialize();
}

void Shader::update()
{
	for (auto currentParameter : m_shaderParameterContainer)
		currentParameter->bind(m_shader);
	sf::Shader::bind(&m_shader);
}

void Shader::initialize()
{
	if (!m_shader.loadFromFile(m_shaderFile, sf::Shader::Fragment))
	{
		std::cout << "wow" << std::endl;
	}
}

void Shader::addParameter(ShaderParameter* inShaderParameter)
{
	m_shaderParameterContainer.push_back(inShaderParameter);
}
