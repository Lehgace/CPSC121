#include "car_comp.hpp"
#include <iostream>

void Car::print()
{
  std::cout << "The name of the car is: " << identity().name() << "\n";
  std::cout << "The id of the car is: " << identity().id() << "\n";
  std::cout << "The license plate of the car is: " << identity().license_plate()
            << "\n";
  std::cout << "The release date of the car is: " << release_date().month()
            << '/' << release_date().day() << '/' << release_date().year()
            << "\n";
}
