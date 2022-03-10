#include "RandomGenerator.hpp"

std::random_device RandomGenerator::rd;

unsigned short RandomGenerator::randBetween(unsigned short min, unsigned short max)
{
    if (min > max)
        std::swap(min, max);

    std::uniform_int_distribution<unsigned short> dist(min, max);
    return dist(rd);
}

long RandomGenerator::randBetween(long min, long max)
{
    if (min > max)
        std::swap(min, max);

    std::uniform_int_distribution<long> dist(min, max);
    return dist(rd);
}

int RandomGenerator::randFromZeroTo(int max)
{
    std::uniform_int_distribution<int> dist(0, max);
    return dist(rd);
}