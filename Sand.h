#pragma once

class World;

class Sand
{
private:
    static const size_t SIZE = 5;
    static const char sandSign = 's';

public: 
    static size_t GetSize() { return SIZE; }
    static char GetSign() { return sandSign; }

    void UpdateSandSimulation(World& world);
};