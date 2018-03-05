#include "ViewManager.h"
#include "ManagersAccess.h"
#include "PlayerEntity.h"

ViewManager::ViewManager()
{
}

void ViewManager::initialize(sf::RenderWindow &window, ManagersAccess *managerAccess)
{
	m_view = window.getDefaultView();
	m_managerAccess = managerAccess;
	m_view.zoom(0.7);
}

ViewManager::~ViewManager()
{
}

void ViewManager::update(sf::RenderWindow &window)
{
	if (m_followPlayer)m_view.setCenter(m_managerAccess->entityManager->getPlayer()->getPosition());

	// tester si la camera en x est en dessous de zero
	if ((m_view.getCenter().x - m_view.getSize().x / 2) < 0) m_view.setCenter(m_view.getSize().x / 2 ,m_view.getCenter().y);
	// tester si la camera en y est en dessous de zero
	if ((m_view.getCenter().y - m_view.getSize().y / 2) < 0) m_view.setCenter(m_view.getCenter().x , m_view.getSize().y / 2);
	// tester si la camera en x ne depasse pas la taille de la map
	if ((m_view.getCenter().x + m_view.getSize().x / 2) > m_mapLimit.x) m_view.setCenter(m_mapLimit.x - m_view.getSize().x / 2, m_view.getCenter().y);
	// tester si la camera en y ne depasse pas la taille de la map
	if ((m_view.getCenter().y + m_view.getSize().y / 2) > m_mapLimit.y) m_view.setCenter(m_view.getCenter().x, m_mapLimit.y - m_view.getSize().y / 2);
	window.setView(m_view);
}

void ViewManager::setMapLimit(int x, int y)
{
	m_mapLimit.x = x;
	m_mapLimit.y = y;
}
