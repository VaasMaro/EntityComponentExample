#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include <iostream>
class RotationComponent
{
public:
	RotationComponent();
	~RotationComponent();
	void update(sf::Vector2f vec1, sf::Vector2f vec2);
	float getRotation();
	sf::Vector2f getDirection();
	void normalize(sf::Vector2f &vec1, sf::Vector2f &vec2);
private:
	float m_rotation;
};
