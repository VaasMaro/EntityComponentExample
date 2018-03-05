#pragma once
#include "Animation.h"
#include "GraphicsComponent.h"
#include "AnimatedSprite.h"
#include "Direction.h"
#include "Log.h"
#include <iostream>

class HumanAnimatedSpriteComponent : public GraphicsComponent
{
public:
	HumanAnimatedSpriteComponent();
	~HumanAnimatedSpriteComponent();
	virtual void update(const sf::Time &time);
	virtual void draw(sf::RenderTexture& renderTexture);
	void initialize(std::string texture, int offx = 0, int offy = 0);
	void setPosition(sf::Vector2f position);
	void setDirection(const Direction &dir);
	Direction getDirection();
	sf::FloatRect getBoundingBox();
	virtual void setId(int id);
	virtual int getId();
	void setIsPlaying(bool b);
	void hit(int damage);
private:
	Direction m_direction = DIR_DOWN;
	AnimatedSprite m_animatedSprite;
	sf::Texture m_texture;
	Animation *m_currentAnimation;
	Animation m_walkingAnimationDown;
	Animation m_walkingAnimationLeft;
	Animation m_walkingAnimationRight;
	Animation m_walkingAnimationUp;
	bool m_isPlaying;

	// impulse system
	bool m_hit = false;
	int m_numberFrameImpulse = 0;
};
