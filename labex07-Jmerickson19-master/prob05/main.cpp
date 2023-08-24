#include "gcd.hpp"
#include <iostream>

int main() {
  int num_1;
  int num_2;
  std::cout << "Enter the first number: ";
  std::cin >> num_1;
  std::cout << "Enter the second number: ";
  std::cin >> num_2;

  int gcd_value;
  // Provide code that calls the gcd function using the two numbers that the
  // user entered. Store the result in the gcd_value variable.

  std::cout << "The GCD of the numbers " << num_1 << " and " << num_2 << " is "
            << gcd_value << "\n";

  return 0;
}
