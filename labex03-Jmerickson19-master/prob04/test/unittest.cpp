#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(UserInput, AskGameInfo) {
  std::string user_input = "3\n70\n30\n24\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number of games and the price for each one.";
}

TEST(UserInput, InvalidNumberOfGamesZero) {
  std::string user_input = "0";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((at least 1 game)|rerun|invalid|error).*)"))
      << "      The system should display an error when the customer provides an invalid number of games.";
  })
}

TEST(UserInput, InvalidNumberOfGamesNegative) {
  std::string user_input = "-10";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((at least 1 game)|rerun|invalid|error).*)"))
      << "      The system should display an error when the customer provides an invalid number of games.";
  })
}

TEST(Cost, NoDiscount) {
  std::string user_input = "5\n15\n20\n10\n59.99\n23.48\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$128.47"))
      << "      The total sale should be $128.47 given there was no discount.";
  })
}

TEST(Cost, Discounted) {
  std::string user_input = "5\n75\n23.48\n39.59\n18.00\n59.99\n";

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$172.85"))
      << "      The total sale should be $172.85 given the 20\% discount.";
  })
}

TEST(Saved, NoDiscount) {
  std::string user_input = "5\n15\n20\n10\n59.99\n23.48\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$0.00"))
      << "      The customer shouldn't receive a discount because no game is $60.00 or more.";
  })
}

TEST(Saved, Discount) {
  std::string user_input = "5\n75\n23.48\n39.59\n18.00\n59.99\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$43.21"))
      << "      The customer should receive a 20\% discount, $43.21, because one game is over $60.00.";
  })
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
