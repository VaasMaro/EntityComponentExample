#include "ProjectileGraphicsComponent.h"

ProjectileGraphicsComponent::ProjectileGraphicsComponent()
{
}

ProjectileGraphicsComponent::ProjectileGraphicsComponent(std::string texture, int offx, int offy, int size)
{
	if (!m_texture.loadFromFile(texture))
	{
		std::cout << "issues ProjectileGraphicsComponent " << std::endl;
	}

	m_projectileAnimation.setSpriteSheet(m_texture);
	m_projectileAnimation.addFrame(sf::IntRect(size * 1 + offx * size, 0 + offy * size, size, size));
	m_projectileAnimation.addFrame(sf::IntRect(size * 2 + offx * size, 0 + offy * size, size, size));
	m_projectileAnimation.addFrame(sf::IntRect(size * 1 + offx * size, 0 + offy * size, size, size));
	m_projectileAnimation.addFrame(sf::IntRect(size * 0 + offx * size, 0 + offy * size, size, size));

	m_currentAnimation = &m_projectileAnimation;
	m_animatedSprite = AnimatedSprite(sf::seconds(0.1), true, false);
	m_animatedSprite.setOrigin(16, 16);
}

ProjectileGraphicsComponent::~ProjectileGraphicsComponent()
{
}

void ProjectileGraphicsComponent::update(const sf::Time & time)
{
	// update AnimatedSprite
	m_animatedSprite.play(*m_currentAnimation);
	m_animatedSprite.update(time);
}

void ProjectileGraphicsComponent::draw(sf::RenderTexture & renderTexture)
{
	renderTexture.draw(m_animatedSprite);
}

void ProjectileGraphicsComponent::initialize(std::string textName, int offx, int offy)
{

	if (!m_texture.loadFromFile(textName))
	{

	}

	m_projectileAnimation.setSpriteSheet(m_texture);
	m_projectileAnimation.addFrame(sf::IntRect(32 + offx * 32, 0 + offy * 32, 32, 32));
	m_projectileAnimation.addFrame(sf::IntRect(64 + offx * 32, 0 + offy * 32, 32, 32));
	m_projectileAnimation.addFrame(sf::IntRect(32 + offx * 32, 0 + offy * 32, 32, 32));
	m_projectileAnimation.addFrame(sf::IntRect(0 + offx * 32, 0 + offy * 32, 32, 32));
	m_currentAnimation = &m_projectileAnimation;
}

void ProjectileGraphicsComponent::setPosition(sf::Vector2f position)
{
	m_animatedSprite.setPosition(position);
}

void ProjectileGraphicsComponent::setRotation(float rotation)
{
	m_animatedSprite.setRotation(rotation);
}
