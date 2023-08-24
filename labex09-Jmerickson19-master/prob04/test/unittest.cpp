#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../student.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(Student, DefaultConstructor) {
  Student your_student;
  ASSERT_EQ(your_student.name(), "Stu Dent") << "The default name of the student should be Stu Dent.";
  ASSERT_EQ(your_student.id(), 123456789) << "The default id of the student should be 123456789.";
  ASSERT_EQ(your_student.num_grades(), 0) << "The value of num_grades should be 0.";
}

TEST(Student, NonDefaultConstructor) {
  Student your_student("Paul Inventado", 90911);
  ASSERT_EQ(your_student.name(), "Paul Inventado") << "The name of the student should be Paul Inventado";
  ASSERT_EQ(your_student.id(), 90911) << "The id of the student should be 90911";
  ASSERT_EQ(your_student.num_grades(), 0)  << "The value of num_grades should be 0.";
}

TEST(Student, AccessorsMutators) {
  Student your_student;
  your_student.set_name("Sunny To");
  your_student.set_id(12213);
  ASSERT_EQ(your_student.name(), "Sunny To") << "The name of the student should be set to Sunny To.";
  ASSERT_EQ(your_student.id(), 12213) << "The id of the student should be set to 12213.";
}
TEST(Student, AddGradesNumGrades) {
  Student your_student;
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  ASSERT_EQ(your_student.num_grades(), 3) << "The number of grades should be 3 after adding three grades.";  
}

TEST(Student, AddGradesFull) {
  Student your_student;
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  your_student.add_grade(90);
  SIMULATE_SIO("", {
    your_student.add_grade(90);
  }, {
    ASSERT_THAT(your_output, HasSubstr("Array full, unable to add grade"))
      << "The function should tell the user that the array is full after adding the 11th element.";     
  });
}

TEST(Student, CalculateGrade) {
  Student your_student;
  your_student.add_grade(90);
  your_student.add_grade(85);
  your_student.add_grade(95);
  your_student.add_grade(95);
  ASSERT_EQ(your_student.num_grades(), 4) << "The number of grades should be 4 after adding four grades.";  
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(your_student.calculate_grade(), 91.25) << "The average of four grades 90, 85, 95, 95, should be 91.25.";
  });
}

TEST(Student, PrintStudent) {
  Student your_student;
  your_student.set_name("Ada Lovelace");
  your_student.add_grade(70);
  your_student.add_grade(80);
  your_student.add_grade(90);
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", {
      your_student.print_student();
    }, {
      ASSERT_THAT(your_output, HasSubstr("Ada Lovelace")) << "The name of the student should be Ada Lovelace.";
      ASSERT_THAT(your_output, HasSubstr("70")) << "The grades of the student should contain 70.";
      ASSERT_THAT(your_output, HasSubstr("80")) << "The grades of the student should contain 80.";
      ASSERT_THAT(your_output, HasSubstr("90")) << "The grades of the student should contain 90.";
    });
  });
}

TEST(Driver, Output)
{
  std::string expected = "Lonnie Hansen 965137824\nTest Grades:\n"
                         "95\n88\n92\n77\n84\nTotal grade = 87.20\n";
  ASSERT_EXECEQ("main", "", expected);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
