#include "MousePointerComponent.h"

MousePointerComponent::MousePointerComponent()
{

}

MousePointerComponent::~MousePointerComponent()
{
}

void MousePointerComponent::initialize(ManagersAccess * managerAccess)
{
	m_managerAccess = managerAccess;
}

void MousePointerComponent::update(const sf::Vector2f &position)
{
	m_mousePosition = sf::Mouse::getPosition(*m_managerAccess->drawManager->getWindow());
	//m_mousePosition = sf::Mouse::getPosition();
	//std::cout << "cursor position :" << m_mousePosition.x << "/" << m_mousePosition.y << std::endl;
}

sf::Vector2i MousePointerComponent::getPosition()
{
	return m_mousePosition;
}
