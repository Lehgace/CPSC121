#include "most_sig_digit.hpp"
#include <iostream>

int main()
{
  int input = 0;
  int most_significant = 0;

  std::cout << "Please enter an integer, this program will produce its most "
               "significant digit: ";
  std::cin >> input;

  most_significant = most_significant_digit(input);

  std::cout << "The most significant digit is " << most_significant << "\n";

  return 0;
}
