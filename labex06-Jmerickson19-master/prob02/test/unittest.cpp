#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../student_profile.hpp"
#include "gtest_ext.h"

using testing::HasSubstr;

class AverageGPA : public ::testing::Test {
protected:
  void SetUp() override {
    student1.set_name("Student 1");
    student1.set_cmajor("Computer Science");
    student1.set_cwid(123456);
    student1.set_gpa(2.0);

    student2.set_name("Student 2");
    student2.set_cmajor("Computer Science");
    student2.set_cwid(78910);
    student2.set_gpa(3.5);

    student3.set_name("Student 3");
    student3.set_cmajor("Computer Science");
    student3.set_cwid(11223344);
    student3.set_gpa(1.5);

    student4.set_name("Student 4");
    student4.set_cmajor("Computer Science");
    student4.set_cwid(22334455);
    student4.set_gpa(4.0);

    student5.set_name("Student 5");
    student5.set_cmajor("Computer Science");
    student5.set_cwid(667788);
    student5.set_gpa(2.5);
  }

  Student student1, student2, student3, student4, student5;
};

TEST(Student, PublicMethodPresent) {
  Student your_student;
  your_student.name();
  your_student.cmajor();
  your_student.cwid();
  your_student.gpa();
  your_student.set_name("name");
  your_student.set_cmajor("major");
  your_student.set_cwid(1);
  your_student.set_gpa(2.0);
}

TEST(Student, MutatorsAndAccessors) {
  Student your_student;

  your_student.set_name("Grace Hopper");
  your_student.set_cmajor("Computer Science");
  your_student.set_cwid(888221234);
  your_student.set_gpa(4.0);

  ASSERT_EQ(your_student.name(), "Grace Hopper") << "      The class' mutator should set the name to Grace Hopper and your accessor should return the same value.";
  ASSERT_EQ(your_student.cmajor(), "Computer Science") << "      The class' mutator should set cmajor to Computer Science and your accessor should return the same value.";
  ASSERT_EQ(your_student.cwid(), 888221234) << "      The class' mutator should set the cwid to 888221234 and your accessor should return the same value.";
  ASSERT_EQ(your_student.gpa(), 4.0) << "      The class' mutator should set the gpa to 4.0 and your accessor should return the same value.";
}

TEST_F(AverageGPA, OneStudent) {
  Student students[] = {student1};
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(average_gpa(students, 1), 2.0) 
      << "      The average gpa should be 2.0."; 
  })
}

TEST_F(AverageGPA, TwoStudents) {
  Student students[] = {student5, student4};
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(average_gpa(students, 2), 3.25)  
      << "      The average gpa should be 3.25 given two student gpas: 4.0 and 2.5."; 
  })
}

TEST_F(AverageGPA, ThreeStudents) {
  Student students[] = {student2, student4, student3};
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(average_gpa(students, 3), 3)
      << "      The average gpa should be 3 given three student gpas: 3.5, 4.0, and 1.5.";  
  })
}

TEST_F(AverageGPA, FourStudents) {
  Student students[] = {student2, student4, student1, student3};
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(average_gpa(students, 4), 2.75)
      << "      The average gpa should be 2.75 given four student gpas: 3.5, 4.0, 2.0, and 1.5.";    
  })
}

TEST(UserInput, OneStudent) {
  std::string user_input = "1\nStudent 1\nComputer Science\n11223344\n3.5\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for information about a single student.";
}

TEST(UserInput, TwoStudents) {
  std::string user_input = "2\nStudent 1\nComputer Science\n11223344\n3.5\nStudent 2\nMath\n554433\n2.5\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for information about two students.";
}

TEST(UserInput, ThreeStudents) {
  std::string user_input = "3\nStudent 1\nComputer Science\n11223344\n3.5\nStudent 2\nMath\n554433\n2.5\nStudent 3\nChemistry\n6523341\n3.0\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for information about two students.";
}

TEST(Driver, ShowAverageGPA) {
  std::string user_input = "3\nStudent 1\nComputer Science\n11223344\n3.5\nStudent 2\nMath\n554433\n2.5\nStudent 3\nChemistry\n6523341\n3.0\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The average gpa of 3 student(s) is 3.00"))
    << "      Your program should show the average of three students' GPA that is 3.00.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
