#pragma once
#include "Item.h"
#include "Damage.h"
#include <iostream>
#include <SFML/Graphics.hpp>
class Weapon : public Item
{
public:
	Weapon();
	Weapon(std::string name, Damage damage, int price);
	~Weapon();
	virtual void strike(float rotation, const sf::Vector2f &position){}

protected:
	Damage m_damage;
	std::string m_name;
	int m_price;
};
