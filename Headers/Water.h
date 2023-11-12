#pragma once

class World;

class Water
{
private:
    static const char waterSign = 'w';
    static const size_t waterSpreadLength = 15;

public:
    static char GetSign() { return waterSign; }
    static size_t GetWaterSpreadLength() { return waterSpreadLength; }

    static void UpdateWaterSimulation(World& world);
};