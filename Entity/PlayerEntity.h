#pragma once
#include "HumanAnimatedSpriteComponent.h"
#include "PositionComponent.h"
#include "HumanPhysicsComponent.h"
#include "StatisticsComponent.h"
#include "WeaponComponent.h"
#include "SpellBookComponent.h"
#include "InputComponent.h"
#include "Bow.h"
#include "MousePointerComponent.h"
#include "RotationComponent.h"
class PlayerEntity : public Entity
{
public:
	PlayerEntity();
	PlayerEntity(ManagersAccess *managerAccess);
	~PlayerEntity();
	virtual void update(sf::Time time);
	sf::Vector2f getPosition() { return sf::Vector2f(m_position->x - 16, m_position->y - 16); }
	int getNumberLife();
	int getNumberMana();
	int getMaximumLife();
	int getMaximumMana();

private:
	ManagersAccess *m_managerAccess;
	// Components
	HumanAnimatedSpriteComponent *m_animatedSprite;
	PositionComponent *m_position;
	HumanPhysicsComponent *m_physics;
	StatisticsComponent *m_statistics;
	WeaponComponent *m_weapon;
	SpellBookComponent *m_spellBook;
	InputComponent *m_input;
	MousePointerComponent *m_mouse;
	RotationComponent *m_rotation;

	// invincibilité
	int m_maxFrame = 20;
	int m_frameCount;
};
