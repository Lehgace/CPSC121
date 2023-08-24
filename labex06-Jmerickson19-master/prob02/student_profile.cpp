#include "student_profile.hpp"
#include <iostream>

void Student::set_name(std::string name) { name_ = std::move(name); }
void Student::set_cmajor(std::string cmajor) { cmajor_ = std::move(cmajor); }
void Student::set_cwid(unsigned int cwid) { cwid_ = cwid; }
void Student::set_gpa(double gpa) { gpa_ = gpa; }

std::string Student::name() { return name_; }
std::string Student::cmajor() { return cmajor_; }
unsigned int Student::cwid() { return cwid_; }
double Student::gpa() { return gpa_; }

double average_gpa(Student array[], unsigned int size)
{
  double gpa_avg;
  double summand;

  double total = 0;
  for (unsigned int i = 0; i < size; i++)
  {

    summand = array[i].gpa();
    total += summand;
  }
  gpa_avg = total / size;
  return gpa_avg;
}
