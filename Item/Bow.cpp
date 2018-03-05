#include "Bow.h"
#include "EntityManager.h"

Bow::Bow()
{

}

Bow::Bow(std::string name, Damage damage, int price, ManagersAccess *managerAccess) : Weapon(name, damage, price)
{
	m_managerAccess = managerAccess;
}

Bow::~Bow()
{

}

void Bow::strike(float rotation, const sf::Vector2f &position)
{
	m_managerAccess->entityManager->create(new Arrow(
		new PositionComponent(position.x + 16, position.y + 16),
		new ProjectileGraphicsComponent("Sprite/projectile001.png", 3, 6),
		new ProjectilePhysicsComponent(1.00f),
			m_damage, 
			m_managerAccess,
			rotation));	


}
