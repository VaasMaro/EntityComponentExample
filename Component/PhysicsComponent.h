#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Entity;
class PhysicsComponent
{
public:
	virtual ~PhysicsComponent(){}
	virtual void addHitBox(sf::FloatRect rect) = 0;
	virtual void setId(int id) { m_id = id; }
	virtual int getId() { return m_id; }	
	virtual std::vector<sf::FloatRect> getHitBoxContainer() { return m_hitBoxContainer; }
	virtual void setEntity(Entity *entity) { m_entity = entity; }
	virtual Entity * getEntity() { return m_entity; }
protected:
	int m_id;
	std::vector<sf::FloatRect> m_hitBoxContainer;
	Entity *m_entity;
};
