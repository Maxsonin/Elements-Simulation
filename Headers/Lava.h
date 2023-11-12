#pragma once

class World;

class Lava
{
private:
    static const char lavaSign = 'l';
    static const size_t lavaSpreadLength = 2;

public:
    static char GetSign() { return lavaSign; }
    static size_t GetLavaSpreadLength() { return lavaSpreadLength; }

    static void UpdateLavaSimulation(World& world);
};