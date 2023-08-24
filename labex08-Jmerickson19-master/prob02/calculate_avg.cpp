#include "calculate_avg.hpp"

double calculate_avg(double * array_address, int size)
{
  double average;
  if (size > 0)
  {
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
      sum += *(array_address + i);
    }
    average = sum / size;
  }
  else
  {
    average = 0.0;
  }
  return average;
}
