#pragma once
#include "HumanAnimatedSpriteComponent.h"
#include "HumanPhysicsComponent.h"
#include <random>
class WalkerAIComponent
{
public:
	WalkerAIComponent();
	~WalkerAIComponent();
	void initialize(HumanAnimatedSpriteComponent *sprite,
		HumanPhysicsComponent *physic);
	void update(const sf::Time &time);
private:
	HumanAnimatedSpriteComponent *m_sprite;
	HumanPhysicsComponent *m_physics;
	sf::Time m_timeRoutine;
	int m_routineIterator;
	bool m_isWalking;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_real_distribution<double> dist;
};
