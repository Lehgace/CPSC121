#include "soda.hpp"
#include <iostream>

double excess = 0;

double excess_dispensed(double array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] > DISPENSE_AMOUNT)
    {
       excess += (array[i] - DISPENSE_AMOUNT);
    }
  }
  return excess;
}
