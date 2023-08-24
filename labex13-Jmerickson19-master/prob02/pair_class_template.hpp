#include <iostream>

template <class T> class MyPair
{
private:
  T value1_;
  T value2_;

public:
  MyPair(T value1, T value2) : value1_(value1), value2_(value2) {}

  void set_value1(T value1) { value1_ = value1; }
  T value1() { return value1_; }
  void set_value2(T value2) { value2_ = value2; }
  T value2() { return value2_; }

  void display() { std::cout << "[" << value1_ << ", " << value2_ << "]"; }

  void display_reverse()
  {
    std::cout << "[" << value2_ << ", " << value1_ << "]";
  }

  T max_value()
  {
    T max;
    if (value1_ > value2_)
    {
      max = value1_;
    }
    else
    {
      max = value2_;
    }
    return max;
  }

  T min_value()
  {
    T min;
    if (value1_ < value2_)
    {
      min = value1_;
    }
    else
    {
      min = value2_;
    }
    return min;
  }

  void swap_value()
  {
    T temp = value1_;
    value1_ = value2_;
    value2_ = temp;
  }
};
