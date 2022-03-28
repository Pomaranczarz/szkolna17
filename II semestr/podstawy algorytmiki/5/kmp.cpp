#include <string>
#include <vector>
#include <iostream>

std::vector<size_t> generate_prefix_function(const std::string& pattern) {
    std::vector<size_t> prefix_function(pattern.size());
    prefix_function[0] = 0;
    for (size_t i = 1, j = 0; i < pattern.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j])
            j = prefix_function[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        prefix_function[i] = j;
    }
    return prefix_function;
}

size_t find_kmp(std::string::iterator begin, std::string::iterator end, const std::string& pattern) {
    std::vector<size_t> prefix_function = generate_prefix_function(pattern);
    size_t i = 0, j = 0;
    while (i < end - begin) {
        while (j > 0 && pattern[j] != *(begin + i))
            j = prefix_function[j - 1];
        if (pattern[j] == *(begin + i))
            ++j;
        if (j == pattern.size())
            return i - j + 1;

        ++i;
    }
    return std::string::npos;
}

int main() {
    std::string str = "Random text with pattern";
    std::string pattern = "pattern";

    std::cout << find_kmp(str.begin(), str.end(), pattern) << std::endl;
}