#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../count-odd.hpp"

using ::testing::MatchesRegex;
using ::testing::HasSubstr;

TEST(count_odd, Zero) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(count_odd(0), 0) 
      << "      Zero is not an odd number.";
  })
}

TEST(count_odd, Test1) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(count_odd(3), 2) 
      << "      There are two odd numbers from 0 to 3: 1 and 3.";
  })
}

TEST(count_odd, Test2) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(count_odd(13), 7) 
      << "      There are seven odd numbers from 0 to 13: 1, 3, 5, 7, 9, 11, and 13.";
  })
}

TEST(count_odd, Test3) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(count_odd(25), 13) 
      << "      There are 13 odd numbers from 0 to 13: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, and 25.";
  })
}

TEST(UserInput, AskNumber) {
  std::string user_input = "10\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for a number.";
}

TEST(Driver, CountOddsNegative) {
  std::string user_input = "-5\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(error|Error|invalid|Invalid).*)"))
    << "      Your program should show an error message when the user provides a negative value.";
}

TEST(Driver, CountOdds) {
  std::string user_input = "9\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The number of odds from 0 to 9 is 5"))
    << "      The program should tell the user that there are 5 odd numbers from 0 to 9.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
