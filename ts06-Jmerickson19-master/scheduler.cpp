#include "scheduler.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

const int MIN_MNTS = 0;
const int MIN_HR = 0;
const int MAX_MNTS = 59;
const int MAX_HR = 24;
const int HR_OFFSET = 100;

//==================================================
// Course
//==================================================

void Course::display()
{

  std::cout << "Course name: " << course_name() << "\n";
  std::cout << "Location: " << location() << "\n";
  std::cout << "Weekly schedule: " << weekly_schedule() << "\n";

  time_.display();
}

bool Course::intersects(Course * cpointer)
{
  bool intersects = false;
  if ((weekly_schedule_ == cpointer->weekly_schedule()) ||
      ((weekly_schedule_ == "MW") && ((cpointer->weekly_schedule() == "M") ||
                                      (cpointer->weekly_schedule() == "W"))) ||
      ((weekly_schedule_ == "MF") && ((cpointer->weekly_schedule() == "M") ||
                                      (cpointer->weekly_schedule() == "F"))) ||
      ((cpointer->weekly_schedule() == "MW") &&
       ((weekly_schedule_ == "M") || (weekly_schedule_ == "W"))) ||
      ((cpointer->weekly_schedule() == "MF") &&
       ((weekly_schedule_ == "T") || (weekly_schedule_ == "H"))) ||
      ((weekly_schedule_ == "TH") && ((cpointer->weekly_schedule() == "T") ||
                                      (cpointer->weekly_schedule() == "H"))) ||
      ((cpointer->weekly_schedule() == "TH") &&
       ((weekly_schedule_ == "T") || (weekly_schedule_ == "H"))))
  {
    if (!(time_ < cpointer->time()))
    {
      if (!(time_ > cpointer->time()))
      {
        intersects = true;
      }
    }
  }
  return intersects;
}

//==================================================
// CourseSchedule
//==================================================

bool CourseSchedule::has_conflict(Course * cpointer)
{
  bool conflict = false;
  for (int i = 0; i < num_courses_; i++)
  {
    if (courses_[i]->intersects(cpointer))
    {
      conflict = true;
      break;
    }
  }

  return conflict;
}

bool CourseSchedule::add(std::string course_name, std::string location,
                         std::string dotw, int start_time, int end_time)
{
  bool ok = false;
  Course * pCourse =
      new Course(std::move(course_name), std::move(location), std::move(dotw),
                 TimeSpan(start_time, end_time));
  if (remove_conflicts_)
  {
    if (has_conflict(pCourse))
    {
      delete pCourse;
    }
    else
    {
      courses_[num_courses_] = pCourse;
      num_courses_++;
      ok = true;
    }
  }
  else
  {
    courses_[num_courses_] = pCourse;
    num_courses_++;
    ok = true;
  }
  return ok;
}

bool CourseSchedule::add(Course * pCourse)
{
  return add(pCourse->course_name(), pCourse->location(),
             pCourse->weekly_schedule(), pCourse->time().start_time(),
             pCourse->time().end_time());
}

void CourseSchedule::display()
{
  for (int i = 0; i < num_courses_; i++)
  {
    courses_[i]->display();
    std::cout << "\n";
  }
}

Course * CourseSchedule::course(int index) { return courses_[index]; }

CourseSchedule::~CourseSchedule()
{
  for (int i = 0; i < num_courses_; i++)
  {
    delete courses_[i];
  }
}

//==================================================
// TimeSpan
//==================================================

void TimeSpan::set_start_time(int start_time) { start_time_ = start_time; }
void TimeSpan::set_end_time(int end_time) { end_time_ = end_time; }
int TimeSpan::start_time() const { return start_time_; }
int TimeSpan::end_time() const { return end_time_; }
bool TimeSpan::operator<(const TimeSpan & right)
{
  return (end_time() < right.start_time());
}
bool TimeSpan::operator>(const TimeSpan & right)
{
  return (start_time() > right.end_time());
}

// Schedule manager Functions
bool ScheduleManager::load_schedule(const std::string & filename)
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

      complete_schedule_.add(course, location, day_symbol, start_time,
                             end_time);
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

CourseSchedule * ScheduleManager::best_schedule(const std::string & filename)
{
  bool valid = load_schedule(filename);
  if (!valid)
  {
    best_schedule_ = nullptr;
  }
  else
  {
    int num_courses = complete_schedule_.num_courses();
    Course * parray[num_courses];
    int i;

    for (i = 0; i < num_courses; i++)
    {
      parray[i] = complete_schedule_.course(i);
    }

    int max = 0;
    CourseSchedule * pCourseSchedule;
    int permutation = 0;
    do
    {
      pCourseSchedule = new CourseSchedule(true);
      for (i = 0; i < num_courses; i++)
      {
        pCourseSchedule->add(parray[i]);
      }
      int num = pCourseSchedule->num_courses();
      if (num > max)
      {
        max = num;
        if (best_schedule_ != nullptr)
        {
          delete best_schedule_;
        }
        best_schedule_ = pCourseSchedule;
      }
      else
      {
        delete pCourseSchedule;
      }
    } while (std::next_permutation(parray, parray + num_courses));
  }
  return best_schedule_;
}

ScheduleManager::~ScheduleManager()
{
  if (best_schedule_ != nullptr)
  {
    delete best_schedule_;
  }
}
