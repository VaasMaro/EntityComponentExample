#include "RotationComponent.h"

RotationComponent::RotationComponent()
{
}

RotationComponent::~RotationComponent()
{
}

void RotationComponent::update(sf::Vector2f mouse,  sf::Vector2f entity)
{
	//normalize(mouse, entity);
	m_rotation = (atan2(mouse.y - entity.y, mouse.x - entity.x) / M_PI) * 180 ;
}

float RotationComponent::getRotation()
{
	return m_rotation;
}

sf::Vector2f RotationComponent::getDirection()
{
	return sf::Vector2f(cos(m_rotation), sin(m_rotation));
}

void RotationComponent::normalize(sf::Vector2f & vec1, sf::Vector2f & vec2)
{
	float temp1x, temp1y, temp2x, temp2y;
	temp1x = vec1.x;
	temp1y = vec1.y;
	temp2x = vec2.x;
	temp2y = vec2.y;
	std::cout << temp1x << "/" << temp1y << "   " << temp2x << "/" << temp2y << std::endl;
	vec1.x = (vec1.x / sqrt((temp1x * temp1x) + (temp1y * temp1y)));
	vec1.y = (vec1.y / sqrt((temp1x * temp1x) + (temp1y * temp1y)));
	vec2.x = (vec2.x / sqrt((temp2x * temp2x) + (temp2y * temp2y)));
	vec2.y = (vec2.y / sqrt((temp2x * temp2x) + (temp2y * temp2y)));
}
