#include "Water.h"
#include "World.h"

void Water::UpdateWaterSimulation(World& world)
{
    char voidElement = world.getVoidElement();

    auto& worldGrid = world.GetWorldGrid();

    size_t currentWaterSpreadLength = 0;

    for (int y = world.GetGridSize().y - 3; y >= 0; y--)
    {
        for (int x = 0; x < world.GetGridSize().x - 1; x++)
        {
            if (worldGrid[x][y] == waterSign)
            {
                bool belowEmpty = (worldGrid[x][y + 1] == voidElement);

                bool leftBelowEmpty = (x - 1 < 0) ? false : (worldGrid[x - 1][y + 1] == voidElement);
                bool rightBelowEmpty = (worldGrid[x + 1][y + 1] == voidElement);

                if (belowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = waterSign;
                }
                else if (leftBelowEmpty && rightBelowEmpty)
                {
                    bool direction = rand() % 2;

                    if (direction == 0)
                    {
                        worldGrid[x][y] = voidElement;
                        worldGrid[x - 1][y + 1] = waterSign;
                    }
                    else
                    {
                        worldGrid[x][y] = voidElement;
                        worldGrid[x + 1][y + 1] = waterSign;
                    }
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
                ////////////////////////////////////////////////////////////
                else if (x + waterSpreadLength - currentWaterSpreadLength >= 0 &&
                    x + waterSpreadLength - currentWaterSpreadLength < world.GetGridSize().x &&
                    x - waterSpreadLength + currentWaterSpreadLength >= 0 &&
                    x - waterSpreadLength + currentWaterSpreadLength < world.GetGridSize().x &&
                    (worldGrid[x + waterSpreadLength - currentWaterSpreadLength][y - 1] == voidElement ||
                        worldGrid[x - waterSpreadLength + currentWaterSpreadLength][y - 1] == voidElement))
                {
                    int r = rand() % 2; // just to make water spread left and right 50/50

                    if (r == 0 && worldGrid[x + waterSpreadLength - currentWaterSpreadLength][y - 1] == voidElement && worldGrid[x + 1][y] == voidElement)
                    {
                        worldGrid[x][y] = voidElement;
                        worldGrid[x + 1][y] = waterSign;
                        currentWaterSpreadLength++;
                    }
                    else if (r == 1 && worldGrid[x - waterSpreadLength + currentWaterSpreadLength][y - 1] == voidElement && worldGrid[x - 1][y] == voidElement)
                    {
                        worldGrid[x][y] = voidElement;
                        worldGrid[x - 1][y] = waterSign;
                        currentWaterSpreadLength++;
                    }
                }


                if (currentWaterSpreadLength == waterSpreadLength - 1) currentWaterSpreadLength = 0;

            }
        }
    }
}