#pragma once
#include "Shader.h"
#include "ShaderParameter.h"

class HeatShader : public Shader
{
protected:


	float m_time;
	float m_riseFactor;
	float m_distortionFactor;


	sf::Texture distortionMap;
public:
	HeatShader();
	virtual ~HeatShader();
	void setTexture(sf::Texture &texture);
	void setRiseFactor(float inValue)
	{
		m_riseFactor = inValue;
	}
	void setDistortionFactor(float inValue)
	{
		m_distortionFactor = inValue;
	}
	void setTime(float inValue)
	{

		m_time = inValue;
	}
	float getTime() { return m_time; }
};
