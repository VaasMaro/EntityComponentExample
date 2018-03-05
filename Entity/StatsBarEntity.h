#pragma once
#include "Entity.h"
#include "RectGraphicsComponent.h"
#include "PlayerEntity.h"
#include "PositionComponent.h"
class StatsBarEntity : public Entity
{
public:
	StatsBarEntity();
	~StatsBarEntity();
	void initialize(sf::Vector2f position, PlayerEntity *player, ManagersAccess *managerAccess);
	virtual void update(sf::Time time);
	void setPosition(sf::Vector2f position);
private:
	ManagersAccess *m_managerAccess;
	PositionComponent *m_position;
	PlayerEntity *m_player;
	RectGraphicsComponent * m_lifeRect;
	RectGraphicsComponent * m_lifeOverRect;
	RectGraphicsComponent * m_manaRect;
	RectGraphicsComponent * m_manaOverRect;
	float m_margin = 5.0f;
	float m_barSize = 16.0f;
	float m_widthFactor = 1.0f;
};
