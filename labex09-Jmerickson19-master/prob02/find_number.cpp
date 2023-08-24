#include "find_number.hpp"
void Numbers::init()
{
  for (int i = 0; i < capacity_; i++)
  {
    *(values_ + i) = i * 2 + 2;
  }
}
