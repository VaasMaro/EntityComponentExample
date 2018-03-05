#include "SpikeComponent.h"

SpikeComponent::SpikeComponent()
{
}

SpikeComponent::~SpikeComponent()
{
}

void SpikeComponent::initialize(ManagersAccess * managerAccess, int damage)
{
	m_managerAccess = managerAccess;
	m_entityHit = NULL;
	m_damage.physical = damage;
}

void SpikeComponent::update(sf::FloatRect floatRect)
{

	if(m_enemy)m_entityHit = m_managerAccess->physicsHandler->solveBoxtoPlayer(floatRect);
	else m_entityHit = m_managerAccess->physicsHandler->solveBoxtoHitBox(floatRect);
}

Entity * SpikeComponent::getEntityHit()
{
	return m_entityHit;
}

void SpikeComponent::setDirection(sf::FloatRect thisEntity, sf::Vector2f player)
{
	m_damage.direction = sf::Vector2f(thisEntity.top - thisEntity.left, player.y - player.x);
}
