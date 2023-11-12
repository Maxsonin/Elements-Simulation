#include "../Headers/World.h"

void Stone::UpdateStoneSimulation(World& world)
{
    char voidElement = World::GetSign();
    char waterElement = Water::GetSign();
    char lavaElement = Lava::GetSign();

    auto& worldGrid = world.GetWorldGrid();

    // We iterating through every cell in grid(from bottom of the window to top)
    for (int y = world.GetGridSize().y - 3; y >= 0; y--)
        for (int x = 0; x < world.GetGridSize().x - 1; x++)
            if (worldGrid[x][y] == stoneSign)
            {
                // Check collision
                bool belowVoid = false;
                bool belowWater = false;
                if (y + 1 < world.GetGridSize().y)
                {
                    belowVoid = (worldGrid[x][y + 1] == voidElement);
                    belowWater = (worldGrid[x][y + 1] == waterElement);
                }

                // Actions for each situation
                if (belowVoid)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = stoneSign;
                }
                if (belowWater)
                {
                    worldGrid[x][y] = waterElement;
                    worldGrid[x][y + 1] = stoneSign;
                }
            }
}