#pragma once
#include "Weapon.h"
#include "Direction.h"
class WeaponComponent
{
public:
	WeaponComponent();
	~WeaponComponent();
	void addWeapon(Weapon *weapon);
	void setDirection(Direction order);
	void update(const sf::Time &time);
	void strike(const sf::Vector2f &position, const float rotation);
private:
	Weapon *m_weapon;
	bool m_equipped = false;
	Direction m_direction;
	bool m_isWaiting = false;
	float m_coolDown = 0.5f;
	sf::Time m_elapsed;
};
