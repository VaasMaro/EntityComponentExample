#pragma once
#include "GraphicsComponent.h"

class RectGraphicsComponent : public GraphicsComponent
{
public:
	RectGraphicsComponent();
	~RectGraphicsComponent();
	void initialize(sf::Vector2f size);
	void setColor(sf::Color color) { m_rect.setFillColor(color); }
	void setPosition(sf::Vector2f position) { m_rect.setPosition(position); }
	virtual void update(sf::Time time);
	virtual void draw(sf::RenderTexture& renderTexture);
	void setWidth(float width);
	void setProperty(sf::Color outlinecolor, float outlinethickness);
private:
	sf::RectangleShape m_rect;
};
