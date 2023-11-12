#include "../Headers/World.h"

void Lava::UpdateLavaSimulation(World& world)
{
    char voidElement = World::GetSign();
    char waterElement = Water::GetSign();
    char stoneElement = Stone::GetSign();
    char sandElement = Sand::GetSign();

    auto& worldGrid = world.GetWorldGrid();

    size_t currentLavaLength = 0;

    for (int y = world.GetGridSize().y - 3; y >= 0; y--)
        for (int x = 0; x < world.GetGridSize().x - 1; x++)

            if (worldGrid[x][y] == lavaSign)
            {
                bool belowEmpty = (worldGrid[x][y + 1] == voidElement);
                bool leftBelowEmpty = (x - 1 >= 0) && (worldGrid[x - 1][y + 1] == voidElement);
                bool rightBelowEmpty = (worldGrid[x + 1][y + 1] == voidElement);


                bool WaterOnTop = false;
                bool SandOnTop = false;
                if (y - 1 >= 0)
                {
                    WaterOnTop = (worldGrid[x][y - 1] == waterElement);
                    SandOnTop = (worldGrid[x][y - 1] == sandElement);
                }

                bool WaterBelow = (worldGrid[x][y + 1] == waterElement);
                bool WaterRight = (worldGrid[x + 1][y] == waterElement);
                bool WaterLeft = (x - 1 >= 0) && (worldGrid[x - 1][y] == waterElement);

                bool SandBelow = (worldGrid[x][y + 1] == sandElement);
                bool SandRight = (worldGrid[x + 1][y] == sandElement);
                bool SandLeft = (x - 1 >= 0) && (worldGrid[x - 1][y] == sandElement);

                // Cases with Void
                if (belowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = lavaSign;
                }
                else if (leftBelowEmpty && rightBelowEmpty)
                {
                    bool direction = rand() % 2;
                    worldGrid[x][y] = voidElement;
                    worldGrid[x + (direction == 0 ? -1 : 1)][y + 1] = lavaSign;
                }
                else if (leftBelowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x - 1][y + 1] = lavaSign;
                }
                else if (rightBelowEmpty)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x + 1][y + 1] = lavaSign;
                }
                // Collision with Water
                else if (WaterOnTop)
                {
                    worldGrid[x][y - 1] = stoneElement;
                }
                else if (WaterBelow)
                {
                    worldGrid[x][y] = voidElement;
                    worldGrid[x][y + 1] = stoneElement;
                }
                else if (WaterRight)
                {
                    worldGrid[x + 1][y] = stoneElement;
                }
                else if (WaterLeft)
                {
                    worldGrid[x - 1][y] = stoneElement;
                }
                // Collision with Sand
                else if (SandOnTop)
                {
                    worldGrid[x][y - 1] = lavaSign;
                }
                else if (SandBelow)
                {
                    worldGrid[x][y + 1] = lavaSign;
                }
                else if (SandRight)
                {
                    worldGrid[x + 1][y] = voidElement;
                }
                else if (SandLeft)
                {
                    worldGrid[x - 1][y] = voidElement;
                }
                else if(y - 1 >= 0)
                {
                    if (
                        (x + lavaSpreadLength - currentLavaLength >= 0 &&
                            x + lavaSpreadLength - currentLavaLength < world.GetGridSize().x &&
                            x - lavaSpreadLength + currentLavaLength >= 0 &&
                            x - lavaSpreadLength + currentLavaLength < world.GetGridSize().x) &&
                        ((worldGrid[x + lavaSpreadLength - currentLavaLength][y - 1] == voidElement && worldGrid[x + 1][y] == voidElement) ||
                            (worldGrid[x - lavaSpreadLength + currentLavaLength][y - 1] == voidElement && worldGrid[x - 1][y] == voidElement))
                       )
                    {
                        int r = rand() % 2;

                        if (r == 0 && worldGrid[x + lavaSpreadLength - currentLavaLength][y - 1] == voidElement && worldGrid[x + 1][y] == voidElement) {
                            worldGrid[x][y] = voidElement;
                            worldGrid[x + 1][y] = lavaSign;
                            currentLavaLength++;
                        }
                        else if (r == 1 && worldGrid[x - lavaSpreadLength + currentLavaLength][y - 1] == voidElement && worldGrid[x - 1][y] == voidElement) {
                            worldGrid[x][y] = voidElement;
                            worldGrid[x - 1][y] = lavaSign;
                            currentLavaLength++;
                        }
                    }
                    if (currentLavaLength == lavaSpreadLength - 1) currentLavaLength = 0;
                }
            }
}