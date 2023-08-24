#include "car.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  int choice;
  std::string name;
  int year;
  double tank;
  double mpg;
  double speed;

  Car * myPcar = nullptr;
  std::cout << "Ubiquitous on-board driving management software test: - "
               "Gas/battery level sensor - \n";
  std::cout << "What type of car is being tested?\n";
  std::cout << "1 - Gasoline Car\n";
  std::cout << "2 - Electric Car\n";
  std::cout << "0 - Exit\n";
  std::cin >> choice;
  std::cin.ignore();

  if (choice == 1)
  {
    std::cout << "What is the name of the car? ";
    std::getline(std::cin, name);
    std::cout << "What year is the car? ";
    std::cin >> year;
    std::cout << "How many gallons of gas can this car store? ";
    std::cin >> tank;
    std::cout << "How much MPG does this car have? ";
    std::cin >> mpg;

    myPcar = new GasolineCar(name, year, tank, mpg);
    std::cout << "How fast do you want to drive this car per hour? ";
    std::cin >> speed;
    int hours = 0;
    do
    {
      hours++;
      myPcar->drive(speed);
    } while (!myPcar->is_empty());

    std::cout << "It took " << name << " about " << hours
              << " hour(s) of driving to empty the tank\n";
  }
  else if (choice == 2)
  {
    std::cout << "What is the name of the car? ";
    std::getline(std::cin, name);
    std::cout << "What year is the car? ";
    std::cin >> year;

    myPcar = new ElectricCar(name, year);
    std::cout << "How fast do you want to drive this car per hour? ";
    std::cin >> speed;
    int hours = 0;
    do
    {
      hours++;

      myPcar->drive(speed);
    } while (!myPcar->is_empty());
    std::cout << "It took " << name << " about " << hours
              << " hour(s) of driving to empty the battery\n";
  }
  else if (choice == 0)
  {
    std::cout << "Shutting down...\n";
  }
  else
  {
    std::cout << "Error - Shutting down...\n";
  }
  delete myPcar;
  myPcar = nullptr;
  return 0;
}
