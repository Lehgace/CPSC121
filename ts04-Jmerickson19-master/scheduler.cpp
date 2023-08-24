#include "scheduler.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

const int MIN_MNTS = 0;
const int MIN_HR = 0;
const int MAX_MNTS = 59;
const int MAX_HR = 24;
const int HR_OFFSET = 100;

void Course::set_course_name(std::string course_name)
{
  course_name_ = std::move(course_name);
}
void Course::set_location(std::string location)
{
  location_ = std::move(location);
}
void Course::set_weekly_schedule(std::string weekly_schedule)
{
  weekly_schedule_ = std::move(weekly_schedule);
}
void Course::set_start_time(int start_time) { start_time_ = start_time; }
void Course::set_end_time(int end_time) { end_time_ = end_time; };

std::string Course::course_name() { return course_name_; }
std::string Course::location() { return location_; }
std::string Course::weekly_schedule() { return weekly_schedule_; }
int Course::start_time() { return start_time_; }
int Course::end_time() { return end_time_; }

void Course::display()
{
  int s_time;
  int e_time;

  std::cout << "Course name: " << course_name() << "\n";
  std::cout << "Location: " << location() << "\n";
  std::cout << "Weekly schedule: " << weekly_schedule() << "\n";
  s_time = start_time();
  std::cout << "Start time: " << s_time / HR_OFFSET << ":" << std::setw(2)
            << std::setfill('0') << s_time % HR_OFFSET << "\n";
  e_time = end_time();
  std::cout << "End time: " << e_time / HR_OFFSET << ":" << std::setw(2)
            << std::setfill('0') << e_time % HR_OFFSET << "\n";
}

bool load_schedule(const std::string & filename, Course * courses[],
                   int & courses_size)
{

  bool valid = true;
  std::ifstream input_file;

  std::string course;
  std::string location;
  std::string day_symbol;
  int start_hr = 0;
  int start_min = 0;
  char start_colon;
  int end_hr = 0;
  int end_min = 0;
  char end_colon;

  input_file.open(filename);

  if (!input_file)
  {
    std::cout << "Error: File does not exist - " << filename << ".\n";
    valid = false;
  }
  else
  {
    while (getline(input_file, course) && valid)
    {
      if (!getline(input_file, location))
      {
        valid = false;
        std::cout << "Error: Unable to get a location.\n";
      }
      else if (!getline(input_file, day_symbol))
      {
        valid = false;
        std::cout << "Error: Unable to get a weekly schedule.\n";
      }
      else if (day_symbol != "M" && day_symbol != "T" && day_symbol != "W" &&
               day_symbol != "H" && day_symbol != "F" && day_symbol != "S" &&
               day_symbol != "MW" && day_symbol != "MF" && day_symbol != "TH")
      {
        valid = false;
        std::cout << "Error: Invalid weekly schedule symbol " << day_symbol
                  << ".\n";
      }
      else if (!(input_file >> start_hr >> start_colon >> start_min))
      {
        valid = false;
        std::cout << "Error: Unable to get a valid start time.\n";
      }
      else if (start_hr < MIN_HR || start_hr > MAX_HR || start_min < MIN_MNTS ||
               start_min > MAX_MNTS || start_colon != ':')
      {
        valid = false;
        std::cout << "Error: " << start_hr << start_colon << start_min
                  << " is an invalid start time.\n";
      }
      else if (!(input_file >> end_hr >> end_colon >> end_min))
      {
        valid = false;
        std::cout << "Error: Unable to get a valid end time.\n";
      }
      else if (end_hr < MIN_HR || end_hr > MAX_HR || end_min < MIN_MNTS ||
               end_min > MAX_MNTS || end_colon != ':')
      {
        valid = false;
        std::cout << "Error: " << end_hr << end_colon << end_min
                  << " is an invalid end time.\n";
      }
      else if (end_hr < start_hr || (start_hr == end_hr && end_min < start_min))
      {
        valid = false;
        std::cout << "Error: The start time " << start_hr << ":" << start_min
                  << " should happen before the end time " << end_hr << ":"
                  << end_min << ".\n";
      }

      int start_time = start_hr * HR_OFFSET + start_min;
      int end_time = end_hr * HR_OFFSET + end_min;
      Course * pCourse = new Course;

      pCourse->set_course_name(course);
      pCourse->set_location(location);
      pCourse->set_weekly_schedule(day_symbol);
      pCourse->set_start_time(start_time);
      pCourse->set_end_time(end_time);

      courses[courses_size] = pCourse;
      courses_size++;

      input_file.ignore();
    }
    input_file.close();
  }
  if (!valid)
  {
    std::cout << "Invalid file.\n";
  }
  return valid;
}

void display_courses(Course * courses[], int size)
{
  for (int i = 0; i < size; i++)
  {
    courses[i]->display();
    std::cout << "\n";
  }
}

void TimeSpan::set_start_time(int start_time) { start_time_ = start_time; }
void TimeSpan::set_end_time(int end_time) { end_time_ = end_time; }
int TimeSpan::start_time() { return start_time_; }
int TimeSpan::end_time() { return end_time_; }
bool TimeSpan::operator<(TimeSpan & other)
{
  return (end_time() < other.start_time());
}
bool TimeSpan::operator>(TimeSpan & other)
{
  return (start_time() > other.end_time());
}
bool has_conflict(TimeSpan object, TimeSpan timespan[], int size)
{
  bool conflict = false;
  for (int i = 0; i < size; i++)
  {
    if (!(object < timespan[i]))
    {
      if (!(object > timespan[i]))
      {
        conflict = true;
        break;
      }
    }
  }
  return conflict;
}
