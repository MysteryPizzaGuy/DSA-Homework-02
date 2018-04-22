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
	sf::RectangleShape** old_scene;
	sf::RectangleShape** new_scene;
};

