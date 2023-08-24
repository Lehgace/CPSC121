#include "../most_sig_digit.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::MatchesRegex;

TEST(UserInput, AskNumber) {
  std::string unittest_input = "4512\n";
  ASSERT_EXECEXIT("main", unittest_input, 3)
    << "      Your program should ask for a number.";
}

TEST(most_significant_digit, NumberTest1) {
  ASSERT_EQ(most_significant_digit(4582), 4) << "      Your function should return 4 as the most significant digit.";
}

TEST(most_significant_digit, NumberTest2) {
  ASSERT_EQ(most_significant_digit(8382), 8) << "      Your function should return 8 as the most significant digit.";
}

TEST(most_significant_digit, PositiveNumber) {
  ASSERT_EQ(most_significant_digit(7821), 7) << "      Your function should return 7 as the most significant digit.";
}

TEST(most_significant_digit, NegativeNumber) {
  ASSERT_EQ(most_significant_digit(-562), -5) << "      Your function should return -5 as the most significant digit.";
}

TEST(most_significant_digit, Zero) {
  ASSERT_EQ(most_significant_digit(0), 0) << "      Your function should return 0 as the most significant digit.";
}

TEST(most_significant_digit, OneDigit) {
  ASSERT_EQ(most_significant_digit(9), 9) << "      Your function should return 9 as the most significant digit.";
}

TEST(most_significant_digit, TwoDigits) {
  ASSERT_EQ(most_significant_digit(71), 7) << "      Your function should return 7 as the most significant digit.";
}

TEST(most_significant_digit, ThreeDigits) {
  ASSERT_EQ(most_significant_digit(865), 8) << "      Your function should return 8 as the most significant digit.";
}

TEST(most_significant_digit, FourDigits) {
  ASSERT_EQ(most_significant_digit(2872), 2) << "      Your function should return 2 as the most significant digit.";
}

TEST(most_significant_digit, FiveDigits) {
  ASSERT_EQ(most_significant_digit(59182), 5) << "      Your function should return 5 as the most significant digit.";
}

TEST(Driver, ShowMostSignificantDigit) {
  std::string unittest_input = "7231\n";
  ASSERT_EXECTHAT("main", unittest_input, MatchesRegex(R"(((.* 7 .*)|(.* 7$)|(.* 7.)))"))
      << "      Your program should output 7 as the most significant digit.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
