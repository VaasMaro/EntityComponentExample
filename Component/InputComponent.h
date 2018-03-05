#pragma once
#include "HumanAnimatedSpriteComponent.h"
#include "HumanPhysicsComponent.h"
#include "WeaponComponent.h"
#include "RotationComponent.h"
#include "SpellBookComponent.h"
class InputComponent
{
public:
	InputComponent();
	~InputComponent();
	void initialize(HumanAnimatedSpriteComponent *sprite,
		HumanPhysicsComponent *physic,
		WeaponComponent *weapon,
		PositionComponent *position,
		RotationComponent *rotation,
		SpellBookComponent * spellBook);
	void update();
private:
	sf::Vector2f m_lastMove;
	PositionComponent *m_position;
	HumanAnimatedSpriteComponent *m_sprite;
	HumanPhysicsComponent *m_physics;
	WeaponComponent *m_weapon;
	RotationComponent *m_rotation;
	SpellBookComponent * m_spellBook;
	bool m_noKeyPressed = true;
};
