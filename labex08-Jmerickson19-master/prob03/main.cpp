#include <iostream>

int main()
{
  const int ARRAY_COUNT = 10;

  int array_1[ARRAY_COUNT];
  int array_2[ARRAY_COUNT];

  std::cout << "Inputs for the first array:\n";
  for (int i = 0; i < ARRAY_COUNT; i++)
  {
    std::cout << "Enter the integer for index " << i << ": ";
    std::cin >> array_1[i];
  }

  std::cout << "\nInputs for the second array:\n";
  for (int i = 0; i < ARRAY_COUNT; i++)
  {
    std::cout << "Enter the integer for index " << i << ": ";
    std::cin >> array_2[i];
  }

  std::cout << "\nThe first array contains:\n";
  for (int i = 0; i < ARRAY_COUNT; i++)
  {
    std::cout << array_1[i] << ' ';
  }
  std::cout << std::endl;

  std::cout << "\nThe second array contains:\n";
  for (int i = 0; i < ARRAY_COUNT; i++)
  {
    std::cout << array_2[i] << ' ';
  }
  std::cout << std::endl;

  std::cout << "\nCalling add_array using the first and second array ...\n";

  // Call your add_array function and pass necessary parameters

  std::cout << "\nAfter calling add_array, the first array now contains:\n";
  for (int i = 0; i < ARRAY_COUNT; i++)
  {
    std::cout << array_1[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
