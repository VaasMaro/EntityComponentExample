#pragma once
#include "ManagersAccess.h"
#include <SFML/Graphics.hpp>
#include "Damage.h"
class SpikeComponent
{
public:
	SpikeComponent();
	~SpikeComponent();
	void initialize(ManagersAccess * managerAccess, int damage = 50);
	void update(sf::FloatRect floatRect);
	Entity *getEntityHit();
	Damage getDamage() { return m_damage; }
	void setDirection(sf::FloatRect thisEntity, sf::Vector2f player);
	void setEnemy(bool b) { m_enemy = b; }
private:
	ManagersAccess *m_managerAccess;
	Entity *m_entityHit;
	Damage m_damage;
	bool m_enemy = true;
};
