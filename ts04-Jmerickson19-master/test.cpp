#include "soda.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  double dispensed[NUMBER_OF_SODAS];

  std::cout << "Please enter the soda amounts dispensed, in ounces.\n";

  for (int i = 0; i < NUMBER_OF_SODAS; i++)
  {
    std::cout << "Soda " << i + 1 << ": ";
    std::cin >> dispensed[i];
  }

  // TODO: Call your excess_dispensed function and pass in the array of soda
  // amounts dispensed as well as the number of items in the array.
  // Store the results of the function call in the "total" variable.

  double total;

  std::cout << std::setprecision(2) << std::fixed;
  std::cout << "\nTotal excess soda dispensed: " << total << " ounces\n";

  return 0;
}