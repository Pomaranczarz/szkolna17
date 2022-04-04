#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define ALPHABET_SIZE 256 - 'A' + 1

size_t make_hash(char c, size_t offset, size_t pos, size_t base) {
    return (c - offset) * std::pow(base, pos);
}

void update_hash(size_t& hash, char prev, char next, size_t offset, size_t pos, size_t base) {
    hash -= make_hash(prev, offset, pos, base);
    hash *= base;
    hash += make_hash(next, offset, pos, base);
}

void search_karp_rabin(const std::string& pattern, const std::string& text, size_t offset) {
    size_t pattern_hash = 0;
    size_t text_hash = 0;
    for (size_t i = 0; i < pattern.size(); ++i) {
        pattern_hash += make_hash(pattern[i], offset, i, ALPHABET_SIZE);
        text_hash += make_hash(text[i], offset, i, ALPHABET_SIZE);
    }

    size_t i = pattern.size();
    size_t j = 0;
    while (i < text.size()) {
        if (pattern_hash == text_hash) {
            for (size_t k = 0; k < pattern.size(); ++k) {
                if (pattern[k] != text[i + k])
                    break;

                if (k == pattern.size() - 1)
                    std::cout << i << " ";
            }
        }

        if (i < text.size())
            update_hash(text_hash, text[j], text[i], offset, i, ALPHABET_SIZE);

        ++i;
        ++j;
    }
}

int main() {
    std::ifstream input{ "tekst.txt" };
    if (input.good()) {
        size_t line_num = 1;
        std::string pattern, text;
        std::getline(input, pattern);
        while (!input.eof()) {
            std::getline(input, text);
            std::cout << "\nLinijka " << line_num << ": ";
            search_karp_rabin(pattern, text, ALPHABET_SIZE);
            ++line_num;
        }
    }
    else
        std::cerr << "Blad pliku\n";
}
