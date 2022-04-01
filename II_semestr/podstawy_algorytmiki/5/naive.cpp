#include <string>

size_t find_naive(const std::string& text, const std::string& pattern) {
    for (size_t i = 0, j = 0; i < text.size() - pattern.size() + 1; ++i) {
        for (j = 0; j < pattern.size(); ++j)
            if (text[i + j] != pattern[j])
                break;

        if (j == pattern.size())
            return i;

    }
    return std::string::npos;
}