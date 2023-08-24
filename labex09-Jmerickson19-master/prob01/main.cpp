#include "cup.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  std::string drink_name;
  double amount;
  char menu_input;

  std::cout << "What kind of drink can I get you?: ";
  std::getline(std::cin, drink_name);
  std::cout << "How much do you want?: ";
  std::cin >> amount;

  Cup mug(drink_name, amount);
  do
  {
    std::cout << "Your cup currently has " << mug.fluid_oz() << " oz. of "
              << mug.drink_type() << std::endl;
    std::cout << "Please select what you want to do with your drink/cup?:\n";
    std::cout << "D: Drink\n";
    std::cout << "R: Refill\n";
    std::cout << "N: Get a brand new drink\n";
    std::cout << "E: Empty\n";
    std::cout << "X: Exit\n";
    std::cout << "Selection: ";
    std::cin >> menu_input;
    std::cin.ignore();

    switch (menu_input)
    {
      case 'D':
      case 'd':
        std::cout << "How much do you want to drink from the cup?: ";
        std::cin >> amount;
        std::cin.ignore();
        mug.drink(amount);
        break;
      case 'R':
      case 'r':
        std::cout << "How much do you want to refill your cup?: ";
        std::cin >> amount;
        std::cin.ignore();
        mug.refill(amount);
        break;
      case 'N':
      case 'n':
        std::cout << "What is the new drink you want?: ";
        std::getline(std::cin, drink_name);
        std::cout << "What is the amount you want?: ";
        std::cin >> amount;
        std::cin.ignore();
        mug.new_drink(drink_name, amount);
        break;
      case 'E':
      case 'e':
        std::cout << "Emptying your cup\n";
        mug.empty();
        break;
      case 'X':
      case 'x':
        std::cout << "Thank you for using Digicup!\n";
        break;
      default:
        std::cout << "Invalid use of Digicup!\n";
    }
  } while (menu_input != 'X' && menu_input != 'x');

  return 0;
}
