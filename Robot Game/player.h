#include <iostream>
#include <SFML/Graphics.hpp>
#include "planet.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
	int x, y, rotation;
	std::vector<int> velocity;
	sf::CircleShape sprite;
	Player(int, int);
	void update(std::vector<Planet>);
	void render(sf::RenderWindow &window);
};

Player::Player(int sx, int sy)
{
	x = sx;
	y = sy;
	rotation = 0;
	sprite = sf::CircleShape(20);
	sprite.setFillColor(sf::Color::White);
	sprite.setPosition(x, y);
}

void Player::update(std::vector<Planet> planets)
{

}

void Player::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

#endif
