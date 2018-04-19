#pragma once
#include <SFML\Graphics.hpp>
class gol
{
public:
	gol(unsigned sizeOfFieldX, unsigned sizeOfFieldY, unsigned sizeOfViewX, unsigned sizeOfViewY);
	~gol();
private:
	class cell
	{
	public:
		void update_cell(); //This does everything for the cell boi
	public:
		bool alive = false;
		unsigned age = 0; // To use to play with colour
		unsigned x; // pos x
		unsigned y; // pos y
		sf::Color color; //Current color of the cell
	private:
		unsigned how_many_alive_around_me() const; //Used to get number of live neighbours
	};
public:
	static unsigned sizeOfFieldX; // Field is the actual size
	static unsigned sizeOfFieldY;
	static unsigned sizeOfViewX; //View is what can be seen by the user
	static unsigned sizeOfViewY;
public:
	static sf::Color freshcolor; //To set; The color young cells have
	static sf::Color deadcolor; //the color dead cells have aka. the background
	static cell** old_scene;
	static cell** new_scene;

};

