#include "FireRaySpell.h"
#include "FireRay.h"
FireRaySpell::FireRaySpell()
{
}

FireRaySpell::FireRaySpell(ManagersAccess * managerAccess, Damage damage)
{
	m_managerAccess = managerAccess;
	m_damage = damage;
}

FireRaySpell::~FireRaySpell()
{

}

void FireRaySpell::cast(float rotation, const sf::Vector2f & position)
{
	m_managerAccess->entityManager->create(new FireRay(
		new PositionComponent(position.x + 16, position.y + 16),
		new ProjectileGraphicsComponent("Sprite/lightbroke.png", 9, 1),
		new ProjectilePhysicsComponent(1.00f),
		m_damage,
		m_managerAccess,
		rotation));
}

void FireRaySpell::update(const sf::Time & time)
{

}
