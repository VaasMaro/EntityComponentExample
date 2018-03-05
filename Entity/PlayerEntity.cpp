#include "PlayerEntity.h"
#include "LifeComponent.h"	
#include "FireBallSpell.h"
#include "FireRaySpell.h"
PlayerEntity::PlayerEntity()
{
}

PlayerEntity::PlayerEntity(ManagersAccess *managerAccess)
{
	m_managerAccess = managerAccess;

	//STATISTICS COMPONENT
	m_statistics = new StatisticsComponent(100, 100, 10, 10, 0.30f);
	// POSITION COMPONENT
	m_position = new PositionComponent;
	m_position->x = 128.0f;
	m_position->y = 128.0f;
	// GRAPHICS COMPONENT
	m_animatedSprite = new HumanAnimatedSpriteComponent();
	m_animatedSprite->initialize("Sprite/Evil.png", 9, 4);
	m_animatedSprite->setId(m_managerAccess->drawManager->subscribe(m_animatedSprite));
	// PHYSICS COMPONENT
	m_physics = new HumanPhysicsComponent();
	m_physics->initialize(m_statistics->moveSpeed, m_managerAccess);
	m_physics->addHitBox();
	m_managerAccess->physicsHandler->subscribePlayer(m_physics);
	m_physics->setEntity(this);
	// WEAPON COMPONENT
	m_weapon = new WeaponComponent();
	m_weapon->addWeapon(new Bow("Bow", Damage(40), 100, m_managerAccess));
	// SPELL BOOK COMPONENT
	m_spellBook = new SpellBookComponent();
	m_spellBook->initialize(m_managerAccess);
	m_spellBook->addSpell(new FireBallSpell(m_managerAccess, Damage(80)));
	m_spellBook->addSpell(new FireRaySpell(m_managerAccess, Damage(5)));
	// MOUSE POINTER
	m_mouse = new MousePointerComponent();
	m_mouse->initialize(m_managerAccess);
	// ROTATION COMPONENT
	m_rotation = new RotationComponent();
	// INPUT
	m_input = new InputComponent();
	m_input->initialize(m_animatedSprite, m_physics, m_weapon, m_position, m_rotation, m_spellBook);
	// LIFECOMPONENT
	setLifeComponent(new LifeComponent(m_statistics->maxLifePoint, 0));
}


PlayerEntity::~PlayerEntity()
{
	delete m_position;
	delete m_statistics;
	m_managerAccess->physicsHandler->rejectPlayer();
	delete m_physics;
	m_managerAccess->drawManager->reject(m_animatedSprite->getId());
	delete m_animatedSprite;
}

void PlayerEntity::update(sf::Time time)
{
	//update
	m_input->update();
	m_mouse->update(*m_position);

	sf::Vector2i pixelPos = m_managerAccess->drawManager->getWindow()->mapCoordsToPixel(*m_position);
	m_rotation->update(sf::Vector2f(m_mouse->getPosition().x, m_mouse->getPosition().y), sf::Vector2f(pixelPos.x, pixelPos.y));

	m_physics->update(time, *m_position);
	m_animatedSprite->setPosition(*m_position);
	m_animatedSprite->update(time);
	m_weapon->update(time);

	// LIFE COMPONENT
	if (m_lifeComponent->isHit() && !m_lifeComponent->isInvincible())
	{
		m_lifeComponent->setInvincible(true);
		m_physics->hit(m_lifeComponent->getLastDamage());
		m_animatedSprite->hit(m_lifeComponent->getLastDamage().physical);
	}
	if (m_lifeComponent->isInvincible())
	{
		m_frameCount--;
		
		if (m_frameCount <= 0)
		{
			m_frameCount = m_maxFrame;
			m_lifeComponent->setInvincible(false);
		}
	}
	m_spellBook->update(time);
	//if (m_lifeComponent->isDead()) alive = false;
}

int PlayerEntity::getNumberLife()
{
	
	return m_lifeComponent->getLife();
}

int PlayerEntity::getNumberMana()
{
	return m_statistics->maxManaPoint;
}

int PlayerEntity::getMaximumLife()
{
	
	return m_statistics->maxLifePoint;
}

int PlayerEntity::getMaximumMana()
{
	return m_statistics->maxManaPoint;
}
