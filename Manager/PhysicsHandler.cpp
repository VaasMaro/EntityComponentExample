#include "PhysicsHandler.h"
#include "ManagersAccess.h"
#include "TileMap.h"
#include "PathLayer.h"
PhysicsHandler::PhysicsHandler()
{
}

PhysicsHandler::~PhysicsHandler()
{
}

void PhysicsHandler::initialize(ManagersAccess * managerAccess)
{
	m_managerAccess = managerAccess;
	m_pathLayer = m_managerAccess->mapManager->getTileMap()->getPathLayer();
}

bool PhysicsHandler::solveBoxToTiles(sf::FloatRect boundingBox)
{
	int xmin, xmax, ymin, ymax, i, j;
	xmin = boundingBox.left / m_tileSize;
	ymin = (boundingBox.top + 16) / m_tileSize;
	xmax = (boundingBox.left + boundingBox.width + 32) / m_tileSize;
	ymax = (boundingBox.top + boundingBox.height + 32) / m_tileSize;
	for (j = xmin; j < xmax; j++)
	{
		for (i = ymin; i < ymax; i++)
		{
			if (!m_pathLayer->isWalkable(i, j)) return false;
		}
	}
	return true;
}

Entity* PhysicsHandler::solveBoxtoHitBox(sf::FloatRect boundingBox)
{
	for(auto physics : m_physicsContainer)
	{
		for (auto rect : physics->getHitBoxContainer())
		{
			if (boundingBox.intersects(rect))
			{
				return physics->getEntity();
			}
		}
	}
	return NULL;
}

Entity * PhysicsHandler::solveBoxtoPlayer(sf::FloatRect boundingBox)
{
	if (m_playerPhysics != NULL)
	{
		for (auto rect : m_playerPhysics->getHitBoxContainer())
		{
			if (boundingBox.intersects(rect))
			{
				return m_playerPhysics->getEntity();
			}
		}
		return NULL;
	}
}

void PhysicsHandler::subscribePlayer(PhysicsComponent * physicsComponent)
{
	m_playerPhysics = physicsComponent;

}

int PhysicsHandler::subscribe(PhysicsComponent * physicsComponent)
{
	m_physicsContainer.push_back(physicsComponent);
	return m_physicsContainer.size() - 1;
}

void PhysicsHandler::reject(const int & id)
{
	m_physicsContainer.erase(m_physicsContainer.begin() + id);
	for (int i = id; i < m_physicsContainer.size(); i++)
	{
		m_physicsContainer[i]->setId(m_physicsContainer[i]->getId() - 1);
	}
}

void PhysicsHandler::rejectPlayer()
{
	m_playerPhysics = NULL;
}
