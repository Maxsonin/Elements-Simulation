#include <SFML/Graphics.hpp>
#include "World.h"


int WinMain()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Element Simulation", sf::Style::Close | sf::Style::Resize);

    Sand sand;
    Water water;
    Stone stone;
    World world;
    sf::Clock clock;
    sf::Clock clickClock;

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (clickClock.getElapsedTime().asMilliseconds() >= 1.0f)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                int gridX = floor(localPosition.x / 5);
                int gridY = floor(localPosition.y / 5);

                // Перевірка, чи gridX та gridY знаходяться в межах worldGrid
                if (gridX >= 0 && gridX < 161 && gridY >= 0 && gridY < 161)
                {
                    world.PlaceElement(gridX, gridY, Sand::GetSign());
                    clickClock.restart();
                }
            }
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (clickClock.getElapsedTime().asMilliseconds() >= 1.0f)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                int gridX = floor(localPosition.x / 5);
                int gridY = floor(localPosition.y / 5);

                // Перевірка, чи gridX та gridY знаходяться в межах worldGrid
                if (gridX >= 0 && gridX < 161 && gridY >= 0 && gridY < 161)
                {
                    world.PlaceElement(gridX, gridY, Water::GetSign());
                    clickClock.restart();
                }
            }
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            if (clickClock.getElapsedTime().asMilliseconds() >= 0.001f)
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                int gridX = floor(localPosition.x / 5);
                int gridY = floor(localPosition.y / 5);

                // Перевірка, чи gridX та gridY знаходяться в межах worldGrid
                if (gridX >= 0 && gridX < 161 && gridY >= 0 && gridY < 161)
                {
                    world.PlaceElement(gridX, gridY, Stone::GetSign());
                    clickClock.restart();
                }
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { world.ClearWorld(); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window.close(); }

        if (clock.getElapsedTime().asMilliseconds() >= 10.0f)
        {
            sand.UpdateSandSimulation(world);
            water.UpdateWaterSimulation(world);
            clock.restart();
        }

        world.Draw(window);
        window.display();
    }

    return 0;
}
