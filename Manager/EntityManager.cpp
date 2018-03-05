#include "EntityManager.h"
#include "ManagersAccess.h"
#include "PlayerEntity.h"
#include "ZombieWalkerEnemy.h"
#include "SpikeTrap.h"
#include "UniqueAnimation.h"
#include "StatsBarEntity.h"
EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::initialize(ManagersAccess *managerAccess)
{
	m_managerAccess = managerAccess;
	// PLAYER
	PlayerEntity* playerEntity = new PlayerEntity(managerAccess);
	m_playerEntity = playerEntity;
	m_entityContainer.push_back(playerEntity);
	// STAT BAR
	StatsBarEntity *statBarEntity = new StatsBarEntity();
	statBarEntity->initialize(sf::Vector2f(-480.0f, -250.0f), playerEntity, m_managerAccess);
	m_entityContainer.push_back(statBarEntity);
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(256, 256), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(300, 300), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(500, 512), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(300, 400), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(288, 256), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(300, 332), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(500, 520), m_managerAccess));
	m_entityContainer.push_back(new ZombieWalkerEnemy(new PositionComponent(120, 250), m_managerAccess));
	m_entityContainer.push_back(new SpikeTrap(new PositionComponent(192, 192), m_managerAccess));
	m_entityContainer.push_back(new SpikeTrap(new PositionComponent(224, 192), m_managerAccess));
	m_entityContainer.push_back(new SpikeTrap(new PositionComponent(256, 192), m_managerAccess));
	m_entityContainer.push_back(new SpikeTrap(new PositionComponent(288, 192), m_managerAccess));
}

void EntityManager::create(Entity * entity)
{
	m_entityContainer.push_back(entity);
}

void EntityManager::update(sf::Time time)
{
	//std::cout << "entities : " << m_entityContainer.size() << std::endl;
	for (int i = 0; i < m_entityContainer.size(); i++)
	{
		m_entityContainer[i]->update(time);

		if (m_entityContainer[i]->alive == false)
		{

			m_entityContainer[i]->~Entity();
			m_entityContainer.erase(m_entityContainer.begin() + i);			
		}
	}
}