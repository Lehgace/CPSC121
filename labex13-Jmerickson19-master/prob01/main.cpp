#include "array_double.hpp"
#include <iostream>

int main()
{
  int num_elements;
  int location;
  double value;
  std::cout << "Please enter the number of elements for your array: ";
  std::cin >> num_elements;

  try
  {
    ArrayDouble myArray(num_elements);
    if (num_elements > 0)
    {
      std::cout << "Enter a value you would like to add to the array: ";
      std::cin >> value;
      std::cout << "Where would you like to add this number"
                << " (array index 0 to " << num_elements - 1 << ")? ";
      std::cin >> location;

      myArray.operator[](location);
      std::cout << "Value at location " << location << " now contains "
                << myArray[location] << std::endl;
    }
    myArray.display();
  }
  catch (const InvalidArrayLengthException & e)
  {
    std::cout << e.message() << std::endl;
  }
  catch (const IndexOutOfRangeException & r)
  {
    std::cout << r.message() << std::endl;
  }
  return 0;
}
