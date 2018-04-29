#include <SFML\Graphics.hpp>
#include "animate.h"
#include "gol.h"
#include <iostream>
#include <sstream>
int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Conway's Game of Life");
	sf::Clock clock;
	gol game(150, 150, 100, 100);
	game.random_seed_start(0.25);
	animate anim(&window);
	int generation = 0;
	sf::Font font;
	font.loadFromFile("Enter-The-Grid.ttf");
	sf::Text counter;
	counter.setCharacterSize(20);
	counter.setFont(font);
	std::stringstream ss;
	sf::Time oneinstancetime = sf::seconds(0.01);// Change the time of one frame here.
	while (window.isOpen())
	{
		//Events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (clock.getElapsedTime()>=oneinstancetime)
		{
			game.update_all_cells();
			ss << "Generation >> " << generation;
			counter.setString(ss.str());
			ss.str("");
			generation++;
			//Render
			window.clear(game.deadcolor);
			anim.draw_all_shapes();
			window.draw(counter);
			window.display();
			clock.restart();
		}
	}


	return 0;
}