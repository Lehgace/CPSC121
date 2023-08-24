#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(UserInput, AskMonthlySales) {
  std::string user_input = "300.25\n400.75\n350.21\n601.28\n702.45\n265.45\n365.89\n291.18\n500.37\n333.68\n450.92\n600.01";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for 12 values that represent the sale for each month.";
}

TEST(Output, TotalSales) {
  std::string user_input = "535.53\n500.52\n489.66\n536.20\n585.65\n624.30\n620.01\n431.56\n180.94\n744.78\n285.96\n239.84";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$5774.95"))
      << "      The total sale should be $5774.95.";
  })
}

TEST(Output, AverageMonthlySales) {
  std::string user_input = "224.82\n396.77\n225.59\n318.35\n452.21\n376.82\n776.98\n131.72\n367.89\n146.01\n654.25\n226.44";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$358.15"))
      << "      The average monthly sale should be $358.15.";
  })
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
