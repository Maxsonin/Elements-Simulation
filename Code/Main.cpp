#include <SFML/Graphics.hpp>

#include "../Headers/World.h"

int WinMain()
{
    World world;
    size_t WindowX = world.GetSizeOfWindow().x;
    size_t WindowY = world.GetSizeOfWindow().y;
    sf::RenderWindow window(sf::VideoMode(WindowX, WindowY), "Element Simulation", sf::Style::Close);   

    // Syt Icon
    sf::Image icon;
    icon.loadFromFile("Resources/Imgs/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Set Cursor
    sf::Image cursorImg;
    cursorImg.loadFromFile("Resources/Imgs/cursor.png");
    sf::Vector2u clickSpot(8, 10);
    sf::Cursor cursor;
    cursor.loadFromPixels(cursorImg.getPixelsPtr(), cursorImg.getSize(), clickSpot);
    window.setMouseCursor(cursor);

    sf::Clock clock;
    float UpdateRate = 10.0f; // You can change this value to make the blocks move faster

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

        // Determining where the block should be depending on the size of the block and the extension of the window
        size_t sizeOfElements = World::GetSizeOfElement();
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        int gridX = floor(localPosition.x / sizeOfElements);
        int gridY = floor(localPosition.y / sizeOfElements);
        if (gridX >= 0 && gridX < WindowX && gridY >= 0 && gridY < WindowY)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) world.PlaceElement(gridX, gridY, Sand::GetSign());
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) world.PlaceElement(gridX, gridY, Water::GetSign());
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) world.PlaceElement(gridX, gridY, Lava::GetSign());
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) world.PlaceElement(gridX, gridY, Stone::GetSign());
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                world.PlaceElement(gridX, gridY, World::GetSign());
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                world.ClearWorld();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }


        if (clock.getElapsedTime().asMilliseconds() >= UpdateRate)
        {
            Sand::UpdateSandSimulation(world);
            // If you want to add Stone simulation just simply uncoment
            //Stone::UpdateStoneSimulation(world);
            Lava::UpdateLavaSimulation(world);
            Water::UpdateWaterSimulation(world);
            clock.restart();
        }
        world.Draw(window);
        window.display();
    }

    return 0;
}