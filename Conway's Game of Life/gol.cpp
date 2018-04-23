#include "gol.h"
#include <random>
#include <iostream>
sf::Color gol::deadcolor(0,0, 0);
sf::Color gol::freshcolor(75, 0, 130);
gol::cell** gol::old_scene = nullptr;
gol::cell** gol::new_scene = nullptr;
unsigned gol::sizeOfFieldX = 0;
unsigned gol::sizeOfFieldY = 0;
unsigned gol::sizeOfViewX = 0;
unsigned gol::sizeOfViewY = 0;




gol::gol(unsigned sizeOfFieldX,unsigned sizeOfFieldY, unsigned sizeOfViewX, unsigned sizeOfViewY)
{
	old_scene = new cell*[sizeOfFieldX];
	new_scene = new cell*[sizeOfFieldX];
	for (unsigned x = 0; x < sizeOfFieldX; x++)
	{
		old_scene[x] = new cell[sizeOfFieldY];
		for (size_t y = 0; y < sizeOfFieldY; y++)
		{
			old_scene[x][y].x = x;
			old_scene[x][y].y = y;
		}
		new_scene[x] = new cell[sizeOfFieldY];
		for (size_t y = 0; y < sizeOfFieldY; y++)
		{
			new_scene[x][y].x = x;
			new_scene[x][y].y = y;
		}
	}
	this->sizeOfFieldX = sizeOfFieldX;
	this->sizeOfFieldY = sizeOfFieldY;
	this->sizeOfViewX = sizeOfViewX;
	this->sizeOfViewY = sizeOfViewY;
}


gol::~gol()
{
	for (size_t i = 0; i < sizeOfFieldX; i++)
	{
		delete[] old_scene[i];
		delete[] new_scene[i];
	}
	delete[] old_scene;
	delete[] new_scene;
}

void gol::update_all_cells()
{
	for (size_t x = 0; x < sizeOfFieldX; x++)
	{
		for (size_t y = 0; y < sizeOfFieldY; y++)
		{
			new_scene[x][y].update_cell();
		}
	}
	for (size_t x = 0; x < sizeOfFieldX; x++)
	{
		std::memcpy(old_scene[x], new_scene[x], sizeOfFieldY * sizeof(cell));
	}
}

void gol::random_seed_start(double bernoullitypeprob)
{
	std::random_device rnd;
	std::mt19937 gen{ rnd() };
	std::bernoulli_distribution dis{ bernoullitypeprob };
	for (size_t x = 0; x < sizeOfFieldX; x++)
	{
		for (size_t y = 0; y < sizeOfFieldY; y++)
		{
			if (dis(gen))
			{
				new_scene[x][y].alive = true;
				new_scene[x][y].color = freshcolor;
				old_scene[x][y].alive = true;
				old_scene[x][y].color = freshcolor;
			}
			else
			{
				new_scene[x][y].color = deadcolor;
				old_scene[x][y].color = deadcolor;

			}
		}
	}
}

void gol::cell::update_cell()
{
	unsigned neighbours = how_many_alive_around_me();
	if (alive) {
		if (neighbours==2 ||neighbours==3)
		{
	/*		if (age <30)
			{
				color.r += (255 - color.r) * 1 / 32;
				color.b += (255 - color.b) * 1 / 32;
				color.g += (255 - color.g) * 1 / 32;
			}*/
			age++;
			return;
		}
		else {
			alive = false;
			age = 0;
			//color = gol::deadcolor;
			color.r += (color.r) * 1 / 8;
			color.b += (color.b) * 1 / 8;
			color.g += (color.g) * 1 / 8;
			color.a -= 40;
			return;
		}
	}
	else {
		if (neighbours==3)
		{
			alive = true;
			color = gol::freshcolor;
			// age is already set to zero by either the dead if branch or the initialization of the cell
			return;
		}
		else if (color!=gol::deadcolor)
		{
			if (age>-4)
			{
				color.r += (color.r) * 1 / 8;
				color.b += (color.b) * 1 / 8;
				color.g += (color.g) * 1 / 8;
				color.a -= 40;
				age--;
			}
			else
			{
				color = gol::deadcolor;
				age = 0;
			}
		}
	}
}

unsigned gol::cell::how_many_alive_around_me() const
{
	//TODO: Set condition for borders, naimely for when x or y go into negative or overflow
	unsigned howmany = 0;
	if (x <= 0 || y <= 0)
	{
		return howmany;
	}
	if (x >= sizeOfFieldX - 1|| y >= sizeOfFieldY - 1) {
		return howmany;
	}
	if (gol::old_scene[x-1][y-1].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x][y - 1].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x+1][y - 1].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x - 1][y].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x + 1][y].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x - 1][y+1].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x][y + 1].alive)
	{
		howmany++;
	}
	if (gol::old_scene[x + 1][y + 1].alive)
	{
		howmany++;
	}
	return howmany;
}

