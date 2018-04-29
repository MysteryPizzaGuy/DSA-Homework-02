#include "animate.h"
#include <math.h>

animate::animate(sf::RenderWindow* window)
{
	this->window = window;
	new_scene = new sf::RectangleShape*[gol::sizeOfFieldX];
	float size = 5;
	float scale = 1.25;
	for (size_t x = 0; x < gol::sizeOfFieldX; x++)
	{
			new_scene[x] = new sf::RectangleShape[gol::sizeOfFieldY];
			for (size_t y = 0; y < gol::sizeOfFieldY; y++)
			{
				new_scene[x][y].setSize(sf::Vector2f(size, size));
				new_scene[x][y].setFillColor(gol::new_scene[x][y].color);
				new_scene[x][y].setOrigin(size/2.0, size/2.0);
				new_scene[x][y].setScale(scale, scale);
				new_scene[x][y].setPosition(gol::new_scene[x][y].x * size * scale, gol::new_scene[x][y].y * size * scale); //It's a long shot jim, lets see if it pays off.
			}
	}
}

animate::~animate()
{
	for (size_t i = 0; i < gol::sizeOfFieldX; i++)
	{
		delete[] new_scene[i];
	}
	delete[] new_scene;
	
}

void animate::draw_all_shapes()
{
	for (size_t x = 0; x < gol::sizeOfFieldX; x++)
	{
		for (size_t y = 0; y < gol::sizeOfFieldY; y++)
		{
			new_scene[x][y].setFillColor(gol::new_scene[x][y].color);
			window->draw(new_scene[x][y]);
		}
	}
}