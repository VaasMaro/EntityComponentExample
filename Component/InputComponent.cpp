#include "InputComponent.h"

InputComponent::InputComponent()
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::initialize(HumanAnimatedSpriteComponent * sprite, HumanPhysicsComponent * physic, WeaponComponent * weapon, PositionComponent *position, RotationComponent *rotation, SpellBookComponent * spellbook)
{
	m_sprite = sprite;
	m_weapon = weapon;
	m_physics = physic;
	m_position = position;
	m_rotation = rotation;
	m_spellBook = spellbook;
}

void InputComponent::update()
{
	m_sprite->setIsPlaying(true);
	m_noKeyPressed = true;

	if (!m_physics->isImpulsed())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			m_physics->move(0, -1);
			m_lastMove.y = -1;
			m_sprite->setDirection(DIR_UP);
			m_noKeyPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_physics->move(0, 1);
			m_lastMove.y = 1;
			m_sprite->setDirection(DIR_DOWN);
			m_noKeyPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			m_physics->move(-1, 0);
			m_lastMove.x = -1;
			m_sprite->setDirection(DIR_LEFT);
			m_noKeyPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_physics->move(1, 0);
			m_lastMove.x = 1;
			m_sprite->setDirection(DIR_RIGHT);
			m_noKeyPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_physics->impulse(m_lastMove, 1.5f, 4);
			m_noKeyPressed = false;
			m_lastMove.x = 0;
			m_lastMove.y = 0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_spellBook->cast(0, m_rotation->getRotation(), sf::Vector2f(m_position->x, m_position->y));
		m_noKeyPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		m_spellBook->cast(1, m_rotation->getRotation(), sf::Vector2f(m_position->x, m_position->y));
		m_noKeyPressed = false;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_weapon->strike(sf::Vector2f(m_position->x, m_position->y), m_rotation->getRotation());
		m_noKeyPressed = false;
	}
	if(m_noKeyPressed)
	{
		m_sprite->setIsPlaying(false);
	}


}
