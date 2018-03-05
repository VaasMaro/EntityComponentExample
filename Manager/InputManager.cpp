#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

InputOrder InputManager::getOrder()
{
	return m_order;
}

void InputManager::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_order = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_order = RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_order = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_order = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_order = A;
	}
	else m_order = NONE;
}