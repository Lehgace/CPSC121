#include "car.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  const int NUM_CARS = 3;
  Car cars[NUM_CARS];
  for (int i = 0; i < NUM_CARS; i++)
  {
    std::string name;
    double price;
    int mileage;
    std::cout << "Car #" << i + 1 << "\n";
    std::cout << "Please enter the name: ";
    std::getline(std::cin, name);
    std::cout << "Please enter the milage: ";
    std::cin >> mileage;
    std::cout << "Please enter the price: ";
    std::cin >> price;
    std::cin.ignore();

    // Set the name, price and mileage of the corresponding Car
    // object based on user input.
  }

  // Create a Car object whose name is lowest.
  // Call the lowerst_price function to get the Car object with the lowest price
  // from the array then assign it to the Car object called lowest.

  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\nThe car with the lowest price is ";
  // Display the name of the car with the lowest price (use the lowest variable)

  std::cout << " with a mileage of ";
  // Display the mileage of the car with the lowest price (use the lowest
  // variable)

  std::cout << " and a price of $";

  // Display the price of the car with the lowest price (use the lowest
  // variable)

  std::cout << '\n';

  return 0;
}
