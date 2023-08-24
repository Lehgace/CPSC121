#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(UserInput, AskBaseAndPower) {
  std::string user_input = "2\n3\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the base and the power.";
}

TEST(Power, NonZeroPower)
{
  std::string user_input = "2\n3\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 8.*))"))
      << "      2 raised to 3 should be 8.";
  })
}

TEST(Power, PowerIsOne)
{
  std::string user_input = "57\n1\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 57.*))"))
      << "      A number raised to 1 is itself. In this case, 57.";
  })
}

TEST(Power, PowerIsZero)
{
  std::string user_input = "2961\n0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 1.*))"))
      << "      A number raised to 0 is is always 1.";
  })
}

TEST(Power, NegativeBaseEvenPower)
{
  std::string user_input = "-3\n4\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 81.*))"))
      << "      A negative base raised to an even number is positive. In this case, 81.";
  })
}

TEST(Power, NegativeBaseOddPower)
{
  std::string user_input = "-3\n3\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* -27.*))"))
      << "      A negative base raised to an odd number is negative. In this case, -27.";
  })
}

TEST(Power, ZeroBase)
{
  std::string user_input = "0\n5283\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 0.*))"))
      << "      Zero raised to any number is always zero.";
  })
}

TEST(RepeatedAddition, NegativePower)
{
  std::string user_input = "7\n-8\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((are not)|aren't|(can not)|cannot|can't|unsupported).*)"))
      << "      The program should indicate that negative powers are currently unsupported.";
  })
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
