#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"
#include "../power.hpp"

using ::testing::HasSubstr;

TEST(power, PowerTest1) {
  ASSERT_EQ(power(2, 3), 8) << "      Your function should return 2 ^ 3, which is 8.";
}

TEST(power, PowerTest2) {
  ASSERT_EQ(power(3, 4), 81) << "      Your function should return 3 ^ 4, which is 81.";
}

TEST(power, BaseRaisedToZero) {
  ASSERT_EQ(power(5, 0), 1) << "      Your function should return 5 ^ 0, which is 1.";
}

TEST(power, ZeroRaisedToPower) {
  ASSERT_EQ(power(0, 10), 0) << "      Your function should return 0 ^ 10, which is 0.";
}

TEST(power, NegativeRaisedToPower) {
  ASSERT_EQ(power(-4, 3), -64) << "      Your function should return -4 ^ 3, which is -64.";
}

TEST(UserInput, AskBasePower) {
  std::string unittest_input = "2\n3\n";
  ASSERT_EXECEXIT("main", unittest_input, 3)
    << "      Your program should ask for the base and power.";
}

TEST(Driver, ShowPower) {
  std::string unittest_input = "3\n4\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("81"))
      << "      Your program should output the result of 3 ^ 4, which is 81.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
