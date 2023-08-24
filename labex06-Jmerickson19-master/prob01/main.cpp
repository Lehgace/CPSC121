#include "get_longest_string.hpp"
#include <iostream>
#include <string>

int main()
{
  const int ARRAY_SIZE = 5;
  // Array called inputs that can store 5 string values
  std::string inputs[ARRAY_SIZE];

  // For loop that stores the users input into the right location in the array
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    std::cout << "Please enter string #" << i + 1 << ": ";
    std::cin >> inputs[i];
  }
  std::string longest;

  // Call the get_longest_string function and store the longest string from the
  // array into the variable called longest
  longest = get_longest_string(inputs, ARRAY_SIZE);
  std::cout << "The longest string is: " << longest << std::endl;

  return 0;
}
