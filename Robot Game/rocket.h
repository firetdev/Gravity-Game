#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ROCKET_H
#define ROCKET_H

class Rocket{
public:
	int x, y;
	sf::Texture tex;
	sf::Sprite sprite;
	Rocket(int, int);
	bool playerCollide(int, int);
	void render(sf::RenderWindow &window);
};

Rocket::Rocket(int sx, int sy)
{
	x = sx;
	y = sy;
	tex.loadFromFile("rocket.png");
	sprite = sf::Sprite(tex);
	sprite.setPosition(sx, sy);
}

void Rocket::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

bool Rocket::playerCollide(int px, int py)
{
	int changeX = px - x;
	int changeY = py - y;
	unsigned int change = sqrt(changeX * changeX + changeY * changeY);
	if (change < (100 / 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif
