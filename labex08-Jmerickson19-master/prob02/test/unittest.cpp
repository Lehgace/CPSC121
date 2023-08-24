#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"
#include "../calculate_avg.hpp"

using ::testing::HasSubstr;

class CalculateAverage : public ::testing::Test {
protected:
  void SetUp() override {
    unittest_array = new double[5];
    unittest_array[0] = 1.5;
    unittest_array[1] = 2.5;
    unittest_array[2] = 4.0;
    unittest_array[3] = 3.0;
    unittest_array[4] = 3.5;
  }

  ~CalculateAverage() {
    delete[] unittest_array;
  }

  double* unittest_array;
};

TEST_F(CalculateAverage, NoElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(calculate_avg(unittest_array, 0), 0);
  })
}

TEST_F(CalculateAverage, OneElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(calculate_avg(unittest_array, 1), 1.5);
  })
}

TEST_F(CalculateAverage, MultipleElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(calculate_avg(unittest_array, 3), 2.6666666666666665);
  })
}

TEST_F(CalculateAverage, MultipleElement2) {
  ASSERT_DURATION_LE(3, {
    ASSERT_DOUBLE_EQ(calculate_avg(unittest_array, 5), 2.9);
  })
}

TEST(UserInput, AskInput) {
  std::string user_input = "3\n3\n2\n4\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number of students, in this case 3, and then the GPA for each student.";
}

TEST(Driver, NoClass) {
  std::string user_input = "0\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("You have no class!"))
    << "      Your program should show an error message when the user inputs a class with no students.";
}

TEST(Driver, ClassAverage) {
  std::string user_input = "5\n3.8\n2.5\n4.0\n1.9\n3.6\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("3.16"))
    << "      Your program should display the correct average, 3.16.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
