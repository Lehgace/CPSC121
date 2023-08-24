#include "find_number.hpp"
#include <iostream>

int main()
{
  // Create an instance of the `numbers` object
  Numbers n;

  // Call `display_array` method
  n.display_array();

  // Call `find_number` method
  n.find_number(2);
  n.find_number(3);
  n.find_number(10);
  n.find_number(15);
  n.find_number(16);
  n.find_number(21);

  return 0;
}
