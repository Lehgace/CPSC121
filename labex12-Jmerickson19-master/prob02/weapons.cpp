#include "weapons.hpp"
#include <iostream>
#include <random>

int Weapon::attack()
{
  return (rand() % (attack_max_ - attack_min_)) + attack_min_;
}

int Daggers::attack()
{
  int attack_value = Weapon::attack();
  int random_number = (rand() % 20) + 1;
  int damage_1 = attack_value;
  int damage_2;
  if (random_number >= crit_dice_)
  {
    damage_1 *= crit_;
  }
  attack_value = Weapon::attack();
  random_number = (rand() % 20) + 1;
  damage_2 = attack_value;
  if (random_number >= crit_dice_)
  {
    damage_2 *= crit_;
  }
  return (damage_1 + damage_2);
}

int ShortSword::attack()
{
  int attack_value = Weapon::attack();
  int multiplier = (rand() % multiplier_) + 1;
  int damage = attack_value * multiplier;
  return damage;
}

void Enemy::receive_attack(Weapon * wep)
{
  int damage;
  if (health_ > 0)
  {
    damage = wep->attack();
    health_ -= damage;
    std::cout << wep->name() << " dealt " << damage << " damage to " << name_
              << "\n";
    if (health_ <= 0)
    {
      std::cout << name_ << " has been slain!" << std::endl;
      health_ = 0;
    }
  }
}
