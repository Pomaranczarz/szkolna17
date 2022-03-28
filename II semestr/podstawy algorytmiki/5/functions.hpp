#pragma once

#include <string>
#include <vector>

size_t find_naive(const std::string& text, const std::string& pattern) {
    for (size_t i = 0, j = 0; i < text.size() - pattern.size() + 1; ++i) {
        for (j = 0; j < pattern.size(); ++j)
            if (text[i + j] != pattern[j])
                break;

        if (j == pattern.size())
            std::cout << "Znaleziono " << pattern << " na " << i<< ". pozycji\n";
    }

    return std::string::npos;
}

std::vector<size_t> generate_prefix_array(const std::string& pattern) {
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

size_t find_kmp(const std::string& text, const std::string& pattern) {
    std::vector<size_t> prefix_function = generate_prefix_array(pattern);
    size_t i = 0, j = 0;
    while (i < text.size()) {
        while (j > 0 && pattern[j] != text[i])
            j = prefix_function[j - 1];
        if (pattern[j] == text[i])
            ++j;
        if (j == pattern.size())
            std::cout << "Znaleziono " << pattern << " na " << i - j + 1 << ". pozycji\n";

        ++i;
    }
    return std::string::npos;
}