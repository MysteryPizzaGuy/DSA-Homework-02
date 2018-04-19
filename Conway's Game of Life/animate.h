#pragma once
#include "gol.h"
class animate // Only use animate after completeing gol operations
{
public:
	animate(sf::RenderWindow* window);
	~animate();
	void draw_all_shapes();
private:
	sf::RenderWindow* window;
	sf::CircleShape** old_scene;
	sf::CircleShape** new_scene;
};

