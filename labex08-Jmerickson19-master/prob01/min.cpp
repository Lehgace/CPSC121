#include "min.hpp"

int min(int * locator, int size)
{
  int candidate = *locator;
  for (int i = 0; i < size; i++)
  {
    if (*(locator + i) < candidate)
    {
      candidate = *(locator + i);
    }
  }
  return candidate;
}
