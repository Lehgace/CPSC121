#include "student_profile.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  unsigned int num_student;
  std::cout << "Enter number of students: ";
  std::cin >> num_student;
  std::cin.ignore();

  // Create an array of student objects named stud_arr. The size of the array
  // should be the number of students based on user input

  Student stud_arr[num_student];

  for (unsigned int i = 0; i < num_student; i++)
  {
    Student curr_student;
    std::string name;
    std::string cmajor;
    unsigned int cwid;
    double gpa;

    std::cout << "\nEnter student " << i + 1 << " name: ";
    std::getline(std::cin, name);
    curr_student.set_name(name);

    std::cout << "Enter student " << i + 1 << " major: ";
    getline(std::cin, cmajor);
    curr_student.set_cmajor(cmajor);

    std::cout << "Enter student " << i + 1 << " cwid: ";
    std::cin >> cwid;

    curr_student.set_cwid(cwid);

    std::cout << "Enter student " << i + 1 << " gpa: ";
    std::cin >> gpa;
    curr_student.set_gpa(gpa);
    std::cin.ignore();

    // Store the student object curr_student in the student array named
    // stud_arr. Use the appropriate index so that the object is placed at the
    // end of the list

    stud_arr[num_student - (i + 1)] = curr_student;
  }

  double average;
  // Compute the average gpa by using the average_gpa function and storing it in
  // the variable called average

  average = average_gpa(stud_arr, num_student);
  std::cout << "\nThe average gpa of " << num_student << " student(s) is "
            << std::fixed << std::setprecision(2) << average << std::endl;
  return 0;
}
