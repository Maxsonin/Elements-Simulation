#include "Sand.h"
#include "World.h"

void Sand::UpdateSandSimulation(World& world)
{
    char voidElement = world.getVoidElement();

    char waterElement = Water::GetSign();

    auto& worldGrid = world.GetWorldGrid();

    for (int y = world.GetGridSize().y - 3; y >= 0; y--)
    {
        for (int x = 0; x < world.GetGridSize().x - 1; x++)
        {
            if (worldGrid[x][y] == sandSign)
            {
                bool belowEmpty = (worldGrid[x][y + 1] == voidElement);

                bool leftBelowEmpty = (x - 1 < 0) ? false : (worldGrid[x - 1][y + 1] == voidElement);
                bool rightBelowEmpty = (worldGrid[x + 1][y + 1] == voidElement);

                if (belowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = sandSign;
                }
                else if (leftBelowEmpty && rightBelowEmpty)
                {
                    bool direction = rand() % 2;

                    if (direction == 0)
                    {
                        worldGrid[x][y] = voidElement;
                        worldGrid[x - 1][y + 1] = sandSign;
                    }
                    else
                    {
                        worldGrid[x][y] = voidElement;
                        worldGrid[x + 1][y + 1] = sandSign;
                    }
                }
                else if (leftBelowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x - 1][y + 1] = sandSign;
                }
                else if (rightBelowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x + 1][y + 1] = sandSign;
                }
                else if (worldGrid[x][y] == sandSign)
                {
                    bool belowWater = (worldGrid[x][y + 1] == waterElement);

                    bool leftBelowWater = (x - 1 < 0) ? false : (worldGrid[x - 1][y + 1] == waterElement);
                    bool rightBelowWater = (worldGrid[x + 1][y + 1] == waterElement);

                    if (belowWater)
                    {
                        worldGrid[x][y] = waterElement;
                        worldGrid[x][y + 1] = sandSign;
                    }
                    else if (leftBelowWater && rightBelowWater)
                    {
                        bool direction = rand() % 2;

                        if (direction == 0)
                        {
                            worldGrid[x][y] = waterElement;
                            worldGrid[x - 1][y + 1] = sandSign;
                        }
                        else
                        {
                            worldGrid[x][y] = waterElement;
                            worldGrid[x + 1][y + 1] = sandSign;
                        }
                    }
                    else if (leftBelowWater)
                    {
                        worldGrid[x][y] = waterElement;
                        worldGrid[x - 1][y + 1] = sandSign;
                    }
                    else if (rightBelowWater)
                    {
                        worldGrid[x][y] = waterElement;
                        worldGrid[x + 1][y + 1] = sandSign;
                    }
                }
            }
         
        }
    }
}