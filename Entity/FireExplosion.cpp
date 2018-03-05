#include "FireExplosion.h"
#include "PlayerEntity.h"
#include "LifeComponent.h"
FireExplosion::FireExplosion()
{
}

FireExplosion::FireExplosion(PositionComponent * point, ManagersAccess * managerAccess, Damage damage)
{
	float scale = 0.7f;
	float size = 192 * scale;
	m_managerAccess = managerAccess;
	// Position Component
	m_position = point;
	// Graphics
	m_graphics = new AnimationGraphicsComponent("Sprite/special2.png", 0, 0, scale);
	m_graphics->setId(m_managerAccess->drawManager->subscribe(m_graphics));
	m_graphics->setPosition(*m_position);
	// SPIKE COMPONENT
	m_spike = new SpikeComponent();
	m_spike->initialize(m_managerAccess, damage.physical);
	m_spike->setEnemy(false);
	// BOUNDING BOX
	m_boudingBox = sf::FloatRect(m_position->x - size / 2, m_position->y - size / 2, size, size);
	// DAMAGE 
	m_damage = damage;

}


FireExplosion::FireExplosion(PositionComponent * point, AnimationGraphicsComponent * graphics, ProjectilePhysicsComponent * physics, Damage damage, ManagersAccess * managerAccess)
{
	m_managerAccess = managerAccess;
	// Position Component
	m_position = point;
	// Graphics
	m_graphics = new AnimationGraphicsComponent("Sprite/special2.png");
	m_graphics->setId(m_managerAccess->drawManager->subscribe(m_graphics));
	m_graphics->setPosition(*m_position);
}

FireExplosion::~FireExplosion()
{
	delete m_position;
	m_managerAccess->drawManager->reject(m_graphics->getId());
	delete m_graphics;
	delete m_spike;
}

void FireExplosion::update(sf::Time time)
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
			//SPIKE UPDATE
	m_spike->update(m_boudingBox);
	if (m_spike->getEntityHit() != NULL)
	{
		m_spike->setDirection(m_boudingBox, m_managerAccess->entityManager->getPlayer()->getPosition());
		m_spike->getEntityHit()->getLifeComponent()->hit(m_spike->getDamage());
	}


}
