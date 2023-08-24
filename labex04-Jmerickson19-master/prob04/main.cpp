#include <iomanip>
#include <iostream>

int main()
{
  double base_input = 0;
  int power_input = 0;

  std::cout << "Please enter the base number: ";
  std::cin >> base_input;
  std::cout << "Please enter the power: ";
  std::cin >> power_input;

  // Call your power function, pass the necessary arguments, then assign
  // its returned value to result.

  double result;  

  std::cout << std::setprecision(2) << std::fixed;
  std::cout << base_input << " ^ " << power_input << " = " << result << "\n";

  return 0;
}
