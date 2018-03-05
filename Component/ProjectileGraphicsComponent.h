#pragma once
#include "GraphicsComponent.h"
#include "AnimatedSprite.h"
#include "Direction.h"
#include "Animation.h"
#include <iostream>
class ProjectileGraphicsComponent : public GraphicsComponent
{
public:
	ProjectileGraphicsComponent();
	ProjectileGraphicsComponent(std::string texture, int offx = 0, int offy = 0, int size = 32);
	~ProjectileGraphicsComponent();
	virtual void update(const sf::Time &time);
	virtual void draw(sf::RenderTexture& renderTexture);
	void initialize(std::string texture, int offx = 0, int offy = 0);
	void setPosition(sf::Vector2f position);
	void setRotation(float rotation);
private:
	AnimatedSprite m_animatedSprite;
	sf::Texture m_texture;
	Animation *m_currentAnimation;
	Animation m_projectileAnimation;
};
