#include "array_max.hpp"
#include <iostream>

int main()
{
  int arr[10] = {10, 9, 6, 1, 2, 4, 16, 8, 7, 5};
  int max_value;

  max_value = array_max(arr, 10);
  std::cout << "The largest number in the array is " << max_value << "\n";
  return 0;
}
