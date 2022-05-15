#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef PLANET_H
#define PLANET_H

class Planet{
public:
	int x, y, s, mass;
	std::string path;
	sf::Texture tex;
	sf::Sprite sprite;
	Planet(int, int, int, int, std::string);
	void render(sf::RenderWindow &window);
};


Planet::Planet(int sx, int sy, int ss, int smass, std::string img)
{
	x = sx;
	y = sy;
	s = ss;
	mass = smass;
	path = img;
	tex.loadFromFile(img);
	sprite = sf::Sprite(tex);
	sprite.setPosition(x, y);
}

void Planet::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

#endif
