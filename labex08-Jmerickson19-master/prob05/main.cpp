#include <iostream>

int main()
{
  const int MAX_ARRAY_COUNT = 10;

  int size;
  int array[MAX_ARRAY_COUNT];

  std::cout << "Enter an integer for the size of the array(Must be less than "
               "or equal to 10): ";
  std::cin >> size;

  std::cout << "Inputs for the array:\n";
  for (int i = 0; i < size; i++)
  {
    std::cout << "Enter the integer for index " << i << ": ";

    // Assign values from cin into indicies of the array.

  }

  // Call your print_array_reverse function and pass the necessary
  // parameters

  return 0;
}
