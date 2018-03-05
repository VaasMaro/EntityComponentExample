#include "FireBallSpell.h"
#include "FireBall.h"
FireBallSpell::FireBallSpell()
{
}

FireBallSpell::FireBallSpell(ManagersAccess *managerAccess, Damage damage)
{
	m_managerAccess = managerAccess;
	m_damage = damage;
}

FireBallSpell::~FireBallSpell()
{
}

void FireBallSpell::cast(float rotation, const sf::Vector2f &position)
{

	if (!m_isWaiting)
	{
		m_managerAccess->entityManager->create(new FireBall(
			new PositionComponent(position.x + 16, position.y + 16),
			new ProjectileGraphicsComponent("Sprite/lightbroke.png", 9, 0),
			new ProjectilePhysicsComponent(1.00f),
			m_damage,
			m_managerAccess,
			rotation));
		m_isWaiting = true;
	}

}

void FireBallSpell::update(const sf::Time & time)
{
	if (m_isWaiting)
	{
		m_elapsed += time;
		if (m_elapsed.asSeconds() >= m_coolDown)
		{
			m_isWaiting = false;
			m_elapsed = sf::seconds(0.0f);
		}
	}
}
