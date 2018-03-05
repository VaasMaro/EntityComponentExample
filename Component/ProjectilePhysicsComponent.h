#pragma once
#include "ManagersAccess.h"
#include "PositionComponent.h"
#include "PhysicsComponent.h"
class ProjectilePhysicsComponent : public PhysicsComponent
{
public:
	ProjectilePhysicsComponent();
	ProjectilePhysicsComponent(float speed);
	~ProjectilePhysicsComponent();
	void update(const sf::Time &time, PositionComponent &positionComponent);
	void initialize(ManagersAccess *managerAccess, const sf::Vector2f &direction);
	void normalize();
	bool isTouching();
	virtual void addHitBox(sf::FloatRect rect);
	virtual std::vector<sf::FloatRect> getHitBoxContainer() { return m_hitBoxContainer; }
	Entity * getEntityHit() { return m_entityHit; }
private:
	float m_speed;
	sf::Vector2f m_velocity;
	sf::FloatRect m_boundingBox;
	ManagersAccess *m_managerAccess;
	bool m_touch = false;
	Entity * m_entityHit = NULL;

};
