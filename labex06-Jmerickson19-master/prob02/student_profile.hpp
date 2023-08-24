#include <iostream>

class Student
{
private:
  std::string name_;
  std::string cmajor_;
  unsigned int cwid_;
  double gpa_;

public:
  // Mutators
  void set_name(std::string name);
  void set_cmajor(std::string cmajor);
  void set_cwid(unsigned int cwid);
  void set_gpa(double gpa);
  // Accessors
  std::string name();
  std::string cmajor();
  unsigned int cwid();
  double gpa();
};

double average_gpa(Student array[], unsigned int size);
