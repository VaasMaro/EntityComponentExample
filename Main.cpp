
#include "GameEngine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticuleTest.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
	window.setFramerateLimit(60);
	GameEngine gameEngine = GameEngine();
	gameEngine.initialize(window);
	gameEngine.run();

	return 0;
}


