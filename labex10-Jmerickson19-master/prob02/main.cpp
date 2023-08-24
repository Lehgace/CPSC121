#include "pet.hpp"
#include <iostream>

int main()
{
  int num_pet = 0;
  std::string name;
  std::string breed;
  std::string species;
  std::string color;
  double weight;

  Pet pet_array[100];

  do
  {
    std::cout << "Please enter the pet's name (q to quit): ";
    std::getline(std::cin, name);
    if (name != "q")
    {
      std::cout << "Please enter the pet's species: ";
      std::getline(std::cin, species);
      std::cout << "Please enter the pet's breed: ";
      std::getline(std::cin, breed);
      std::cout << "Please enter the pet's color: ";
      std::getline(std::cin, color);
      std::cout << "Please enter the pet's weight (lbs): ";
      std::cin >> weight;
      std::cin.ignore();

      Pet pet_object = Pet(name, species, breed, color, weight);
      
      pet_array[num_pet] = pet_object;
      num_pet++;
    }
  } while (name != "q");

  std::cout << "Printing Pets:\n";
  for (int i = 0; i < num_pet; i++)
  {
    std::cout << "Pet " << i + 1 << "\n";
    
    pet_array[i].print();
  }
  return 0;
}
