#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../min.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

class Min : public ::testing::Test {
protected:
  int unittest_array[5] = {4, 1, 6, 2, 3};
};

TEST(Min, OneElement) {
  int unittest_array[1] = {4};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(min(unittest_array, 1), 4)  
      << "   The minimum value in a 1-element array is the element.";
  })  
}

TEST(Min, MinFirst) {
  int unittest_array[5] = {-2, 10, 6, -1, 3};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(min(unittest_array, 5), -2)  
      << "   The minimum value in the array [-2, 10, 6, -1, 3] is -2.";
  })  
}

TEST(Min, MinMiddle) {
  int unittest_array[5] = {6, 10, -2, -1, 3};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(min(unittest_array, 5), -2)  
      << "   The minimum value in the array [6, 10, -2, -1, 3] is -2.";
  })  
}

TEST(Min, MinLast) {
  int unittest_array[5] = {6, 10, 3, -1, -2};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(min(unittest_array, 5), -2)  
      << "   The minimum value in the array [6, 10, 3, -1, -2] is -2.";
  })  
}

TEST(Drive, ProgramExits) {
  ASSERT_EXECEXIT("main", "", 3)
    << "      Your program should exit.";
}

TEST(Driver, Min) {
  ASSERT_EXECTHAT("main", "", HasSubstr("-40"))
    << "      Your program should display the minimum value, -40, from the array [-1, 22, 54, 33, -40, 67, 8, 15, -28, 1].";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
