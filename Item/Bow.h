#pragma once
#include "Weapon.h"
#include "ManagersAccess.h"
#include "Arrow.h"
class Bow : public Weapon
{
public:
	Bow();
	Bow(std::string name, Damage damage, int price, ManagersAccess *managerAccess);
	~Bow();
	virtual void strike(float rotation, const sf::Vector2f &position);
private:
	ManagersAccess * m_managerAccess;
};
