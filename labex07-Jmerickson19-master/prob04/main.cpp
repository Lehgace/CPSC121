#include "lsa.hpp"
#include <iostream>

int main() {
  int array[10] = {3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  int choice;
  std::cout << "Array: ";
  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
  std::cout << "Please enter a number you want to search for: ";
  std::cin >> choice;
  int index;
  // Provide code that calls the linear_search function to find the number that
  // the user provided. Return the index of the value in the array
  // or -1 if it is not in the array. Store the value in the variable named
  // index

  if (index == -1) {
    std::cout << choice << " is not in the array"
              << "\n";
  } else {
    std::cout << "The index of " << choice << " in the array is: " << index
              << "\n";
  }
  return 0;
}
