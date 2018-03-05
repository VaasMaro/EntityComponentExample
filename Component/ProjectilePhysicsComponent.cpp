
#include "ProjectilePhysicsComponent.h"

ProjectilePhysicsComponent::ProjectilePhysicsComponent()
{

}

ProjectilePhysicsComponent::ProjectilePhysicsComponent(float speed)
{
	m_speed = speed;


}

ProjectilePhysicsComponent::~ProjectilePhysicsComponent()
{
	
}

void ProjectilePhysicsComponent::update(const sf::Time & time, PositionComponent & positionComponent)
{
	m_boundingBox.left = positionComponent.x - 8; // DEBUG
	m_boundingBox.top = positionComponent.y ;

	normalize();
	sf::FloatRect tempRect = sf::FloatRect(
		m_boundingBox.left + (m_velocity.x * time.asMilliseconds()),
		m_boundingBox.top + (m_velocity.y * time.asMilliseconds()),
		m_boundingBox.width,
		m_boundingBox.height);
	
	if (m_managerAccess->physicsHandler->solveBoxToTiles(tempRect))
	{
		// MOVE
		positionComponent.x = positionComponent.x + (m_velocity.x * time.asMilliseconds());
		positionComponent.y = positionComponent.y + (m_velocity.y * time.asMilliseconds());
	}
	else
	{
		m_touch = true;
	}
	if(m_entityHit == NULL) m_entityHit = m_managerAccess->physicsHandler->solveBoxtoHitBox(tempRect);
}

void ProjectilePhysicsComponent::initialize( ManagersAccess * managerAccess, const sf::Vector2f &direction)
{
	m_velocity = direction;
	m_boundingBox = sf::FloatRect(0, 0, 16, 16);
	m_managerAccess = managerAccess;
}

void ProjectilePhysicsComponent::normalize()
{
	float tempx, tempy;
	tempx = m_velocity.x;
	tempy = m_velocity.y;
	m_velocity.x = (m_velocity.x / sqrt((tempx * tempx) + (tempy * tempy))) * m_speed;
	m_velocity.y = (m_velocity.y / sqrt((tempx * tempx) + (tempy * tempy))) * m_speed;
}

bool ProjectilePhysicsComponent::isTouching()
{
	return m_touch;
}


void ProjectilePhysicsComponent::addHitBox(sf::FloatRect rect)
{
	m_hitBoxContainer.push_back(rect);
}
