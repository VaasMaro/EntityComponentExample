
#include "GameEngine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticuleTest.h"

//int main()
//{
//	// on cr�e la fen�tre
//	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Particles");
//
//	// on cr�e un syst�me de 1000 particules
//	ParticleSystem particles(1000);
//
//	// on cr�e un chrono pour mesurer le temps �coul�
//	sf::Clock clock;
//
//	// on fait tourner la boucle principale
//	while (window.isOpen())
//	{
//		// on g�re les �v�nements
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		// on fait en sorte que l'�metteur des particules suive la souris
//		sf::Vector2i mouse = sf::Mouse::getPosition(window);
//		particles.setEmitter(window.mapPixelToCoords(mouse));
//
//		// on met � jour le syst�me de particules
//		sf::Time elapsed = clock.restart();
//		particles.update(elapsed);
//
//		// on le dessine
//		window.clear();
//		window.draw(particles);
//		window.display();
//	}
//
//	return 0;
//}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
	window.setFramerateLimit(60);
	GameEngine gameEngine = GameEngine();
	gameEngine.initialize(window);
	gameEngine.run();

	return 0;
}


