#include "get_longest_string.hpp"
#include <iostream>

std::string get_longest_string(std::string input[], int size)
{
  std::string longest_string;
  std::string candidate = input[0];
  for (int i = 0; i < size; i++)
  {
    if (input[i].length() > candidate.length())
    {
      candidate = input[i];
    }
  }
  longest_string = candidate;
  return longest_string;
}
