#include "power.hpp"
#include <iostream>

int main()
{
  int base;
  int exp;
  std::cout << "Enter a base: ";
  std::cin >> base;
  std::cout << "Enter an exponent: ";
  std::cin >> exp;
  int exponent_value;
  
  exponent_value = power(base, exp);

  std::cout << base << " ^ " << exp << " = " << exponent_value << "\n";
}
