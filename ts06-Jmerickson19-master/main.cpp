#include "scheduler.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
  std::string filename;
  std::cout << "Welcome to Tuffy Scheduler!\n";

  std::cout << "Please enter the file name containing the list of classes: ";
  std::cin >> filename;

  ScheduleManager scheduleManager;
  CourseSchedule * courseSchedule = scheduleManager.best_schedule(filename);
  if (courseSchedule != nullptr)
  {
    courseSchedule->display();
    std::cout << "Thank you for using Tuffy Scheduler.\n";
  }
  return 0;
}
