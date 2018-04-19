#include <SFML\Graphics.hpp>
#include "animate.h"
#include "gol.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Conway's Game of Life");
	sf::Clock clock;
	gol game(20, 20, 20, 20);
	animate anim(&window);
	while (window.isOpen())
	{
		//Events

		//Elapsed time get

		//Update

		//Render
		window.clear(sf::Color::Black);
		anim.draw_all_shapes();
		window.display();
	}


	return 0;
}