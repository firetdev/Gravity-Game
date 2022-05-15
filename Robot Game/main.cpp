#include <SFML/Graphics.hpp>
#include "player.h"
#include "button.h"
#include "planet.h"

int main()
{
    //Create window
    sf::RenderWindow window(sf::VideoMode(1500, 900), "Gravity Game", sf::Style::None);
    //Exit button
    Button close(1445, 860, 45, 30, "Exit");
    //Mouse position
    sf::Vector2i m;
    Player p(100, 100);
    Planet jupiter(500, 500, 100, 50);
    //Loop
    while(window.isOpen())
    {
        //Get mouse position
        m = sf::Mouse::getPosition(window);
        //Get event handler
        sf::Event event;
        //Check for events
        while(window.pollEvent(event))
        {
            //Close app
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            //Exit game
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                if(close.hovering(m.x, m.y))
                {
                    window.close();
                }
            }
        }
        //Rendering
        window.clear();
        close.render(window);
        p.render(window);
        jupiter.render(window);
        window.display();
    }
    return 0;
}