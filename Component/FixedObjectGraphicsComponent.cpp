#include "FixedObjectGraphicsComponent.h"

FixedObjectGraphicsComponent::FixedObjectGraphicsComponent()
{
}

FixedObjectGraphicsComponent::FixedObjectGraphicsComponent(std::string texture, int offx, int offy )
{
	if (!m_texture.loadFromFile(texture))
	{
		std::cout << "issues ProjectileGraphicsComponent " << std::endl;
	}

	m_objectAnimation.setSpriteSheet(m_texture);
	m_objectAnimation.addFrame(sf::IntRect(0 + offx * 32, 0 + offy * 32, 32, 32));
	m_objectAnimation.addFrame(sf::IntRect(0 + offx * 32, 32 + offy * 32, 32, 32));
	m_objectAnimation.addFrame(sf::IntRect(0 + offx * 32, 64 + offy * 32, 32, 32));
	m_objectAnimation.addFrame(sf::IntRect(0 + offx * 32, 32 + offy * 32, 32, 32));

	m_currentAnimation = &m_objectAnimation;
	m_animatedSprite = AnimatedSprite(sf::seconds(0.1), true, false);
}

FixedObjectGraphicsComponent::~FixedObjectGraphicsComponent()
{
}

void FixedObjectGraphicsComponent::update(const sf::Time & time)
{
	// update AnimatedSprite
	m_animatedSprite.play(*m_currentAnimation);
	if (m_playing) m_animatedSprite.update(time);
}

void FixedObjectGraphicsComponent::draw(sf::RenderTexture & renderTexture)
{
	renderTexture.draw(m_animatedSprite);
}

void FixedObjectGraphicsComponent::initialize(std::string texture, int offx, int offy)
{
}

void FixedObjectGraphicsComponent::setPosition(sf::Vector2f position)
{
	m_animatedSprite.setPosition(position);
}

bool FixedObjectGraphicsComponent::updateOneFrame(const sf::Time &time)
{
	if (m_animatedSprite.update(time)) return true; 
	else return false;
}
