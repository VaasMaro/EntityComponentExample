#include "HeatShader.h"


HeatShader::HeatShader()
{
	m_shader.loadFromFile("example_001.frag.txt", sf::Shader::Fragment);
	addParameter(new TShaderParameter<sf::Shader::CurrentTextureType>("currentTexture", &sf::Shader::CurrentTexture));
	addParameter(new TShaderParameter<sf::Texture>("distortionMapTexture", &distortionMap));

	addParameter(new TShaderParameter<float>("time", &m_time));
	addParameter(new TShaderParameter<float>("distortionFactor", &m_distortionFactor));
	addParameter(new TShaderParameter<float>("riseFactor", &m_riseFactor));
}

HeatShader::~HeatShader()
{

}

void HeatShader::setTexture(sf::Texture & texture)
{
	distortionMap = texture;
	distortionMap.setRepeated(true);
	distortionMap.setSmooth(true);
}
