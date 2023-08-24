#include "calculate_avg.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  int size;

  std::cout << "How many students are in your class? ";
  std::cin >> size;

  if (size <= 0)
  {
    std::cout << "You have no class!\n";
  }
  else
  {
    double * ptr_array;
    ptr_array = new double[size];
    std::cout << "Enter the GPA for the students in your class (0.0 - 4.0)\n";

    for (int i = 0; i < size; i++)
    {
      std::cout << "Enter the GPA for student #" << i + 1 << ": ";
      double gpa;
      std::cin >> gpa;
      *(ptr_array + i) = gpa;
    }

    double average;
    average = calculate_avg(ptr_array, size);

    std::cout << "Class average: " << std::setprecision(2) << std::fixed
              << average << std::endl;

    delete[] ptr_array;
  }

  return 0;
}
