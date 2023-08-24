#include <iomanip>
#include <iostream>

const int YEAR = 12;
int main()
{
  int month;
  double sales;
  double total = 0.0;
  double average;

  std::cout << "Annual sales report\n"
            << "===================\n"
            << "Please provide the monthly sales for the year.\n";

  for (int month = 1; month < YEAR + 1; month++)
  {
    std::cout << "Month: " << month << " $";
    std::cin >> sales;
    total = total + sales;
  }
  average = total / YEAR;
  std::cout << "Total sales: $" << std::fixed << std::setprecision(2) << total
            << std::endl;
  std::cout << "Average monthly sale: $" << std::fixed << std::setprecision(2)
            << average << std::endl;
  return 0;
}
