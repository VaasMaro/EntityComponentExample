#pragma once
#include "Entity.h"
#include "ProjectileGraphicsComponent.h"
#include "PositionComponent.h"
#include "Damage.h"
#include "ManagersAccess.h"
#include "ProjectilePhysicsComponent.h"
#include "RotationComponent.h"
#include "Math.h"
class Arrow : public Entity
{
public:
	Arrow();
	Arrow(PositionComponent *point, ProjectileGraphicsComponent *graphics, ProjectilePhysicsComponent *physics, Damage damage, ManagersAccess *managerAccess, const float &rotation);
	~Arrow();
	virtual void update(sf::Time time);
private:
	ManagersAccess *m_managerAccess;
	Damage m_damage;
	ProjectileGraphicsComponent *m_graphics;
	ProjectilePhysicsComponent *m_physics; 
	PositionComponent *m_position;	
	float m_rotation;
	sf::Time m_fadeTime = sf::seconds(0.00f);
};
