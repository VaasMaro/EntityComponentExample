#pragma once
#include <SFML/Graphics.hpp>
#include "ShaderParameter.h"

class Shader
{
public:
	Shader() {}
	Shader(const std::string& inFileName);
	virtual ~Shader(){}
	virtual void update();
	void initialize();
	void addParameter(ShaderParameter* inShaderParameter);
	sf::Shader& getShader() { return m_shader; }

protected:
	sf::Shader m_shader;
	std::string m_shaderFile;
	std::vector<ShaderParameter*> m_shaderParameterContainer;
};
