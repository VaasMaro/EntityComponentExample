#pragma once
#include "Entity.h"
#include "ProjectilePhysicsComponent.h"
#include "PositionComponent.h"
#include "Damage.h"
#include "ManagersAccess.h"
#include "AnimationGraphicsComponent.h"
#include "RotationComponent.h"
#include "Math.h"
#include "SpikeComponent.h"
class FireExplosion : public Entity
{
public:
	FireExplosion();
	FireExplosion(PositionComponent *point, ManagersAccess *managerAccess, Damage damage);
	FireExplosion(PositionComponent *point, AnimationGraphicsComponent *graphics, ProjectilePhysicsComponent *physics, Damage damage, ManagersAccess *managerAccess);
	~FireExplosion();
	virtual void update(sf::Time time);
private:
	ManagersAccess *m_managerAccess;
	Damage m_damage;
	AnimationGraphicsComponent *m_graphics;
	PositionComponent *m_position;
	SpikeComponent *m_spike;
	sf::FloatRect m_boudingBox;
	int m_numberFrame = 0;
};
