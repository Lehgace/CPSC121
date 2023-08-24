#include "scheduler.hpp"
#include <fstream>
#include <iostream>
#include <string>

const int ARRAY_SIZE = 100;

int main()
{
  std::string filename;
  std::cout << "Welcome to Tuffy Scheduler!\n";

  std::cout << "Please enter the file name containing the list of classes: ";
  std::cin >> filename;

  int courses_size = 0;
  Course * courses[ARRAY_SIZE];
  bool is_valid;
  is_valid = load_schedule(filename, courses, courses_size);
  if (is_valid)
  {
    display_courses(courses, courses_size);
  }
  std::cout << "Thank you for using Tuffy Scheduler.\n";

  return 0;
}
