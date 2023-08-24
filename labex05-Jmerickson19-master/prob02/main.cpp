#include <iomanip>
#include <iostream>
#include "bubble.hpp"

int main()
{
  double radius1;
  double radius2;

  // Two Bubble objects called bubble1 and bubble2
  Bubble bubble1;
  Bubble bubble2;

  // Get the radius of both bubbles from the user
  std::cout << "Please enter the radius of the first bubble: ";
  std::cin >> radius1;
  std::cout << "Please enter the radius of the second bubble: ";
  std::cin >> radius2;

  // Set the radius of bubble1 to radius1 and bubble2 to radius2
  bubble1.set_radius(radius1);
  bubble2.set_radius(radius2);

  // Use the overloaded operator== function to determine whether
  // bubble1 and bubble2 are the same size
  if (bubble1.operator==(bubble2))
  {
    std::cout << "Your bubbles are the same size.\n";
  }

  // Create a new Bubble object called combined, and call the
  // overloaded operator+ function to combine bubble1 and bubble2
  Bubble combined;
  combined = bubble1.operator+(bubble2);

  // Get the volume of the combined Bubble object and print it out
  double volume;
  std::cout << "The bubbles have now combined and created a bubble with the "
            << "volume of: " << std::fixed << std::setprecision(2)
            << combined.volume() << std::endl;
  return 0;
}
