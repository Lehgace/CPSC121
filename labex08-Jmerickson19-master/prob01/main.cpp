#include "min.hpp"
#include <iostream>

int main()
{
  const int SIZE = 10;
  int array[SIZE] = {-1, 22, 54, 33, -40, 67, 8, 15, -28, 11};

  std::cout << "Array: ";
  for (int i = 0; i < SIZE; i++)
  {
    std::cout << *(array + i) << ' ';
  }
  std::cout << std::endl;

  int min_value;
  min_value = min(array, SIZE);
  std::cout << "Min: " << min_value << std::endl;

  return 0;
}
