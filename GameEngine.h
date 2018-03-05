#pragma once
#include <SFML/Graphics.hpp>
#include "ManagersAccess.h"


class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void initialize(sf::RenderWindow & window);
	void run();
private:
	// window
	sf::RenderWindow *m_window;
	// managers
	EntityManager m_entityManager;
	MapManager m_mapManager;
	PhysicsHandler m_physicsHandler;
	ViewManager m_viewManager;
	InputManager m_inputManager;
	DrawManager m_drawManager;
	ResourcesManager m_resourcesManager;
	// manager access
	ManagersAccess m_managerAccess;

};
