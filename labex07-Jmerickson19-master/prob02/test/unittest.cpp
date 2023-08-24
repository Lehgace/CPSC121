#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../array_max.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

class ArrayMax : public ::testing::Test {
protected:
  int number_array[10] = {3, 16, 22, 8, 11, 4, 31, 34, 27, 55};
  int number_array_reverse[10] = {55, 27, 34, 31, 4, 11, 8, 22, 16, 3};
  int number_array_mid[10] = {3, 16, 22, 8, 11, 4, 55, 34, 27, 31};
};

TEST_F(ArrayMax, EmptyArray) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array, 0), -1)
      << "   The function should return -1 if the size of the array is invalid.";
  })
}

TEST_F(ArrayMax, OneElementArray) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array, 1), 3)
      << "   The function should return 3 as the largest number in the array [3].";
  })
}

TEST_F(ArrayMax, TwoElementArraySmallerFirst) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array, 2), 16)
      << "   The function should return 16 as the largest number in the array [3, 16].";
  })
}

TEST_F(ArrayMax, TwoElementArrayBiggerFirst) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array_reverse, 2), 55)
      << "   The function should return 55 as the largest number in the array [55, 27].";
  })
}

TEST_F(ArrayMax, MultiElementArrayBiggestLast) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array, 10), 55)
      << "   The function should return 55 as the largest number in the array [3, 16, 22, 8, 11, 4, 31, 34, 27, 55].";
  })
}

TEST_F(ArrayMax, MultiElementArrayBiggestFirst) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array_reverse, 10), 55)
      << "   The function should return 55 as the largest number in the array [55, 27, 34, 31, 4, 11, 8, 22, 16, 3].";
  })
}

TEST_F(ArrayMax, MultiElementArrayBiggestMiddle) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(array_max(number_array_mid, 10), 55)
      << "   The function should return 55 as the largest number in the array [3, 16, 22, 8, 11, 4, 55, 34, 27, 31].";
  })
}

TEST(UserInput, NoInput) {
  std::string user_input = "";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should not ask the user for input.";
}

TEST(Driver, MaxFound) {
  std::string user_input = "";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The largest number in the array is 16"))
    << "      Your program should tell the user that the largest number in the array is 16.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
