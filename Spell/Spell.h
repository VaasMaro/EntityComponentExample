#pragma once
#include <SFML/Graphics.hpp>
class Spell
{
public:
	virtual ~Spell() {}
	virtual void cast(float rotation, const sf::Vector2f &position) = 0;
	virtual void update(const sf::Time &time) = 0;
private:
};
