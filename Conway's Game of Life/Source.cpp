#include <SFML\Graphics.hpp>
#include "animate.h"
#include "gol.h"
#include <iostream>
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
		for (size_t x = 0; x < 20; x++)
		{
			for (size_t y = 0; y < 20; y++)
			{
				std::cout << game.old_scene[x][y].x << " " << game.old_scene[x][y].y << std::endl;
			}
		}
		game.update_all_cells();
		//Render
		window.clear(sf::Color::Black);
		anim.draw_all_shapes();
		window.display();
	}


	return 0;
}