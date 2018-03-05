#include "Weapon.h"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string name, Damage damage, int price) : m_name(name), m_damage(damage), m_price(price)
{

}

Weapon::~Weapon()
{

}