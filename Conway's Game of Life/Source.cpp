#include <SFML\Graphics.hpp>
#include "animate.h"
#include "gol.h"
#include <iostream>
int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Conway's Game of Life");
	sf::Clock clock;
	gol game(150, 150, 100, 100);
	game.random_seed_start(0.25);
	animate anim(&window);
	int generation = 0;
	while (window.isOpen())
	{
		//Events

		//Elapsed time get

		//Update
		//for (size_t x = 0; x < 20; x++)
		//{
		//	for (size_t y = 0; y < 20; y++)
		//	{
		//		std::cout << game.old_scene[x][y].x << " " << game.old_scene[x][y].y << std::endl;
		//	}
		//}
	
		game.update_all_cells();
		//Render
		window.clear(game.deadcolor);
		anim.draw_all_shapes();
		window.display();
		sf::sleep(sf::Time(sf::seconds(0.01)));
		std::cout << "Generation: " << generation << std::endl;
		generation++;
	}


	return 0;
}