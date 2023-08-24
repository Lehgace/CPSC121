#include "count-odd.hpp"
#include <iostream>

int main() {
  int num;
  std::cout << "Enter a number: ";
  std::cin >> num;

  if (num < 0) {
    std::cout << "Invalid input.\n";
  } else {
    int odd;
    // Provide code that calls the count_odd function that passes the user's
    // input. Store the result in the odd variable.

    std::cout << "The number of odds from 0 to " << num << " is " << odd
              << "\n";
  }

  return 0;
}
