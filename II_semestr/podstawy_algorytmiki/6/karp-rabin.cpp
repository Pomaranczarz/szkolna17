#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define ALPHABET_SIZE ('Z' - 'A' + 1) * 2

size_t make_hash(char c, int offset, size_t base, size_t pos) {
    return ((int)c - offset) * std::pow(base, pos);
}

void update_hash(size_t& hash, char s_prev, char s_next, int offset, size_t base, size_t pos) {
    hash -= make_hash(s_prev, offset, base, pos);
    hash *= base;
    hash += ((int)s_next - offset);
}

void kr(const std::string& pattern, const std::string& text, size_t base, size_t offset) {
    size_t hashP = 0;
    size_t hashT = 0;

    bool match = false;

    int i = 0;
    while (i < pattern.size())
    {
        hashP += make_hash(pattern[i], offset, base, pattern.size() - 1 - i);
        hashT += make_hash(text[i], offset, base, pattern.size() - 1 - i);
        ++i;
    }

    i = pattern.size();
    int j = 0;

    while (i <= text.size())
    {
        if (hashP == hashT) { // && pattern == text.substr(j, pattern.size())
            std::cout << j << " ";
            match = true;
        }

        if (i < text.size())
            update_hash(hashT, text[j], text[i], offset, base, pattern.size() - 1);

        ++j;
        ++i;
    }

    if (!match)
        std::cout << "-1";
}

int main() {
    std::ifstream input{"tekst.txt"};
    if (input.good())
    {
        size_t line_num = 2;
        std::string pattern, text;
        std::getline(input, pattern);

        while (!input.eof())
        {
            std::getline(input, text);
            std::cout << "Linijka " << line_num << ": ";
            kr(pattern, text, ALPHABET_SIZE, 'A');
            std::cout << '\n';
            ++line_num;
        }
    }
    else
        std::cerr << "Blad pliku\n";
}
