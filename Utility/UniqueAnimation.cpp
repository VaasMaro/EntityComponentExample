#include "UniqueAnimation.h"

UniqueAnimation::UniqueAnimation()
{

}

UniqueAnimation::UniqueAnimation(ManagersAccess * managerAccess, PositionComponent * position)
{
	m_managerAccess = managerAccess;
	// Position Component
	m_position = position;
	// Graphics
	m_graphics = new AnimationGraphicsComponent("Sprite/State1.png", 0, 0, 0.5f);
	m_graphics->setId(m_managerAccess->drawManager->subscribe(m_graphics));
	m_graphics->setPosition(*m_position);
	
}

UniqueAnimation::~UniqueAnimation()
{
	delete m_position;
	m_managerAccess->drawManager->reject(m_graphics->getId());
	delete m_graphics;
}

void UniqueAnimation::update(sf::Time time)
{
	m_graphics->update(time);
	if (m_graphics->updateOneFrame(time))
	{
		m_numberFrame++;
		if (m_numberFrame > 14)
		{
			alive = false;
		}
	}

}
