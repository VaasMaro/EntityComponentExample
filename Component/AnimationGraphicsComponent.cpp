#include "AnimationGraphicsComponent.h"

AnimationGraphicsComponent::AnimationGraphicsComponent()
{
}

AnimationGraphicsComponent::AnimationGraphicsComponent(std::string texture, int offx, int offy, float scale, int size)
{
	if (!m_texture.loadFromFile(texture))
	{
		std::cout << "issues AnimationGraphicsComponent " << std::endl;
	}
	m_texture.setSmooth(true);	
	m_objectAnimation.setSpriteSheet(m_texture);
	m_objectAnimation.addFrame(sf::IntRect(size * 0 + offx * 192, 0 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 1 + offx * 192, 0 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 2 + offx * 192, 0 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 3 + offx * 192, 0 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 4 + offx * 192, 0 + offy * 192, 192, 192));

	m_objectAnimation.addFrame(sf::IntRect(size * 0 + offx * 192, size * 1 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 1 + offx * 192, size * 1 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 2 + offx * 192, size * 1 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 3 + offx * 192, size * 1 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 4 + offx * 192, size * 1 + offy * 192, 192, 192));

	m_objectAnimation.addFrame(sf::IntRect(size * 0 + offx * 192, size * 2 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 1 + offx * 192, size * 2 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 2 + offx * 192, size * 2 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 3 + offx * 192, size * 2 + offy * 192, 192, 192));
	m_objectAnimation.addFrame(sf::IntRect(size * 4 + offx * 192, size * 2 + offy * 192, 192, 192));

	m_currentAnimation = &m_objectAnimation;
	m_animatedSprite = AnimatedSprite(sf::seconds(0.03), true, false);
	m_animatedSprite.setOrigin(size / 2, size / 2);
	m_animatedSprite.setScale(sf::Vector2f(scale, scale));
	
}

AnimationGraphicsComponent::~AnimationGraphicsComponent()
{

}

void AnimationGraphicsComponent::update(const sf::Time & time)
{
	// update AnimatedSprite
	m_animatedSprite.play(*m_currentAnimation);
	if(m_playing)m_animatedSprite.update(time);
}

void AnimationGraphicsComponent::draw(sf::RenderTexture & renderTexture)
{
	renderTexture.draw(m_animatedSprite);
}

void AnimationGraphicsComponent::initialize(std::string texture, int offx, int offy)
{
}

void AnimationGraphicsComponent::setPosition(sf::Vector2f position)
{
	m_animatedSprite.setPosition(position);
}

void AnimationGraphicsComponent::setScale(sf::Vector2f scale)
{
	m_animatedSprite.setScale(scale);
}

bool AnimationGraphicsComponent::updateOneFrame(const sf::Time & time)
{
	if (m_animatedSprite.update(time)) return true;
	else return false;
}
