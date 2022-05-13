#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef BUTTON_H
#define BUTTON_H

class Button {
public:
	int x, y, w, h;
	std::string string;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape rect;
	Button(int, int, int, int, std::string);
	bool hovering(float, float);
	void render(sf::RenderWindow& window);
};

Button::Button(int ex, int ey, int ew, int eh, std::string str)
{
	x = ex;
	y = ey;
	w = ew;
	h = eh;
	string = str;
	font = sf::Font();
	font.loadFromFile("Arial.ttf");
	rect = sf::RectangleShape(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color(100, 100, 100));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1);
	text.setString(string);
	text.setPosition(x + 5, y + 3);
	text.setCharacterSize(20);
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
}

bool Button::hovering(float mx, float my)
{
	if (mx > x && mx < (x + w) && my > y && my < (y + h))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(rect);
	window.draw(text);
}

#endif
