#pragma once
#include <SFML/Graphics.hpp>

struct Damage
{
	float physical;
	sf::Vector2f direction;
	Damage(){}
	Damage(float phys)
	{
		physical = phys;
	}
};