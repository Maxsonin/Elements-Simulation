#pragma once

class Stone
{
private:
    static const char stoneSign = 'r';

public:
    static char GetSign() { return stoneSign; }

    static void UpdateStoneSimulation(World& world);
};