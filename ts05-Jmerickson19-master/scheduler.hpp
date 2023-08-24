#include <iostream>
#include <iomanip>

const int CONVERT = 100;
class TimeSpan
{
private:
  int start_time_;
  int end_time_;

public:
  TimeSpan() : start_time_(0000), end_time_(0000) {}
  TimeSpan(int start_time, int end_time)
      : start_time_(start_time), end_time_(end_time)
  {
  }
  void set_start_time(int start_time);
  void set_end_time(int end_time);
  int start_time() const;
  int end_time() const;
  bool operator<(const TimeSpan & right);
  bool operator>(const TimeSpan & right);

  void display()
  {
    int s_time;
    int e_time;
    s_time = start_time();
    std::cout << "Start time: " << s_time / CONVERT << ":" << std::setw(2)
              << std::setfill('0') << s_time % CONVERT << "\n";
    e_time = end_time();
    std::cout << "End time: " << e_time / CONVERT << ":" << std::setw(2)
              << std::setfill('0') << e_time % CONVERT << "\n";
  }
};

class Course
{
private:
  std::string course_name_;
  std::string location_;
  std::string weekly_schedule_;
  TimeSpan time_;

public:
  Course() : course_name_(""), location_(""), weekly_schedule_("") {}
  Course(std::string course_name, std::string location,
         std::string weekly_schedule, TimeSpan timespan)
      : course_name_(std::move(course_name)), location_(std::move(location)),
        weekly_schedule_(std::move(weekly_schedule)), time_(timespan)
  {
  }

  void set_course_name(std::string course_name)
  {
    course_name_ = std::move(course_name);
  }
  std::string course_name() { return course_name_; }
  void set_location(std::string location) { location_ = std::move(location); }
  std::string location() { return location_; }
  void set_weekly_schedule(std::string weekly_schedule)
  {
    weekly_schedule_ = std::move(weekly_schedule);
  }
  std::string weekly_schedule() { return weekly_schedule_; }
  void set_time(TimeSpan time) { time_ = time; }
  TimeSpan time() { return time_; }

  void display();

  bool intersects(Course * cpointer);
};

class CourseSchedule
{
private:
  Course * courses_[CONVERT];
  int num_courses_;
  bool has_conflict(Course * cpointer);

public:
  CourseSchedule() : num_courses_(0) {}
  ~CourseSchedule();

  void set_num_courses(int num_courses) { num_courses_ = num_courses; }
  int num_courses() { return num_courses_; }

  bool add(std::string course_name, std::string location, std::string dotw,
           int start_time, int end_time);

  void display();
};

bool load_schedule(const std::string & filename,
                   CourseSchedule & courseSchedule);
