#include "array_max.hpp"
#include <iostream>

int array_max(int array[], int size)
{
  if (size == 1)
  {
    return array[0];
  }
  else if (size < 1)
  {
    return -1;
  }
  else
  {
    return std::max(array[size - 1], array_max(array, size - 1));
  }
}
