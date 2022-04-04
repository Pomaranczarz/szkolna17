#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define ALPHABET_SIZE 256

size_t make_hash(char s, int off, size_t p, size_t exp)
{
    return ((int)s - off) * std::pow(p, exp);
}

void update_hash(size_t &hash, char s_prev, char s_next, int off, size_t p, size_t exp)
{
    hash -= make_hash(s_prev, off, p, exp);
    hash *= p;
    hash += ((int)s_next - off);
}

void kr(const std::string &pattern, const std::string &text, size_t p, size_t off)
{
    size_t hashP = 0;
    size_t hashT = 0;

    int i = 0;
    while (i < pattern.size())
    {
        hashP += make_hash(pattern[i], off, p, pattern.size() - 1 - i);
        hashT += make_hash(text[i], off, p, pattern.size() - 1 - i);
        ++i;
    }

    i = pattern.size();
    int j = 0;

    while (i <= text.size())
    {
        if (hashP == hashT && pattern == text.substr(j, pattern.size()))
            std::cout << j << " ";

        if (i < text.size())
            update_hash(hashT, text[j], text[i], off, p, pattern.size() - 1);

        ++j;
        ++i;
    }
}

int main()
{
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
