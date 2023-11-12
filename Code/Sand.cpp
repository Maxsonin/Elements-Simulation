#include "../Headers/World.h"

void Sand::UpdateSandSimulation(World& world)
{
    char voidElement = World::GetSign();
    char waterElement = Water::GetSign();

    auto& worldGrid = world.GetWorldGrid();

    // We iterating through every cell in grid(from bottom of the window to top)
    for (int y = world.GetGridSize().y - 3; y >= 0; y--)
        for (int x = 0; x < world.GetGridSize().x - 1; x++)
            if (worldGrid[x][y] == sandSign)
            {
                // Check collision with Void
                bool belowEmpty = (worldGrid[x][y + 1] == voidElement);
                bool leftBelowEmpty = (x - 1 >= 0) && (worldGrid[x - 1][y + 1] == voidElement);
                bool rightBelowEmpty = (worldGrid[x + 1][y + 1] == voidElement);

                // Check collision with Water
                bool belowWater = (worldGrid[x][y + 1] == waterElement);
                bool leftBelowWater = (x - 1 >= 0) && (worldGrid[x - 1][y + 1] == waterElement);
                bool rightBelowWater = (worldGrid[x + 1][y + 1] == waterElement);

                // Actions for each situation (For the sake of simplicity, I didn't complicate the code)
                // Cases with Void
                if (belowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = sandSign;                   
                }
                else if (leftBelowEmpty && rightBelowEmpty)
                {
                    bool direction = rand() % 2;
                    worldGrid[x][y] = voidElement;
                    worldGrid[x + (direction == 0 ? -1 : 1)][y + 1] = sandSign;
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
                // Cases with Water
                else if (belowWater)
                {
                    worldGrid[x][y] = waterElement;
                    worldGrid[x][y + 1] = sandSign;
                }
                else if (leftBelowWater && rightBelowWater)
                {
                    bool direction = rand() % 2;
                    worldGrid[x][y] = waterElement;
                    worldGrid[x + (direction == 0 ? -1 : 1)][y + 1] = sandSign;
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