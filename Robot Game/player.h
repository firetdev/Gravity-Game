#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "planet.h"

class Player{
public:
	float x, y, rotation;
	std::vector<float> velocity;
	sf::CircleShape sprite;
	Player(float, float);
	void update(std::vector<Planet>);
	void render(sf::RenderWindow &window);
	bool collide(Planet &planet);
};

Player::Player(float sx, float sy)
{
	x = sx;
	y = sy;
	rotation = 0;
	sprite = sf::CircleShape(20);
	sprite.setFillColor(sf::Color::White);
	sprite.setPosition(x, y);
	velocity.push_back(0);
	velocity.push_back(0);
}

void Player::update(std::vector<Planet> planets)
{
	std::vector<float> forces;
	std::vector<float> forcesX;
	std::vector<float> forcesY;
	float dx;
	float dy;
	for(int i = 0; i < planets.size(); i++)
	{
		dx = planets[i].x - x;
		dy = planets[i].y - y;
		forces.push_back(0.02*((100*planets[i].mass)/((dx*dx)+(dy*dy))));
		forcesY.push_back((dy/(sqrt((dx*dx)+(dy*dy)))*forces[i]));
		forcesX.push_back((dx/(sqrt((dx*dx)+(dy*dy)))*forces[i]));
	}
	float forceX = 0;
	float forceY = 0;
	for(int i = 0; i < planets.size(); i++)
	{
		forceX += forcesX[i];
		forceY += forcesY[i];
	}
	float aX;
	float aY;
	aX = forceX / 100;
	aY = forceY / 100;
	velocity[0] += aX;
	velocity[1] += aY;
	x += velocity[0];
	y += velocity[1];
	sprite.setPosition(x, y);
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(sprite);
}

bool Player::collide(Planet &planet)
{
	int changeX = planet.x - x;
	int changeY = planet.y - y;
	unsigned int change = sqrt(changeX * changeX + changeY * changeY);
	if (change < (planet.s / 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif
