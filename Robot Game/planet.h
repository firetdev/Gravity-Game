#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef PLANET_H
#define PLANET_H

class Planet{
public:
	int x, y, s, mass;
	sf::CircleShape sprite;
	Planet(int, int, int, int);
	void render(sf::RenderWindow &window);
};


Planet::Planet(int sx, int sy, int ss, int smass)
{
	x = sx;
	y = sy;
	s = ss;
	mass = smass;
	sprite = sf::CircleShape(s/2);
	sprite.setFillColor(sf::Color::White);
	sprite.setPosition(x, y);
}

void Planet::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

#endif
