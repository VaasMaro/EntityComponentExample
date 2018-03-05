#pragma once
#include <SFML/Graphics.hpp>
#include "InputOrder.h"

struct ManagersAccess;
class ViewManager
{
public:
	ViewManager();
	~ViewManager();
	void initialize(sf::RenderWindow &window, ManagersAccess *managerAccess);
	void update(sf::RenderWindow &window);
	void setMapLimit(int x, int y);
	sf::Vector2f getViewCenter() { return m_view.getCenter(); }
private:
	ManagersAccess*m_managerAccess;
	bool m_followPlayer = true;
	sf::View m_view;
	sf::Vector2i m_mapLimit;
};
