#include "DrawManager.h"
#include "ManagersAccess.h"
#include "TileMap.h"
DrawManager::DrawManager()
{

}


DrawManager::~DrawManager()
{

}

void DrawManager::initialize(ManagersAccess *managersAccess, sf::RenderWindow &window)
{
	m_managersAccess = managersAccess;
	m_renderTexture  = new sf::RenderTexture();
	m_renderTexture->create(m_managersAccess->mapManager->getTileMap()->getSize().x * 32, m_managersAccess->mapManager->getTileMap()->getSize().y * 32);
	m_renderSprite = new sf::Sprite();
	m_window = &window;
}

int DrawManager::subscribe(GraphicsComponent *graphicsComponent)
{
	m_graphicsComponentContainer.push_back(graphicsComponent);
	return m_graphicsComponentContainer.size() - 1;
}

int DrawManager::subscribeUnderLayer(GraphicsComponent * graphicsComponent)
{
	m_graphicsComponentUnderLayer.push_back(graphicsComponent);
	return m_graphicsComponentUnderLayer.size() - 1;
}

int DrawManager::subscribeUILayer(GraphicsComponent * graphicsComponent)
{
	m_graphicsComponentUILayer.push_back(graphicsComponent);
	return m_graphicsComponentUILayer.size() - 1;
}

void DrawManager::reject(const int &id)
{
	m_graphicsComponentContainer.erase(m_graphicsComponentContainer.begin() + id);
	for (int i = id; i < m_graphicsComponentContainer.size(); i++)
	{
		m_graphicsComponentContainer[i]->setId(m_graphicsComponentContainer[i]->getId() - 1);
	}
}

void DrawManager::rejectUnderLayer(const int & id)
{
	m_graphicsComponentUnderLayer.erase(m_graphicsComponentUnderLayer.begin() + id);
	for (int i = id; i < m_graphicsComponentUnderLayer.size(); i++)
	{
		m_graphicsComponentUnderLayer[i]->setId(m_graphicsComponentUnderLayer[i]->getId() - 1);
	}
}

void DrawManager::rejectUILayer(const int & id)
{
	m_graphicsComponentUILayer.erase(m_graphicsComponentUILayer.begin() + id);
	for (int i = id; i < m_graphicsComponentUILayer.size(); i++)
	{
		m_graphicsComponentUILayer[i]->setId(m_graphicsComponentUILayer[i]->getId() - 1);
	}
}

void DrawManager::update(sf::RenderWindow & window)
{
	// effacement de la texture en noir
	m_renderTexture->clear(sf::Color::Black);



	// on dessine dans la texture
	m_managersAccess->mapManager->getTileMap()->update(*m_renderTexture);
	for (auto graphics : m_graphicsComponentUnderLayer)
	{
		graphics->draw(*m_renderTexture);
	}
	for (auto graphics : m_graphicsComponentContainer)
	{
		graphics->draw(*m_renderTexture);
	}
	m_managersAccess->mapManager->getTileMap()->drawForeground(*m_renderTexture);
	for (auto graphics : m_graphicsComponentUILayer)
	{
		graphics->draw(*m_renderTexture);
	}
	// We're done drawing to the texture
	m_renderTexture->display();
	// Now we start rendering to the window, clear it first
	window.clear();

	// Draw the texture
	m_renderSprite->setTexture(m_renderTexture->getTexture());
	window.draw(*m_renderSprite);
	// End the current frame and display its contents on screen


	window.display();

}

sf::RenderWindow *DrawManager::getWindow()
{
	return m_window;
}
