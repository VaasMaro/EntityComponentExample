#pragma once
#include "AnimatedSprite.h"
#include "GraphicsComponent.h"

class WeaponAnimatedSpriteComponent : public GraphicsComponent
{
public:
	WeaponAnimatedSpriteComponent();
	~WeaponAnimatedSpriteComponent();
	virtual void update(const sf::Time &time);
	virtual void draw(sf::RenderTexture& renderTexture);
	void setId(int id);
	int getId();

private:
	int m_id;
	AnimatedSprite m_animatedSprite;
	sf::Texture m_texture;
	Animation m_weaponAnimation;
	Animation m_strikeAnimation;
};
