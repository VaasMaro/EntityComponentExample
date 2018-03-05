#include "HumanPhysicsComponent.h"

HumanPhysicsComponent::HumanPhysicsComponent()
{
	resetVelocity();
}

HumanPhysicsComponent::~HumanPhysicsComponent()
{

}

void HumanPhysicsComponent::update(const sf::Time &time, PositionComponent &positionComponent)
{
	// UPDATE INITIALIZE
	m_boundingBox.left = positionComponent.x;
	m_boundingBox.top = positionComponent.y;
	if (!m_hitBoxContainer.empty())
	{
		m_hitBoxContainer[0].left = positionComponent.x;
		m_hitBoxContainer[0].top = positionComponent.y;
	}
	if (m_impulsed)
	{
		if (m_numberFrameImpulse > 0)
		{
			m_velocity = m_imulseDirection;
			m_numberFrameImpulse--;
			m_tempSpeed = m_impulseSpeed;
		}
		else
		{
			m_impulseSpeed = 0;
			m_tempSpeed = m_speed;
			m_impulsed = false;
		}
	}
	else m_tempSpeed = m_speed;

	//TRY
	if (m_velocity.x != 0 || m_velocity.y != 0)
	{
		normalize();
		tempRectX = sf::FloatRect(
			m_boundingBox.left + (m_velocity.x * time.asMilliseconds()),
			m_boundingBox.top, 
			m_boundingBox.width, 
			m_boundingBox.height);
		tempRectY = sf::FloatRect(
			m_boundingBox.left,
			m_boundingBox.top + (m_velocity.y * time.asMilliseconds()),
			m_boundingBox.width,
			m_boundingBox.height);

		if (m_managerAccess->physicsHandler->solveBoxToTiles(tempRectX))
		{
			// MOVE
			positionComponent.x = positionComponent.x + (m_velocity.x * time.asMilliseconds());
		}
		if (m_managerAccess->physicsHandler->solveBoxToTiles(tempRectY))
		{
			// MOVE
			positionComponent.y = positionComponent.y + (m_velocity.y * time.asMilliseconds());
		}
	}
	resetVelocity();



}

void HumanPhysicsComponent::initialize(float speed, ManagersAccess *managerAccess)
{
	m_speed = speed;
	m_tempSpeed = speed;
	m_boundingBox = sf::FloatRect(0, 0, 32, 32);
	m_managerAccess = managerAccess;
}

void HumanPhysicsComponent::setOrder(const InputOrder &order)
{
	m_order = order;
}

void HumanPhysicsComponent::resetVelocity()
{
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;
}

void HumanPhysicsComponent::move(float x, float y)
{
	if (!m_impulsed)
	{
		m_velocity.x += x;
		m_velocity.y += y;
	}

}

void HumanPhysicsComponent::normalize()
{
	float tempx, tempy;
	tempx = m_velocity.x;
	tempy = m_velocity.y;
	m_velocity.x = (m_velocity.x / sqrt((tempx * tempx) + (tempy * tempy)) ) * m_tempSpeed;
	m_velocity.y = (m_velocity.y / sqrt((tempx * tempx) + (tempy * tempy)) ) * m_tempSpeed;
	
}

void HumanPhysicsComponent::addHitBox()
{
	m_hitBoxContainer.push_back(m_boundingBox);
	
}

void HumanPhysicsComponent::addHitBox(sf::FloatRect rect)
{
	m_hitBoxContainer.push_back(rect);

}

void HumanPhysicsComponent::hit(const Damage & damage)
{
	impulse(damage.direction, 0.150f + damage.physical / 100, 7 + damage.physical / 50);
}

void HumanPhysicsComponent::impulse(sf::Vector2f direction, float strenght, int numberFrame)
{
	m_impulsed = true;
	m_impulseSpeed = strenght;
	m_imulseDirection = direction;
	m_numberFrameImpulse = numberFrame;
}
