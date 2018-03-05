#pragma once
#include "GraphicsComponent.h"
#include "AnimatedSprite.h"
#include "Animation.h"
#include <iostream>
class AnimationGraphicsComponent : public GraphicsComponent
{
public:
	AnimationGraphicsComponent();
	AnimationGraphicsComponent(std::string texture, int offx = 0, int offy = 0, float scale = 0.5f, int size = 192);
	~AnimationGraphicsComponent();
	virtual void update(const sf::Time &time);
	virtual void draw(sf::RenderTexture& renderTexture);
	void initialize(std::string texture, int offx = 0, int offy = 0);
	void setPosition(sf::Vector2f position);
	void setScale(sf::Vector2f scale);
	bool updateOneFrame(const sf::Time &time);
private:
	AnimatedSprite m_animatedSprite;
	sf::Texture m_texture;
	Animation *m_currentAnimation;
	Animation m_objectAnimation;
	bool m_playing = false;
};
