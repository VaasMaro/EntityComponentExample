#pragma once
#include "Entity.h"
#include "FixedObjectGraphicsComponent.h"
#include "PositionComponent.h"
#include "ManagersAccess.h"
#include "SpikeComponent.h"
class SpikeTrap : public Entity
{
public:
	SpikeTrap();
	SpikeTrap(PositionComponent *point, ManagersAccess *managerAccess);
	~SpikeTrap();
	virtual void update(sf::Time time);
private:
	
	FixedObjectGraphicsComponent * m_graphics;
	PositionComponent * m_position;
	SpikeComponent *m_spike;
	ManagersAccess *m_managerAccess;
	sf::FloatRect m_boudingBox;
	sf::Time m_time = sf::seconds(0.0f);
	bool m_working = false;
	int m_numberFrame = 0;
};
