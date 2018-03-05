#include "RectGraphicsComponent.h"

RectGraphicsComponent::RectGraphicsComponent()
{
}

RectGraphicsComponent::~RectGraphicsComponent()
{
}

void RectGraphicsComponent::initialize(sf::Vector2f size)
{
	m_rect.setSize(size);
}

void RectGraphicsComponent::update(sf::Time time)
{
}

void RectGraphicsComponent::draw(sf::RenderTexture & renderTexture)
{
	renderTexture.draw(m_rect);
}

void RectGraphicsComponent::setWidth(float width)
{
	if(width >= 0) m_rect.setSize(sf::Vector2f(width, m_rect.getSize().y));
	else m_rect.setSize(sf::Vector2f(0, m_rect.getSize().y));
}

void RectGraphicsComponent::setProperty(sf::Color outlinecolor, float outlinethickness)
{
	m_rect.setOutlineColor(outlinecolor);
	m_rect.setOutlineThickness(outlinethickness);
}
