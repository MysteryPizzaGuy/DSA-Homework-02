#include "animate.h"
#include <math.h>
animate::animate(sf::RenderWindow* window)
{
	this->window = window;
	old_scene = new sf::CircleShape*[gol::sizeOfFieldX];
	new_scene = new sf::CircleShape*[gol::sizeOfFieldX];
	float radius = 5;
	float scale = 3;
	for (size_t x = 0; x < gol::sizeOfFieldX; x++)
	{
		if (x%2 ==0)
		{
			old_scene[x] = new sf::CircleShape[gol::sizeOfFieldY];
			for (size_t y = 0; y < gol::sizeOfFieldY; y++)
			{
				old_scene[x][y].setPointCount(6);
				old_scene[x][y].setRadius(radius);
				old_scene[x][y].setFillColor(gol::deadcolor);
				old_scene[x][y].setOrigin(radius, radius);
				old_scene[x][y].setRotation(30);
				old_scene[x][y].setPosition(gol::old_scene[x][y].x * radius * 2, gol::old_scene[x][y].y * radius * 2); //It's a long shot jim, lets see if it pays off.
			}
			new_scene[x] = new sf::CircleShape[gol::sizeOfFieldY];
			for (size_t y = 0; y < gol::sizeOfFieldY; y++)
			{
				new_scene[x][y].setPointCount(6);
				new_scene[x][y].setRadius(radius);
				new_scene[x][y].setFillColor(sf::Color::Red);
				new_scene[x][y].setOrigin(radius, radius);
				new_scene[x][y].setRotation(30);
				//Hex grid, every other row is half a step below the other one
				new_scene[x][y].setScale(scale, scale);
				new_scene[x][y].setPosition(gol::new_scene[x][y].x * scale* radius * 2+(0.5*radius), gol::new_scene[x][y].y *scale* radius * 2+(3*radius*cos(0.523599))); //It's a long shot jim, lets see if it pays off. it's in radian
			}
		}
		else {
			old_scene[x] = new sf::CircleShape[gol::sizeOfFieldY];
			for (size_t y = 0; y < gol::sizeOfFieldY; y++)
			{
				old_scene[x][y].setPointCount(6);
				old_scene[x][y].setRadius(radius);
				old_scene[x][y].setFillColor(gol::deadcolor);
				old_scene[x][y].setOrigin(radius, radius);
				old_scene[x][y].setRotation(30);
				old_scene[x][y].setPosition(gol::old_scene[x][y].x * radius * 2, gol::old_scene[x][y].y * radius * 2); //It's a long shot jim, lets see if it pays off.
			}
			new_scene[x] = new sf::CircleShape[gol::sizeOfFieldY];
			for (size_t y = 0; y < gol::sizeOfFieldY; y++)
			{
				new_scene[x][y].setPointCount(6);
				new_scene[x][y].setRadius(radius);
				new_scene[x][y].setFillColor(gol::deadcolor);
				new_scene[x][y].setOrigin(radius, radius);
				new_scene[x][y].setRotation(30);
				//Hex grid, every other row is half a step below the other one
				new_scene[x][y].setScale(scale, scale);
				new_scene[x][y].setPosition(gol::new_scene[x][y].x * scale* radius * 2, gol::new_scene[x][y].y *scale* radius * 2); //It's a long shot jim, lets see if it pays off.
			}
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
