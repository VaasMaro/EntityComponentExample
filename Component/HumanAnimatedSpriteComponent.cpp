#include "HumanAnimatedSpriteComponent.h"
#include "HeatShader.h"
HumanAnimatedSpriteComponent::HumanAnimatedSpriteComponent()
{


}


HumanAnimatedSpriteComponent::~HumanAnimatedSpriteComponent()
{

}

void HumanAnimatedSpriteComponent::initialize(std::string textName, int offx, int offy)
{

	if (!m_texture.loadFromFile(textName))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
	}	

	m_walkingAnimationDown.setSpriteSheet(m_texture);
	m_walkingAnimationDown.addFrame(sf::IntRect(32 + offx * 32, 0 + offy * 32, 32, 32));
	m_walkingAnimationDown.addFrame(sf::IntRect(64 + offx * 32, 0 + offy * 32, 32, 32));
	m_walkingAnimationDown.addFrame(sf::IntRect(32 + offx * 32, 0 + offy * 32, 32, 32));
	m_walkingAnimationDown.addFrame(sf::IntRect(0 + offx * 32, 0 + offy * 32, 32, 32));

	m_walkingAnimationLeft.setSpriteSheet(m_texture);
	m_walkingAnimationLeft.addFrame(sf::IntRect(32 + offx * 32, 32 + offy * 32, 32, 32));
	m_walkingAnimationLeft.addFrame(sf::IntRect(64 + offx * 32, 32 + offy * 32, 32, 32));
	m_walkingAnimationLeft.addFrame(sf::IntRect(32 + offx * 32, 32 + offy * 32, 32, 32));
	m_walkingAnimationLeft.addFrame(sf::IntRect(0 + offx * 32, 32 + offy * 32, 32, 32));

	m_walkingAnimationRight.setSpriteSheet(m_texture);
	m_walkingAnimationRight.addFrame(sf::IntRect(32 + offx * 32, 64 + offy * 32, 32, 32));
	m_walkingAnimationRight.addFrame(sf::IntRect(64 + offx * 32, 64 + offy * 32, 32, 32));
	m_walkingAnimationRight.addFrame(sf::IntRect(32 + offx * 32, 64 + offy * 32, 32, 32));
	m_walkingAnimationRight.addFrame(sf::IntRect(0 + offx * 32, 64 + offy * 32, 32, 32));

	m_walkingAnimationUp.setSpriteSheet(m_texture);
	m_walkingAnimationUp.addFrame(sf::IntRect(32 + offx * 32, 96 + offy * 32, 32, 32));
	m_walkingAnimationUp.addFrame(sf::IntRect(64 + offx * 32, 96 + offy * 32, 32, 32));
	m_walkingAnimationUp.addFrame(sf::IntRect(32 + offx * 32, 96 + offy * 32, 32, 32));
	m_walkingAnimationUp.addFrame(sf::IntRect(0 + offx * 32, 96 + offy * 32, 32, 32));

	m_currentAnimation = &m_walkingAnimationDown;
	m_animatedSprite = AnimatedSprite(sf::seconds(0.1), true, false);
	
}

void HumanAnimatedSpriteComponent::update(const sf::Time& time)
{
	if (m_direction == DIR_UP)
	{
		m_currentAnimation = &m_walkingAnimationUp;
	}
	else if (m_direction == DIR_DOWN)
	{
		m_currentAnimation = &m_walkingAnimationDown;
	}
	else if (m_direction == DIR_LEFT)
	{
		m_currentAnimation = &m_walkingAnimationLeft;
	}
	else if (m_direction == DIR_RIGHT)
	{
		m_currentAnimation = &m_walkingAnimationRight;
	}

	if (!m_isPlaying)
	{
		m_animatedSprite.stop();
	}

	if (m_hit)
	{
		if (m_numberFrameImpulse > 0)
		{
			m_numberFrameImpulse--;
			m_animatedSprite.setColor(sf::Color::Red);
		}
		else
		{
			m_animatedSprite.setColor(sf::Color(255, 255, 255, 255));
			m_hit = false;
		}
	}
	else;
	// update AnimatedSprite
	m_animatedSprite.play(*m_currentAnimation);
	m_animatedSprite.update(time);
}

void HumanAnimatedSpriteComponent::draw(sf::RenderTexture& renderTexture)
{
	renderTexture.draw(m_animatedSprite);
}

void HumanAnimatedSpriteComponent::setPosition(sf::Vector2f position)
{
	m_animatedSprite.setPosition(position);

}

void HumanAnimatedSpriteComponent::setDirection(const Direction &dir)
{
	m_direction = dir;

}

Direction HumanAnimatedSpriteComponent::getDirection()
{
	return m_direction;
}

sf::FloatRect HumanAnimatedSpriteComponent::getBoundingBox()
{
	return m_animatedSprite.getGlobalBounds();
}

void HumanAnimatedSpriteComponent::setId(int id)
{
	m_id = id;
}

int HumanAnimatedSpriteComponent::getId()
{
	return m_id;
}

void HumanAnimatedSpriteComponent::setIsPlaying(bool b)
{
	m_isPlaying = b;
}

void HumanAnimatedSpriteComponent::hit(int damage)
{
	m_hit = true;
	m_numberFrameImpulse = 7 + damage / 50;
}


