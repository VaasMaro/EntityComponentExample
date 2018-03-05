#pragma once
#include "Entity.h"
#include "AnimationGraphicsComponent.h"
#include "ManagersAccess.h"
#include "PositionComponent.h"
class UniqueAnimation : public Entity
{
public:
	UniqueAnimation();
	UniqueAnimation(ManagersAccess * managerAccess, PositionComponent *position);
	~UniqueAnimation();
	virtual void update(sf::Time time);
private:
	AnimationGraphicsComponent * m_graphics;
	ManagersAccess * m_managerAccess;
	PositionComponent * m_position;
	int m_numberFrame = 0;
};
