#include "ZombieWalkerEnemy.h"
#include "PlayerEntity.h"
#include "UniqueAnimation.h"
ZombieWalkerEnemy::ZombieWalkerEnemy()
{
}

ZombieWalkerEnemy::ZombieWalkerEnemy(PositionComponent * position, ManagersAccess *managerAccess)
{
	m_managerAccess = managerAccess;

	//STATISTICS COMPONENT
	m_statistics = new StatisticsComponent(100, 10, 10, 10, 0.125f);
	// POSITION COMPONENT
	m_position = position;
	// GRAPHICS COMPONENT
	m_animatedSprite = new HumanAnimatedSpriteComponent();
	m_animatedSprite->initialize("Sprite/people03.png");
	m_animatedSprite->setId(m_managerAccess->drawManager->subscribe(m_animatedSprite));
	// PHYSICS COMPONENT
	m_physics = new HumanPhysicsComponent();
	m_physics->initialize(m_statistics->moveSpeed, m_managerAccess);
	m_physics->addHitBox();
	m_physics->setId(m_managerAccess->physicsHandler->subscribe(m_physics));
	m_physics->setEntity(this);
	// AI COMPONENT
	m_AI = new WalkerAIComponent();
	m_AI->initialize(m_animatedSprite, m_physics);
	// LIFE COMPONENT
	setLifeComponent(new LifeComponent(m_statistics->maxLifePoint, 10));
	// SPIKE COMPONENT
	m_spikeComponent = new SpikeComponent();
	m_spikeComponent->initialize(m_managerAccess, 30);
}

ZombieWalkerEnemy::~ZombieWalkerEnemy()
{
	delete m_position;
	delete m_statistics;
	m_managerAccess->physicsHandler->reject(m_physics->getId());
	delete m_physics;
	m_managerAccess->drawManager->reject(m_animatedSprite->getId());
	delete m_animatedSprite;
	delete m_AI;
	delete m_spikeComponent;
}

void ZombieWalkerEnemy::update(sf::Time time)
{
	m_AI->update(time);
	m_physics->update(time, *m_position);
	m_animatedSprite->setPosition(*m_position);
	m_animatedSprite->update(time);
	m_spikeComponent->update(m_physics->getBoundingBox());
	if (m_spikeComponent->getEntityHit() != NULL)
	{
		m_spikeComponent->setDirection(m_physics->getBoundingBox(),m_managerAccess->entityManager->getPlayer()->getPosition());
		m_spikeComponent->getEntityHit()->getLifeComponent()->hit(m_spikeComponent->getDamage());
	}
	if (m_lifeComponent->isHit())
	{
		m_physics->hit(m_lifeComponent->getLastDamage());
		m_animatedSprite->hit(m_lifeComponent->getLastDamage().physical);
	}
	if (m_lifeComponent->isDead())
	{
		m_managerAccess->entityManager->create(new UniqueAnimation(m_managerAccess, new PositionComponent(m_position->x + 16, m_position->y +16)));
		alive = false;
	}
}
