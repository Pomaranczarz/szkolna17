#pragma once

#include <random>

class RandomGenerator
{
public:
    static unsigned short randBetween(unsigned short min, unsigned short max);
    static long randBetween(long min, long max);
    static int randFromZeroTo(int max);

private:
    static std::random_device rd;
    RandomGenerator() = default;
};

using GEN = RandomGenerator;