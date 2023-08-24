#include "pair_class_template.hpp"
#include <iostream>

int main()
{
  MyPair<int> p1(3, 5);
  p1.display();
  std::cout << "\n";
  p1.display_reverse();
  std::cout << "\n";
  std::cout << p1.max_value() << "\n";
  std::cout << p1.min_value() << "\n";
  p1.swap_value();
  p1.display();
  std::cout << "\n";
  p1.display_reverse();
  std::cout << "\n";

  MyPair<double> p2(9.7, 6.4);
  p2.display();
  std::cout << "\n";
  p2.display_reverse();
  std::cout << "\n";
  std::cout << p2.max_value() << "\n";
  std::cout << p2.min_value() << "\n";
  p2.swap_value();
  p2.display();
  std::cout << "\n";
  p2.display_reverse();
  std::cout << "\n";

  MyPair<char> p3('a', 'z');
  p3.display();
  std::cout << "\n";
  p3.display_reverse();
  std::cout << "\n";
  std::cout << p3.max_value() << "\n";
  std::cout << p3.min_value() << "\n";
  p3.swap_value();
  p3.display();
  std::cout << "\n";
  p3.display_reverse();
  std::cout << "\n";

  return 0;
}
