#pragma once
#include "Damage.h"
#include <iostream>

class LifeComponent
{
public:
	LifeComponent();
	LifeComponent(int numberLife, int numberShield);
	~LifeComponent();
	void addLife(int life);
	void addShield(int shield);
	void update();
	void hit(Damage damage);
	Damage getLastDamage();
	bool isDead() { return m_isDead; }
	bool isHit() {return m_justHit;}
	bool isInvincible() { return m_invincible; }
	void setInvincible(bool b) { m_invincible = b; }
	int getLife() { return m_numberLife; }
	int getShield() { return m_numberShield; }
private:
	bool m_isDead = false;
	bool m_justHit = false;
	int m_numberLife;
	int m_numberShield;
	Damage m_lastDamage;
	bool m_invincible = false;
};
