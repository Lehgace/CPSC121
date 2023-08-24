#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(UserInput, AskCardTypeAndSpending) {
  std::string user_input = "g\n100\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the type of card and the amount of money spent.";
}

TEST(CashBack, GreenCard) {
  std::string user_input = "g\n384.26\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$38.43"))
    << "      Your program should display $38.43, which is 10\% of the amount spent.";
}

TEST(CashBack, YellowCard) {
  std::string user_input = "y\n54.68\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$2.73"))
    << "      Your program should display $2.73, which is 5\% of the amount spent.";
}

TEST(CashBack, RedCard) {
  std::string user_input = "r\n202.44\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$4.05"))
    << "      Your program should display $4.05, which is 2\% of the amount spent.";
}

TEST(CashBack, InvalidCardType) {
  std::string user_input = "x\n123.45\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(i|I)(nvalid).*)"))
    << "      Your program should indicate that the card type is invalid.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
