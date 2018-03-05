#include "GameEngine.h"

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::initialize(sf::RenderWindow & window)
{
	m_window = &window;
	// create managers
	m_entityManager = EntityManager();
	m_mapManager = MapManager();
	m_viewManager = ViewManager();
	m_physicsHandler = PhysicsHandler();
	m_managerAccess = ManagersAccess();
	m_drawManager = DrawManager();
	m_resourcesManager = ResourcesManager();
	// granting access
	m_managerAccess.entityManager = &m_entityManager;
	m_managerAccess.mapManager = &m_mapManager;
	m_managerAccess.viewManager = &m_viewManager;
	m_managerAccess.physicsHandler = &m_physicsHandler;
	m_managerAccess.inputManager = NULL;
	m_managerAccess.drawManager = &m_drawManager;
	m_managerAccess.resourcesManager = &m_resourcesManager;
}

void GameEngine::run()
{
	m_viewManager.initialize(*m_window, &m_managerAccess);
	m_mapManager.create(&m_managerAccess);
	m_entityManager.initialize(&m_managerAccess);
	m_drawManager.initialize(&m_managerAccess, *m_window);
	m_physicsHandler.initialize(&m_managerAccess);
	m_resourcesManager.initialize(&m_managerAccess);
	sf::Clock frameClock;
	sf::Time frameTime;
	// MAIN LOOP
	while (m_window->isOpen())
	{
		frameTime = frameClock.restart();
		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				m_window->close();
		}


		// input manager
		//m_inputManager.update();
		// map manager
		//m_mapManager.update(*m_window);

		// view manager
		m_viewManager.update(*m_window);
		// entity manager
		m_entityManager.update(frameTime);
		// draw manager
		m_drawManager.update(*m_window);


		// clock

	}

}