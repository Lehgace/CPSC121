#include "pet.hpp"
#include <iostream>

void Pet::print()
{
  std::cout << "Name: " << name() << '\n';
  std::cout << "Species: " << breed().species() << '\n';
  std::cout << "Breed: " << breed().name() << '\n';
  std::cout << "Color: " << breed().color() << '\n';
  std::cout << "Weight: " << weight() << '\n';
}
