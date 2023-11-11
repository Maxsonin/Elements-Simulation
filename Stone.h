#pragma once

class Stone
{
private:
    static const size_t SIZE = 5;
    static const char stoneSign = 'r';

public:
    static size_t GetSize() { return SIZE; }
    static char GetSign() { return stoneSign; }
};