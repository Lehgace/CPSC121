#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../lsa.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

class LSA : public ::testing::Test {
protected:
  int number_array[10] = {3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
};

TEST_F(LSA, EmptyArray) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 5, 0), -1)
      << "   The function should return -1 if the size of the array is invalid.";
  })
}

TEST_F(LSA, OneElementArrayPresent) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 3, 1), 0)
      << "   The function should return 0 as the index of 3 given the array [3].";
  })
}

TEST_F(LSA, OneElementArrayNotPresent) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 10, 1), -1)
      << "   The function should return -1 because 10 is not in the array given the array [3].";
  })
}

TEST_F(LSA, MultiElementArrayPresent) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 8, 10), 3)
      << "   The function should return 3 as the index of 8 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST_F(LSA, MultiElementArrayFirstElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 3, 10), 0)
      << "   The function should return 0 as the index of 3 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST_F(LSA, MultiElementArraySecondElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 16, 10), 1)
      << "   The function should return 1 as the index of 16 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST_F(LSA, MultiElementArrayMiddleElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 11, 10), 4)
      << "   The function should return 4 as the index of 11 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST_F(LSA, MultiElementArrayLastElement) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 31, 10), 9)
      << "   The function should return 9 as the index of 31 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST_F(LSA, MultiElementArrayNotPresent) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(linear_search(number_array, 6, 10), -1)
      << "   The function should return -1 because 6 is not in the array given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST(UserInput, AskSearchNumber) {
  std::string user_input = "5\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number to search.";
}

TEST(Driver, NumberFound) {
  std::string user_input = "11\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The index of 11 in the array is: 4"))
    << "      Your program should tell the user that the 11 is in index 4.";
}

TEST(Driver, NumberNotFound) {
  std::string user_input = "6\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("is not in the array"))
    << "      Your program should tell the user that the number they are looking for is not in the array.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
