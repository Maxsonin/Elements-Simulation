#include "../Headers/World.h"

void Water::UpdateWaterSimulation(World& world)
{
    char voidElement = World::GetSign();

    auto& worldGrid = world.GetWorldGrid();

    size_t currentWaterLength = 0;

    for (int y = world.GetGridSize().y - 3; y >= 0; y--)
        for (int x = 0; x < world.GetGridSize().x - 1; x++)
        
            if (worldGrid[x][y] == waterSign)
            {
                bool belowEmpty = (worldGrid[x][y + 1] == voidElement);
                bool leftBelowEmpty = (x - 1 >= 0) && (worldGrid[x - 1][y + 1] == voidElement);
                bool rightBelowEmpty = (worldGrid[x + 1][y + 1] == voidElement);

                // Cases with Void
                if (belowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = waterSign;
                }
                else if (leftBelowEmpty && rightBelowEmpty)
                {
                    bool direction = rand() % 2;
                    worldGrid[x][y] = voidElement;
                    worldGrid[x + (direction == 0 ? -1 : 1)][y + 1] = waterSign;
                }
                else if (leftBelowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x - 1][y + 1] = waterSign;
                }
                else if (rightBelowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x + 1][y + 1] = waterSign;
                }
                // To keep water in the window and there were no errors with vector
                else if (y - 1 >= 0)
                {
                    if (
                        (x + waterSpreadLength - currentWaterLength >= 0 &&
                            x + waterSpreadLength - currentWaterLength < world.GetGridSize().x &&
                            x - waterSpreadLength + currentWaterLength >= 0 &&
                            x - waterSpreadLength + currentWaterLength < world.GetGridSize().x) &&
                        ((worldGrid[x + waterSpreadLength - currentWaterLength][y - 1] == voidElement && worldGrid[x + 1][y] == voidElement) ||
                            (worldGrid[x - waterSpreadLength + currentWaterLength][y - 1] == voidElement && worldGrid[x - 1][y] == voidElement))
                        )
                    {
                        int r = rand() % 2; // to make Water chaotic

                        if (r == 0 && worldGrid[x + waterSpreadLength - currentWaterLength][y - 1] == voidElement && worldGrid[x + 1][y] == voidElement) {
                            worldGrid[x][y] = voidElement;
                            worldGrid[x + 1][y] = waterSign;
                            currentWaterLength++;
                        }
                        else if (r == 1 && worldGrid[x - waterSpreadLength + currentWaterLength][y - 1] == voidElement && worldGrid[x - 1][y] == voidElement) {
                            worldGrid[x][y] = voidElement;
                            worldGrid[x - 1][y] = waterSign;
                            currentWaterLength++;
                        }
                    }
                    if (currentWaterLength == waterSpreadLength - 1) currentWaterLength = 0;
                }
            }    
}