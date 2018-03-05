#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsComponent.h"
class PhysicsHandler
{
public:
	PhysicsHandler();
	~PhysicsHandler();
	void initialize(struct ManagersAccess *managerAccess);
	bool solveBoxToTiles(sf::FloatRect boundingBox);
	Entity* solveBoxtoHitBox(sf::FloatRect boundingBox);
	Entity* solveBoxtoPlayer(sf::FloatRect boundingBox);
	void subscribePlayer(PhysicsComponent *physicsComponent);
	int subscribe(PhysicsComponent *physicsComponent);
	void reject(const int &id);
	void rejectPlayer();
private:
	struct ManagersAccess *m_managerAccess;
	class PathLayer *m_pathLayer;
	int m_tileSize = 32;
	std::vector<PhysicsComponent*> m_physicsContainer;
	PhysicsComponent *m_playerPhysics;
};
