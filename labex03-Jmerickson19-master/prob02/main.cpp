#include <iostream>

int main()
{
  int base = 0;
  int power = 0;

  std::cout << "Please enter the base number: ";
  std::cin >> base;
  std::cout << "Please enter the power: ";
  std::cin >> power;

  int product = base;

  if (power < 0)
  {
    std::cout << "Negative powers are currently unsupported.\n";
  }
  else if (power == 0)
  {
    product = 1;
    std::cout << base << " ^ " << power << " = " << product << std::endl;
  }
  else
  {
    for (int i = 1; i < power; i++)
    {
      product = product * base;
    }
    std::cout << base << " ^ " << power << " = " << product << std::endl;
  }

  return 0;
}
