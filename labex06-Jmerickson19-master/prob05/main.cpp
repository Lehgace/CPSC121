#include <iostream>
#include <string>

int main()
{
  std::string input;
  std::cout << "Please input a single word: ";
  std::cin >> input;
  int vowels;
  int consonants;
  // Call the count_vowels function to count the number of vowels in the user's
  // input and store it in the vowels variable

  // Call the count_consonants function to count the number of consonants in the
  // user's input and store it in the consonants variable

  std::cout << "The number of vowels in this string is: " << vowels << "\n";
  std::cout << "The number of consonants in this string is: " << consonants
            << "\n";
}
