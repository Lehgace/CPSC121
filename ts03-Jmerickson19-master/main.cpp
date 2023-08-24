#include <iostream>
#include <string>
#include "scheduler.hpp"

int main()
{
  const int APPOINTMENTS_MAX = 100;
  char option = ' ';
  int start_time = 0;
  int end_time = 0;
  int num_appointments = 0;
  TimeSpan appointments[APPOINTMENTS_MAX];

  std::cout << "Welcome to Appointment Scheduler!\n";
  std::cout
      << "Let's create your schedule. Please provide all times you are busy.\n";
  do
  {
    std::cout << "Start time (0000 - 2359): ";
    std::cin >> start_time;
    std::cout << "End time (0000 - 2359): ";
    std::cin >> end_time;
    TimeSpan temp;
    temp.set_start_time(start_time);
    temp.set_end_time(end_time);
    appointments[num_appointments++] = temp;
    std::cout << "Do you want to add another schedule? (Y/N): ";
    std::cin >> option;
  } while (option != 'n' && option != 'N');

  std::cout
      << "\nNow let's schedule an appointment! When do you want to meet?\n";
  bool found_appointment = false;
  do
  {
    std::cout << "Start time (0000 - 2359): ";
    std::cin >> start_time;
    std::cout << "End time (0000 - 2359): ";
    std::cin >> end_time;
    TimeSpan temp;
    temp.set_start_time(start_time);
    temp.set_end_time(end_time);
    if (has_conflict(temp, appointments, num_appointments))
    {
      std::cout << "Unfortunately, that time conflicts with an appointment. "
                   "Please select another time.\n";
    }
    else
    {
      found_appointment = true;
      std::cout << "That schedule works! Your appointment is set to "
                << start_time << " - " << end_time << "\n";
    }
  } while (!found_appointment);

  return 0;
}
