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
		int age = 0; // To use to play with colour
		unsigned x; // pos x
		unsigned y; // pos y
		sf::Color color; //Current color of the cell
	private:
		unsigned how_many_alive_around_me() const; //Used to get number of live neighbours
	};
public:
	void update_all_cells();
	void random_seed_start(double bernoullitypeprob);
private:
	static sf::Color approach_color(sf::Color approacher,sf::Color approchee, float step);
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

