#include "utensils.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  std::string name;
  std::string color;
  double mass;
  double size;
  double bite_size;

  std::cout << "Please enter the name of a food item: ";
  std::getline(std::cin, name);
  std::cout << "Please enter the mass of the food item: ";
  std::cin >> mass;

  Food myFood(name, mass);

  std::cout << "Please enter the size of the spoon: ";
  std::cin >> size;
  std::cout << "Please enter the color of the spoon: ";
  std::cin.ignore();
  std::getline(std::cin, color);
  std::cout << "Please enter your bite size using the spoon: ";
  std::cin >> bite_size;

  Spoon mySpoon(size, color, bite_size);

  std::cout << "Food before being eaten:\n";
  myFood.print();
  std::cout << "Food after spoon used:\n";
  mySpoon.use(myFood);
  myFood.print();
  return 0;
}
