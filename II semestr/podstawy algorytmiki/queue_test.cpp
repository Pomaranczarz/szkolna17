#include <iostream>
#include "Queue.hpp"

int main() {
    Queue<int> queue;
    for (int i = 0; i < 10; ++i) {
        queue.push(i);
    }

    for (const auto& elem : queue)
        std::cout << elem << " ";

    std::cout << std::endl;

    queue.clear();

    for (const auto& elem : queue)
        std::cout << elem << " ";

    std::cout << std::endl;
}