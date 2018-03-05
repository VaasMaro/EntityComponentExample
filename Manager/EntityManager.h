#pragma once
#include "Entity.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	void initialize(struct ManagersAccess *m_managerAccess);
	void create(Entity *entity);
	void update(sf::Time time);
	class PlayerEntity * getPlayer() { return m_playerEntity; }
private:
	class PlayerEntity * m_playerEntity;
	std::vector<Entity*> m_entityContainer;
	struct ManagersAccess *m_managerAccess;
};
