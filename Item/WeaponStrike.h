#pragma once
#include "Entity.h"
#include "Damage.h"
class WeaponStrike
{
public:
	WeaponStrike();
	~WeaponStrike();

private:
	Damage *m_damage;
};
