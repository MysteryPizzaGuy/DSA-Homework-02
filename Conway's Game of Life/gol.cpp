#include "gol.h"



gol::gol(unsigned sizeOfFieldX,unsigned sizeOfFieldY, unsigned sizeOfViewX, unsigned sizeOfViewY)
{
	old_scene = new cell*[sizeOfFieldX];
	new_scene = new cell*[sizeOfFieldX];
	for (unsigned x = 0; x < sizeOfFieldX; x++)
	{
		cell* temp = new cell[sizeOfFieldY];
		for (size_t y = 0; y < sizeOfFieldY; y++)
		{
			temp[y].x = x;
			temp[y].y = y;
		}
		old_scene[x] = temp;
		cell* temp = new cell[sizeOfFieldY];
		for (size_t y = 0; y < sizeOfFieldY; y++)
		{
			temp[y].x = x;
			temp[y].y = y;
		}
		new_scene[x] = temp;
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

void gol::cell::update_cell()
{
	unsigned neighbours = how_many_alive_around_me();
	if (alive) {
		if (neighbours==2 ||neighbours==3)
		{
			age++;
			return;
		}
		else {
			alive = false;
			age = 0;
			color = gol::freshcolor;
			return;
		}
	}
	else {
		if (neighbours==3)
		{
			alive = true;
			return;
		}
	}
}

unsigned gol::cell::how_many_alive_around_me() const
{
	//TODO: Set condition for borders, naimely for when x or y go into negative or overflow
	unsigned howmany;
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

