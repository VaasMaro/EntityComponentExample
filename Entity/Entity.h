#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity() {}
	virtual void update(sf::Time time) = 0;
	virtual void setLifeComponent(class LifeComponent *life) { m_lifeComponent = life; }
	virtual class LifeComponent *getLifeComponent() { return m_lifeComponent; }
	bool alive = true;
protected:
	class LifeComponent *m_lifeComponent = NULL;
};

