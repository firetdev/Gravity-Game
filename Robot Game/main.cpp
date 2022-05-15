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
    //Start button
    Button start(1430, 720, 60, 30, "Start");
    //Shop
    Button mars(15, 760, 100, 125, "");
    Button venus(130, 760, 100, 125, "");
    Button saturn(245, 760, 100, 125, "");
    Button jupiter(360, 760, 100, 125, "");
    Button sun(475, 760, 100, 125, "");
    //Shop visuals
    sf::Texture tex1;
    sf::Texture tex2;
    sf::Texture tex3;
    sf::Texture tex4;
    sf::Texture tex5;
    tex1.loadFromFile("mars.png");
    tex2.loadFromFile("venus.png");
    tex3.loadFromFile("saturn.png");
    tex4.loadFromFile("jupiter.png");
    tex5.loadFromFile("dwarf.png");
    sf::Sprite s1(tex1);
    sf::Sprite s2(tex2);
    sf::Sprite s3(tex3);
    sf::Sprite s4(tex4);
    sf::Sprite s5(tex5);
    s1.setPosition(15, 760);
    s2.setPosition(130, 760);
    s3.setPosition(245, 760);
    s4.setPosition(360, 760);
    s5.setPosition(475, 760);
    s2.setScale(0.66, 0.66);
    s3.setScale(0.5, 0.5);
    s4.setScale(0.33, 0.33);
    //Mouse position
    sf::Vector2i m;
    //Player
    Player p(100, 430);
    //Buying
    int matter = 1000;
    int selected = 0;
    //Scenes
    int level = 1;
    int stage = 1;
    std::vector<Planet*> level1;
    level1.push_back(new Planet(500, 430, 50, 0, "mars.png"));
    //Loop
    while(window.isOpen())
    {
        //Get mouse position
        m = sf::Mouse::getPosition(window);
        //Get event handler
        sf::Event event;
        //Run stage 2
        if(stage == 2)
        {
            std::vector<Planet> planets;
            if (level == 1)
            {
                for (int i = 0; i < level1.size(); i++)
                {
                    planets.push_back(*level1[i]);
                    if(p.collide(planets[i]))
                    {
                        stage = 1;
                        p.x = 100;
                        p.y = 430;
                        level1 = {};
                        level1.push_back(new Planet(500, 430, 50, 0, "mars.png"));
                        matter = 1000;
                    }
                }
            }
            p.update(planets);
        }
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
            //Start stage 2
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                if(start.hovering(m.x, m.y))
                {
                    stage = 2;
                }
            }
            //Place planets
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && stage == 1)
            {
                if(m.y < 750)
                {
                    if(selected == 1 && matter >= 150)
                    {
                        matter -= 150;
                        if(level == 1)
                        {
                            level1.push_back(new Planet(m.x, m.y, 50, 4000, "mars.png"));
                        }
                    }
                    if (selected == 2 && matter >= 300)
                    {
                        matter -= 300;
                        if (level == 1)
                        {
                            level1.push_back(new Planet(m.x, m.y, 75, 7000, "venus.png"));
                        }
                    }
                    if (selected == 3 && matter >= 750)
                    {
                        matter -= 750;
                        if (level == 1)
                        {
                            level1.push_back(new Planet(m.x, m.y, 100, 9000, "saturn.png"));
                        }
                    }
                    if (selected == 4 && matter >= 1000)
                    {
                        matter -= 1000;
                        if (level == 1)
                        {
                            level1.push_back(new Planet(m.x, m.y, 150, 13000, "jupiter.png"));
                        }
                    }
                    if (selected == 5 && matter >= 1500)
                    {
                        matter -= 1500;
                        if (level == 1)
                        {
                            level1.push_back(new Planet(m.x, m.y, 50, 15000, "dwarf.png"));
                        }
                    }
                }
            }
        }
        //Rendering
        window.clear();
        close.render(window);
        start.render(window);
        mars.render(window);
        venus.render(window);
        saturn.render(window);
        jupiter.render(window);
        sun.render(window);
        window.draw(s1);
        window.draw(s2);
        window.draw(s3);
        window.draw(s4);
        window.draw(s5);
        p.render(window);
        if(level == 1)
        {
            for(int i = 0; i < level1.size(); i++)
            {
                level1[i]->render(window);
            }
        }
        window.display();
    }
    return 0;
}
