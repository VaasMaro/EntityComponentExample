#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class WaterShader
{
public:
	WaterShader();
	~WaterShader();
	void update();
	void bind();
	void unbind();
	sf::Shader& getShader() { return m_shader; }
private:
	sf::Clock *clock;
	sf::Shader m_shader;
	sf::Texture m_distortionMap;
};
