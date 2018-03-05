#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

template<typename T>
class ParameterValue
{
public:
	T* m_value;

	virtual T& getValue()
	{
		return *m_value;
	}

	virtual void setValue(T* inValue)
	{
		m_value = inValue;
		std::cout << "indeed" << std::endl;
	}
};

class ShaderParameter
{
public:

	virtual ~ShaderParameter() {}

	virtual void bind(sf::Shader &shader) = 0;

	std::string getParameterName() {
		return ParameterName;
	}

protected:
	std::string ParameterName;
};

template<typename T>
class TShaderParameter : public ShaderParameter, public ParameterValue<T>
{
public:
	TShaderParameter(const std::string& inParameterName, T* inValue)
	{
		m_value = inValue;
		ParameterName = inParameterName;
	}

	void bind(sf::Shader &shader)
	{
		if (m_value)
			shader.setUniform(ParameterName, getValue());
		//else
			//std::cout << "oula" << std::endl;
	}
};