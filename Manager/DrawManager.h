#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsComponent.h"
#include <iostream>
#include "WaterShader.h"

struct ManagersAccess;
class DrawManager
{
public:
	DrawManager();
	~DrawManager();
	void initialize(ManagersAccess *managersAccess, sf::RenderWindow &window);
	int subscribe(GraphicsComponent *graphicsComponent);
	int subscribeUnderLayer(GraphicsComponent *graphicsComponent);
	int subscribeUILayer(GraphicsComponent *graphicsComponent);
	void reject(const int &id);
	void rejectUnderLayer(const int &id);
	void rejectUILayer(const int &id);
	void update(sf::RenderWindow & window);
	sf::RenderWindow *getWindow();
private:
	sf::RenderWindow * m_window;
	sf::RenderTexture *m_renderTexture;
	sf::Sprite *m_renderSprite;
	ManagersAccess *m_managersAccess;
	std::vector<GraphicsComponent*> m_graphicsComponentUnderLayer;
	std::vector<GraphicsComponent*> m_graphicsComponentContainer;
	std::vector<GraphicsComponent*> m_graphicsComponentUILayer;
};
