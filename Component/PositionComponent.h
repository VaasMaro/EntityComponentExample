#pragma once
#include <SFML/Graphics.hpp>

struct PositionComponent : public sf::Vector2f
{
	PositionComponent() { x = 0.0f, y = 0.0f; }
	PositionComponent(float inX, float inY) { x = inX, y = inY; };
};