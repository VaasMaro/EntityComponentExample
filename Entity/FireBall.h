#pragma once
#include "Entity.h"
#include "ProjectileGraphicsComponent.h"
#include "PositionComponent.h"
#include "Damage.h"
#include "ManagersAccess.h"
#include "ProjectilePhysicsComponent.h"
#include "RotationComponent.h"
#include "Math.h"
class FireBall : public Entity
{
public:
	FireBall();
	FireBall(PositionComponent *point, ProjectileGraphicsComponent *graphics, ProjectilePhysicsComponent *physics, Damage damage, ManagersAccess *managerAccess, const float &rotation);
	~FireBall();
	virtual void update(sf::Time time);
private:
	ManagersAccess *m_managerAccess;
	Damage m_damage;
	ProjectileGraphicsComponent *m_graphics;
	ProjectilePhysicsComponent *m_physics;
	PositionComponent *m_position;
	float m_rotation;
};
