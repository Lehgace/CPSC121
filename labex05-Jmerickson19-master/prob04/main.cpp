#include <iostream>

int main() {
  unsigned short int mil_time = 0;
  std::cout << "Please enter the time in military time: ";
  std::cin >> mil_time;

  // Call your function to convert from military time to regular time
  // and assign it's result to reg_time
  std::string reg_time;

  std::cout << "The equivalent regular time is: " << reg_time << "\n";
  return 0;
}