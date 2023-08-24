#include <iostream>

class Numbers
{
private:
  int * values_;
  int capacity_;
  void init();

public:
  Numbers() : capacity_{10}
  {
    values_ = new int[capacity_];
    init();
  }

  Numbers(int size) : capacity_(size)
  {
    values_ = new int[capacity_];
    init();
  }

  ~Numbers()
  {
    delete[] values_;
    values_ = nullptr;
  }

  int capacity() { return capacity_; }

  void find_number(int number)
  {
    for (int i = 0; i < capacity_; i++)
    {
      if (*(values_ + i) == number)
      {
        std::cout << number << " is in the array\n";
      }
    }
  }

  void display_array()
  {
    for (int i = 0; i < capacity_; i++)
    {
      std::cout << *(values_ + i) << " ";
    }
    std::cout << "\n";
  }
};
