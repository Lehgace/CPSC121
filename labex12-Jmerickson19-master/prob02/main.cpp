#include "weapons.hpp"
#include <iostream>

int main()
{
  std::string e_name;
  int e_health;

  std::cout << "Please enter the name of an enemy: ";
  std::getline(std::cin, e_name);
  std::cout << "Please enter the enemy's health: ";
  std::cin >> e_health;

  Enemy myEnemy(e_name, e_health);

  Weapon * myDagger = new Daggers();
  Weapon * myShortSword = new ShortSword();

  myEnemy.receive_attack(myDagger);
  myEnemy.receive_attack(myShortSword);

  delete myDagger;
  myDagger = nullptr;
  delete myShortSword;
  myShortSword = nullptr;

  return 0;
}
