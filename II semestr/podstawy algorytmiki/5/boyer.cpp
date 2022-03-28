#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's bad character heuristic
std::vector<int> generate_bad_char_array(const std::string& str) {
    std::vector<int> badchar(NO_OF_CHARS);

    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (int i = 0; i < str.size(); i++)
        badchar[static_cast<int>(str[i])] = i;

    return badchar;
}

size_t search(std::string::iterator begin, std::string::iterator end, const std::string& pattern) {
    int pattern_size = pattern.size();
    int text_size = begin - end;

    std::vector<int> badchar = generate_bad_char_array(pattern);

    int pattern_shift = 0;

    while (pattern_shift <= (text_size - pattern_size)) {
        int j = pattern_size - 1;

        while (j >= 0 && pattern[j] == text[pattern_shift + j])
            j--;

        if (j < 0)
            return pattern_shift;
        else
            pattern_shift += std::max(1, j - badchar[text[pattern_shift + j]]);

    }

    return std::string::npos;
}


int main()
{
    std::string txt = "ABAAABCD";
    std::string pat = "ABC";
    std::cout << search(txt.begin(), txt.end(), pat);

    return 0;
}