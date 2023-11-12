#pragma once

class World;

class Sand
{
private:
    static const char sandSign = 's';

public: 
    static char GetSign() { return sandSign; }

    static void UpdateSandSimulation(World& world);
};