#include "FireBall.h"
#include "LifeComponent.h"
#include "FireExplosion.h"
FireBall::FireBall()
{
}

FireBall::FireBall(PositionComponent * point, ProjectileGraphicsComponent * graphics, ProjectilePhysicsComponent * physics, Damage damage, ManagersAccess * managerAccess, const float & rotation)
{
	// manager Access
	m_managerAccess = managerAccess;
	// Rotation
	m_rotation = rotation;
	// Position Component
	m_position = point;
	// Graphics
	m_graphics = graphics;
	m_graphics->setId(m_managerAccess->drawManager->subscribe(m_graphics));
	m_graphics->setRotation(m_rotation - 90);
	// Damage
	m_rotation = (m_rotation + 90) * 0.01745329252; // degree to radian
	sf::Vector2f direction(sin(m_rotation), -cos(m_rotation));
	m_damage = damage;
	m_damage.direction = direction;
	// physics rotatio
	m_physics = physics;

	m_physics->initialize(m_managerAccess, direction);
	m_physics->setId(m_managerAccess->physicsHandler->subscribe(m_physics));
}

FireBall::~FireBall()
{
	delete m_position;
	m_managerAccess->physicsHandler->reject(m_physics->getId());
	delete m_physics;
	m_managerAccess->drawManager->reject(m_graphics->getId());
	delete m_graphics;
}

void FireBall::update(sf::Time time)
{
	if (m_physics->isTouching())
	{

		m_managerAccess->entityManager->create(new FireExplosion(new PositionComponent(m_position->x, m_position->y), m_managerAccess, m_damage));
		alive = false;
	}
	else
	{
		m_physics->update(time, *m_position);

	}
	m_graphics->setPosition(*m_position);
	m_graphics->update(time);
	if (m_physics->getEntityHit() != nullptr)
	{
		m_managerAccess->entityManager->create(new FireExplosion(new PositionComponent(m_position->x, m_position->y), m_managerAccess, m_damage));
		alive = false;
	}
}
