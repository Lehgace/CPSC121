#include <iomanip>
#include <iostream>

const float FTIME = 40;
const float OTIME = 65;
const float MULT = 1.5;
const float ADD = 25;

int main()
{
  float hours;
  float wage;
  float salary;

  std::cout << "Hourly wage: ";
  std::cin >> wage;
  std::cout << "Hours worked: ";
  std::cin >> hours;

  if (hours < 0 || wage < 0)
  {
    std::cout << "Invalid input\n";
  }
  else if (hours <= FTIME)
  {
    salary = wage * hours;
    std::cout << "Total Salary Owed: $" << std::fixed << std::setprecision(2)
              << salary << std::endl;
  }
  else if (hours <= OTIME)
  {
    salary = (wage * FTIME) + (hours - FTIME) * (wage * MULT);
    std::cout << "Total Salary Owed: $" << std::fixed << std::setprecision(2)
              << salary << std::endl;
  }
  else
  {
    salary = (wage * FTIME) + (wage * MULT) * ADD + (hours - OTIME) * wage * 2;
    std::cout << "Total Salary Owed: $" << std::fixed << std::setprecision(2)
              << salary << std::endl;
  }

  return 0;
}
