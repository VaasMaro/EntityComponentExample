#pragma once
#include "Spell.h"
#include "ManagersAccess.h"
#include "Damage.h"
class FireRaySpell : public Spell
{
public:
	FireRaySpell();
	FireRaySpell(ManagersAccess *managerAccess, Damage damage);
	~FireRaySpell();
	virtual void cast(float rotation, const sf::Vector2f &position);
	virtual void update(const sf::Time &time);
private:
	ManagersAccess * m_managerAccess;
	Damage m_damage;
};
