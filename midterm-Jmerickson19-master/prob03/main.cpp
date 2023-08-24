#include "cat.hpp"
#include <iostream>
#include <string>

int main()
{
  std::string name;
  std::string breed;
  double weight;

  std::cout << "Please tell me about your cat\n";
  std::cout << "Name: ";
  getline(std::cin, name);
  std::cout << "Breed: ";
  getline(std::cin, breed);
  std::cout << "Weight: ";
  std::cin >> weight;

  Cat cat;
  cat.set_name(name);
  cat.set_breed(breed);
  cat.set_weight(weight);

  std::cout << "\nYou entered:\n"
            << cat.name() << std::endl
            << cat.breed() << std::endl
            << cat.weight() << std::endl << std::endl;

  cat.display();

  return 0;
}
