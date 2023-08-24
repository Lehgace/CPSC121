#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(UserInput, AskNumberAndRepetitions) {
  std::string user_input = "5\n10\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for a number and how many times it will be added.";
}

TEST(RepeatedAddition, ZeroReps)
{
  std::string user_input = "5\n0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 0.*))"))
      << "      Repeatedly adding the number zero times is 0.";
  })
}

TEST(RepeatedAddition, OneRep)
{
  std::string user_input = "32\n1\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 32.*))"))
      << "      Repeatedly adding the number once is the number.";
  })
}

TEST(RepeatedAddition, FiveReps)
{
  std::string user_input = "27\n5\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 135.*))"))
      << "      The total should be 134.";
  })
}

TEST(RepeatedAddition, NegativeNumber)
{
  std::string user_input = "-12\n3\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* -36.*))"))
      << "      The total should be -36.";
  })
}

TEST(RepeatedAddition, NegativeReps)
{
  std::string user_input = "7\n-8\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((can not)|cannot|can't|rerun|invalid|error).*)"))
      << "      The program should not accept a negative number for repetitions.";
  })
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
