#include  <string>
#include  <iostream>
#include "algo.h"

//
// Created by abdul on 13/03/2026.
//


void palindrome(const std::string &words) {
    int fc = 0;
    size_t bc = words.size() - 1;

    bool isPalindrome = true;
    while (fc < bc) {
        const int c1 = toupper(words[fc]);
        const int c2 = toupper(words[bc]);

        if (!isalnum(c1)) {
            fc++;
            continue;
        }
        if (!isalnum(c2)) {
            bc--;
            continue;
        }

        if (c1 != c2)
            isPalindrome = false;
        ++fc;
        --bc;
    }

    std::cout << words << (isPalindrome ? " is a palindrome." : " is not a palindrome.") << std::endl;
}

bool is_an_alpha(char c) {
    c = tolower(c);
    constexpr int end = 'z';
    if (constexpr int start = 'a'; c >= start && c <= end) return true;
    return false;
}
