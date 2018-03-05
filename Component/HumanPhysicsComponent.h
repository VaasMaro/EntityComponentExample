#pragma once
#include "InputOrder.h"
#include "PositionComponent.h"
#include "ManagersAccess.h"
#include "PhysicsComponent.h"

#include "Damage.h"
class HumanPhysicsComponent : public PhysicsComponent
{
public:
	HumanPhysicsComponent();
	~HumanPhysicsComponent();
	void update(const sf::Time &time, PositionComponent &positionComponent);
	void initialize(float speed, ManagersAccess *managerAccess);
	void setOrder(const InputOrder &order);
	void resetVelocity();
	void move(float x, float y);
	void normalize(); 
	void addHitBox();
	virtual void addHitBox(sf::FloatRect rect);
	virtual std::vector<sf::FloatRect> getHitBoxContainer() { return m_hitBoxContainer; }
	sf::FloatRect getBoundingBox() { return m_boundingBox; }
	void hit(const Damage &damage);
	void impulse(sf::Vector2f direction, float strenght, int numberFrame);
	bool isImpulsed() { return m_impulsed; }
private:
	InputOrder m_order = NONE;
	float m_speed;
	sf::Vector2f m_velocity;
	sf::FloatRect m_boundingBox;
	ManagersAccess *m_managerAccess;
	sf::FloatRect tempRectX;
	sf::FloatRect tempRectY;
	// impulse system
	bool m_impulsed = false;
	int m_numberFrameImpulse = 10;
	float m_tempSpeed;
	float m_impulseSpeed = 0;
	sf::Vector2f m_imulseDirection;
};
