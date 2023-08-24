#include "array_double.hpp"
#include <iomanip>
#include <iostream>

ArrayDouble::ArrayDouble(int num)
{
  array_ = nullptr;
  num_ = 0;
  if (num >= 0)
  {
    num_ = num;
    array_ = new double[num_];
    for (int i = 0; i < num_; i++)
    {
      array_[i] = 0.0;
    }
  }
  else
  {
    throw InvalidArrayLengthException(num);
  }
}

ArrayDouble::~ArrayDouble() { delete[] array_; }

double & ArrayDouble::operator[](int ix) const
{
  if (ix <= num_ - 1 && ix >= 0)
  {
    return array_[ix];
  }
  else
  {
    throw IndexOutOfRangeException(ix, num_);
  }
}
void ArrayDouble::display() const
{
  if (num_ == 0)
  {
    std::cout << "Array is empty.\n";
  }
  else
  {
    std::cout << "Array contents:";
    for (int i = 0; i < num_; i++)
    {
      std::cout << ' ' << std::setprecision(2) << std::fixed << array_[i];
    }
    std::cout << "\n";
  }
}
