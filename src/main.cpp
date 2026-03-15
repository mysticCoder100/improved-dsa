#include "lsp_impl.h"
#include <iostream>
#include "heap.h"
#include "singly_list.h"
#include "doubly_list.h"
#include <string>
#include <cctype>
#include "algo.h"


int main() {
   // singlyDemo();
   // doublyDemo();

   // const std::string words = "Ad a, is i A!da";

   if (constexpr char c = 'a'; is_an_alpha(c)) std::cout << c << " is an alpha." << std::endl;
   else std::cout << c << " is not an alpha." << std::endl;

   // palindrome(words);
   return 0;
}

