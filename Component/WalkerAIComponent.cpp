#include "WalkerAIComponent.h"

WalkerAIComponent::WalkerAIComponent()
{
	m_timeRoutine = sf::seconds(0.0f);
	m_routineIterator = 0;
	m_isWalking = true;
}

WalkerAIComponent::~WalkerAIComponent()
{
}

void WalkerAIComponent::initialize(HumanAnimatedSpriteComponent * sprite, HumanPhysicsComponent * physic)
{
	m_sprite = sprite;
	m_physics = physic;

	mt = std::mt19937(rd());
	dist = std::uniform_real_distribution<double>(0.0, 3.0);
}

void WalkerAIComponent::update(const sf::Time & time)
{
	if (m_timeRoutine < sf::seconds(1.0f))
	{
		m_timeRoutine += time;
		if (m_isWalking)
		{
			m_sprite->setIsPlaying(true);
			if (m_routineIterator == 0)
			{
				m_physics->move(0, -1);
				m_sprite->setDirection(DIR_UP);
				
			}
			if (m_routineIterator == 1)
			{
				m_physics->move(0, 1);
				m_sprite->setDirection(DIR_DOWN);
			}
			if (m_routineIterator == 2)
			{
				m_physics->move(-1, 0);
				m_sprite->setDirection(DIR_LEFT);
			}
			if (m_routineIterator == 3)
			{
				m_physics->move(1, 0);
				m_sprite->setDirection(DIR_RIGHT);
			}
		}
		else
		{
			m_sprite->setIsPlaying(false);
		}
	}
	else
	{
		m_isWalking = !m_isWalking;
		m_timeRoutine = sf::seconds(0.0f);
		if (m_isWalking)
		{
			m_routineIterator = dist(mt);
		}
	}

}

