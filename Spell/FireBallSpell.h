#pragma once
#include "Spell.h"
#include "ManagersAccess.h"
#include "Damage.h"
class FireBallSpell : public Spell
{
public:
	FireBallSpell();
	FireBallSpell(ManagersAccess *managerAccess, Damage damage);
	~FireBallSpell();
	virtual void cast(float rotation, const sf::Vector2f &position);
	virtual void update(const sf::Time &time);
private:
	ManagersAccess * m_managerAccess;
	Damage m_damage;
	bool m_isWaiting = false;
	float m_coolDown = 0.5f;
	sf::Time m_elapsed;
};
