#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../gcd.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(GCD, SameNumbers1) {
  ASSERT_DURATION_LE(3, { 
    ASSERT_EQ(gcd(4, 4), 4)
    << "      The GCD of 4 and 4 should be 4."; 
  });
}

TEST(GCD, SameNumbers2) {
  ASSERT_DURATION_LE(3, { 
    ASSERT_EQ(gcd(8, 8), 8)
    << "      The GCD of 8 and 8 should be 8."; 
  });
}

TEST(GCD, FirstNumDivisiblebySecondNum) {
  ASSERT_DURATION_LE(3, { 
    ASSERT_EQ(gcd(6, 3), 3)
    << "      The GCD of 6 and 3 should be 3."; 
  });  
}

TEST(GCD, SecondNumDivisiblebyFirstNum) {
  ASSERT_DURATION_LE(3, { 
    ASSERT_EQ(gcd(7, 14), 7)
    << "      The GCD of 7 and 14 should be 7."; 
  });  
}

TEST(GCD, NumbersDontDivideEachOtherButShareDivisor) {
  ASSERT_DURATION_LE(3, { 
    ASSERT_EQ(gcd(46, 161), 23)
    << "      The GCD of 46 and 161 should be 23."; 
  });  
}

TEST(GCD, NoCommonDenominatorButOne) {
  ASSERT_DURATION_LE(3, { 
    ASSERT_EQ(gcd(9, 7), 1)
    << "      The GCD of 9 and 7 should be 1."; 
  });  
}

TEST(UserInput, AskNumbers) {
  std::string user_input = "24\n18\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for two numbers.";
}

TEST(Driver, ComputeGCD) {
  std::string user_input = "24\n18\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The GCD of the numbers 24 and 18 is 6"))
    << "      Your program should thhe GCD of 24 and 18, which is 6.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
