#pragma once

class World;

class Water
{
private:
    static const size_t SIZE = 5;
    static const char waterSign = 'w';
    static const size_t waterSpreadLength = 4;

public:
    static size_t GetSize() { return SIZE; }
    static char GetSign() { return waterSign; }
    static size_t GetWaterSpreadLength() { return waterSpreadLength; }

    void UpdateWaterSimulation(World& world);
};