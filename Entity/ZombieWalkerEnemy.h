#pragma once
#include "Entity.h"
#include "HumanAnimatedSpriteComponent.h"
#include "PositionComponent.h"
#include "HumanPhysicsComponent.h"
#include "StatisticsComponent.h"
#include "WalkerAIComponent.h"
#include "LifeComponent.h"
#include "SpikeComponent.h"
class ZombieWalkerEnemy : public Entity
{
public:
	ZombieWalkerEnemy();
	ZombieWalkerEnemy(PositionComponent *position, ManagersAccess *managerAccess);
	~ZombieWalkerEnemy();
	virtual void update(sf::Time time);
private:
	ManagersAccess *m_managerAccess;
	// Components
	HumanAnimatedSpriteComponent *m_animatedSprite;
	PositionComponent *m_position;
	HumanPhysicsComponent *m_physics;
	StatisticsComponent *m_statistics;
	WalkerAIComponent *m_AI;
	SpikeComponent *m_spikeComponent;

};

