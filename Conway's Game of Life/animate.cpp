#include "animate.h"

animate::animate(sf::RenderWindow* window)
{
	this->window = window;
	old_scene = new sf::CircleShape*[gol::sizeOfFieldX];
	new_scene = new sf::CircleShape*[gol::sizeOfFieldX];
	for (size_t x = 0; x < gol::sizeOfFieldX; x++)
	{
		old_scene[x] = new sf::CircleShape[gol::sizeOfFieldY];
		for (size_t y = 0; y < gol::sizeOfFieldY; y++)
		{
			old_scene[x][y].setPointCount(6);
			old_scene[x][y].setRadius(5);
			old_scene[x][y].setFillColor(gol::deadcolor);
			old_scene[x][y].setOrigin(5, 5);
			old_scene[x][y].setPosition(gol::old_scene[x][y].x * old_scene[x][y].getRadius()*2, gol::old_scene[x][y].y * old_scene[x][y].getRadius() * 2); //It's a long shot jim, lets see if it pays off.
		}
		new_scene[x] = new sf::CircleShape[gol::sizeOfFieldY];
		for (size_t y = 0; y < gol::sizeOfFieldY; y++)
		{
			new_scene[x][y].setPointCount(6);
			new_scene[x][y].setRadius(5);
			new_scene[x][y].setFillColor(gol::deadcolor);
			new_scene[x][y].setOrigin(5, 5);
			//Hex grid, every other row is half a step below the other one
			new_scene[x][y].setScale(3, 3);
			new_scene[x][y].setPosition(gol::new_scene[x][y].x * new_scene[x][y].getScale().x* new_scene[x][y].getRadius() * 2, gol::new_scene[x][y].y *new_scene[x][y].getScale().x* new_scene[x][y].getRadius() * 2); //It's a long shot jim, lets see if it pays off.
		}
	}
}

animate::~animate()
{
}

void animate::draw_all_shapes()
{
	for (size_t x = 0; x < gol::sizeOfFieldX; x++)
	{
		for (size_t y = 0; y < gol::sizeOfFieldY; y++)
		{
			window->draw(new_scene[x][y]);
		}
	}
}
