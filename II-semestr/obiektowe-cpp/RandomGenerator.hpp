#pragma once

#include <random>
#include <algorithm>
#include <vector>
#include <functional>

class Index2D
{
public:
    unsigned row, column;
    Index2D(unsigned row = 0, unsigned column = 0) : row(row), column(column) {}
};

using Index2DVec = std::vector<Index2D>;

class RandomGenerator
{
public:
    static unsigned short randBetween(unsigned short min, unsigned short max);
    static long randBetween(long min, long max);
    static int randFromZeroTo(int max);
    static Index2DVec getRandomIndexes(unsigned rows, unsigned cols);

private:
    static std::random_device rd;
    RandomGenerator() = default;
};

using GEN = RandomGenerator;