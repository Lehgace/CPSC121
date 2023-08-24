#include <iostream>

class Course
{
private:
  std::string course_name_;
  std::string location_;
  std::string weekly_schedule_;
  int start_time_;
  int end_time_;

public:
  void set_course_name(std::string course_name);
  void set_location(std::string location);
  void set_weekly_schedule(std::string weekly_schedule);
  void set_start_time(int start_time);
  void set_end_time(int end_time);

  std::string course_name();
  std::string location();
  std::string weekly_schedule();
  int start_time();
  int end_time();

  void display();
};

class TimeSpan
{
private:
  int start_time_;
  int end_time_;

public:
  void set_start_time(int start_time);
  void set_end_time(int end_time);
  int start_time();
  int end_time();
  bool operator<(TimeSpan & other); // true of end < start
  bool operator>(TimeSpan & other); // true if start > end time
};

bool load_schedule(const std::string & filename, Course courses[], int & size);

void display_courses(Course courses[], int size);

bool has_conflict(TimeSpan object, TimeSpan timespan[], int size);
