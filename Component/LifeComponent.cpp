#include "LifeComponent.h"

LifeComponent::LifeComponent()
{

}

LifeComponent::LifeComponent(int numberLife, int numberShield)
{
	m_numberLife = numberLife;
	m_numberShield = numberShield;
}

LifeComponent::~LifeComponent()
{

}

void LifeComponent::addLife(int life)
{
	m_numberLife += life;
}

void LifeComponent::addShield(int shield)
{
	m_numberShield += shield;
}

void LifeComponent::update()
{

}

void LifeComponent::hit(Damage damage)
{
	if (!m_invincible)
	{
		m_justHit = true;
		if (m_numberShield >= damage.physical)
		{
			m_numberShield -= damage.physical;
		}
		else
		{
			m_numberLife -= damage.physical - m_numberShield;
			m_numberShield = 0;
		}
		m_lastDamage = damage;

		if (m_numberLife <= 0) m_isDead = true;
		std::cout << m_numberLife << "/" << m_numberShield << std::endl;
	}

}

Damage LifeComponent::getLastDamage()
{
	m_justHit = false;
	return m_lastDamage;
}
