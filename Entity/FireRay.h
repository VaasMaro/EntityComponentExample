#pragma once
#include "Entity.h"
#include "ProjectileGraphicsComponent.h"
#include "PositionComponent.h"
#include "Damage.h"
#include "ManagersAccess.h"
#include "ProjectilePhysicsComponent.h"
#include "RotationComponent.h"
#include "Math.h"
class FireRay : public Entity
{
public:
	FireRay();
	FireRay(PositionComponent *point, ProjectileGraphicsComponent *graphics, ProjectilePhysicsComponent *physics, Damage damage, ManagersAccess *managerAccess, const float &rotation);
	~FireRay();
	virtual void update(sf::Time time);
private:
	ManagersAccess *m_managerAccess;
	Damage m_damage;
	ProjectileGraphicsComponent *m_graphics;
	ProjectilePhysicsComponent *m_physics;
	PositionComponent *m_position;
	float m_rotation;
};
