#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ManagersAccess.h"
class MousePointerComponent
{
public:
	MousePointerComponent();
	~MousePointerComponent();
	void initialize(ManagersAccess *managerAccess);
	void update(const sf::Vector2f &position);
	sf::Vector2i getPosition();
private:
	ManagersAccess *m_managerAccess;
	sf::Vector2i m_mousePosition;
};
