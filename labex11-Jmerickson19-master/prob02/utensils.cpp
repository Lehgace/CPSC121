#include "utensils.hpp"
#include <iostream>

void Utensil::use(Food & object) {}

void Spoon::use(Food & object) { object.eat(bite_size_); }

void Food::eat(double eat)
{
  if (mass_ >= eat)
  {
    mass_ -= eat;
  }
  else
  {
    mass_ = 0.0;
  }
}
