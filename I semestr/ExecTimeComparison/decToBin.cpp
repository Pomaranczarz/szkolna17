#include <iostream>
#include <chrono>
#include <string>

std::string decToBin(long long int decNumber) {
    std::string result{ "" };
    while (decNumber) {
        result += (decNumber % 2) + '0';
        decNumber /= 2;
    }

    return std::string(result.rbegin(), result.rend());
}

std::chrono::microseconds measure(long long count) {
    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned long long i = 0; i < count; i++)
        decToBin(i);

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

int main() {
    long double measureSum{ 0 };
    long long int numOfCases{ 5000 };
    long count{ 1 };
    while (numOfCases < 1'000'000) {
        for (size_t i = 0; i < 100; i++)
            measureSum += measure(numOfCases).count();

        std::cout << "Average exec time for " << numOfCases << " cases: " << measureSum / 100 << " microseconds\n";
        numOfCases += 5000 * count;
        measureSum = 0;
        count += 1;
    }
}