#include "WeaponComponent.h"

WeaponComponent::WeaponComponent()
{
}

WeaponComponent::~WeaponComponent()
{
}

void WeaponComponent::addWeapon(Weapon *weapon)
{
	m_weapon = weapon;
	m_equipped = true;
}

void WeaponComponent::setDirection(Direction order)
{
	m_direction = order;
}

void WeaponComponent::update(const sf::Time &time)
{
	if (m_isWaiting)
	{
		m_elapsed += time;
		if (m_elapsed.asSeconds() > m_coolDown)
		{
			m_isWaiting = false;
			m_elapsed = sf::seconds(0.0f);
		}
	}	
}

void WeaponComponent::strike(const sf::Vector2f &position, const float rotation)
{
	if (!m_isWaiting)
	{
		m_weapon->strike(rotation, position);
		m_isWaiting = true;
	}
}
