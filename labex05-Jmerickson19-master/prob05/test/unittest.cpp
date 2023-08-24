#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "gtest_ext.h"
#include "../rectangle.hpp"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(UserInput, AskLengthWidth) {
  std::string unittest_input = "2\n3\n";
  ASSERT_EXECEXIT("main", unittest_input, 3)
    << "      Your program should ask for the length and width of the rectangle.";
}

TEST(draw_rectangle, DrawRectangleTest1) {
  std::string unittest_input = "2\n3\n";
  std::string unittest_output = "***\n"
                                "***\n";
  SIMULATE_SIO("", draw_rectangle(2, 3), {
    ASSERT_EQ(your_output, unittest_output) << "      Your function should display a 2x3 rectangle.";
  })
}

TEST(draw_rectangle, DrawRectangleTest2) {
  std::string unittest_input = "3\n8\n";
  std::string unittest_output = "********\n"
                                "********\n"
                                "********\n";
  SIMULATE_SIO("", draw_rectangle(3, 8), {
    ASSERT_EQ(your_output, unittest_output) << "      Your function should display a 3x8 rectangle.";
  })
}

TEST(draw_rectangle, ZeroLength) {
  std::string unittest_input = "0\n8\n";
  std::string unittest_output = "";
  SIMULATE_SIO("", draw_rectangle(0, 8), {
    ASSERT_THAT(your_output, MatchesRegex(R"(.*(error|Error|invalid|Invalid).*)")) << "      Your function should display an error because the length is 0.";
  })
}

TEST(draw_rectangle, ZeroWidth) {
  std::string unittest_input = "3\n0\n";
  std::string unittest_output = "";
  SIMULATE_SIO("", draw_rectangle(3, 0), {
    ASSERT_THAT(your_output, MatchesRegex(R"(.*(error|Error|invalid|Invalid).*)")) << "      Your function should display an error because the width is 0.";
  })
}

TEST(draw_rectangle, NegativeLength) {
  std::string unittest_input = "-3\n8\n";
  std::string unittest_output = "";
  SIMULATE_SIO("", draw_rectangle(-3, 8), {
    ASSERT_THAT(your_output, MatchesRegex(R"(.*(error|Error|invalid|Invalid).*)")) << "      Your function should display an error because the length is negative.";
  })
}

TEST(draw_rectangle, NegativeWidth) {
  std::string unittest_input = "3\n-8\n";
  std::string unittest_output = "\n";
  SIMULATE_SIO("", draw_rectangle(3, -8), {
    ASSERT_THAT(your_output, MatchesRegex(R"(.*(error|Error|invalid|Invalid).*)")) << "      Your function should display an error because the width is negative.";
  })
}

TEST(Driver, ShowRectangle) {
  std::string unittest_input = "4\n5\n";
  std::string unittest_output = "*****\n"
                                "*****\n"
                                "*****\n"
                                "*****\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr(unittest_output))
      << "      Your program should display a 4 x 5 rectangle.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
