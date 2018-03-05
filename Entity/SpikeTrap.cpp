#include "SpikeTrap.h"
#include "PlayerEntity.h"
#include "Entity.h"
#include "LifeComponent.h"
SpikeTrap::SpikeTrap()
{

}

SpikeTrap::SpikeTrap(PositionComponent * point, ManagersAccess *managerAccess)
{
	// Manager Access
	m_managerAccess = managerAccess;
	// Position Component
	m_position = point;
	// Graphics
	m_graphics = new FixedObjectGraphicsComponent("Sprite/trap.png", 2);
	m_graphics->setId(m_managerAccess->drawManager->subscribeUnderLayer(m_graphics));
	m_graphics->setPosition(*m_position);
	// SPIKE COMPONENT
	m_spike = new SpikeComponent();
	m_spike->initialize(m_managerAccess, 30);
	// BOUNDING BOX
	m_boudingBox = sf::FloatRect(m_position->x, m_position->y, 32, 32);
}

SpikeTrap::~SpikeTrap()
{
}

void SpikeTrap::update(sf::Time time)
{

	m_graphics->update(time);
	if (m_working)
	{
		//SPIKE UPDATE
		m_spike->update(m_boudingBox);
		if (m_spike->getEntityHit() != NULL)
		{
			m_spike->setDirection(m_boudingBox, m_managerAccess->entityManager->getPlayer()->getPosition());
			m_spike->getEntityHit()->getLifeComponent()->hit(m_spike->getDamage());
		}
		// ANIMATION UPDATE
		if(m_graphics->updateOneFrame(time))
		{
			m_numberFrame++;
			if (m_numberFrame > 3)
			{
				m_numberFrame = 0;
				m_working = false;
			}
		}
	}
	else
	{
		m_time += time;
		if (m_time > sf::seconds(1.0f))
		{
			m_working = true;
			m_time = sf::seconds(0.0f);
		}
	}
}
