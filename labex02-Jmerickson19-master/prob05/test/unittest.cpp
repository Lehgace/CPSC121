#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::MatchesRegex;
using ::testing::HasSubstr;

TEST(UserInput, AskAgeOneAndTwo) {
  std::string user_input = "15\n25\n";
  ASSERT_EXECEXIT("main", user_input, 3) << "      Your program should ask for two age values.";
}

TEST(UserInput, ShowPriceInfo) {
  std::string user_input = "15\n25\n";
  ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(Children).*(\$10\.00).*(Young Adults).*(\$13\.00).*(Adults).*(\$15\.00).*(Seniors).*(\$10\.00).*)"))
    << "      Your program should display the pricing structure for each age range. Specifically, Children tickets cost $10.00, Young Adults tickets cost $13.00, and so forth.";

}

TEST(SubTotal, ChildChild) {
  std::string user_input = "10\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$20.00"))
    << "      Your program should display $20.00, the price of two tickets for children.";  
}

TEST(SubTotal, ChildChildEdge) {
  std::string user_input = "12\n12\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$20.00"))
    << "      Your program should display $20.00. Anyone whose age is 12 is still considered a child.";  
}

TEST(SubTotal, YoungAdultYoungAdult) {
  std::string user_input = "16\n18\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$26.00"))
    << "      Your program should display $26.00, the price of two tickets for young adults.";  
}

TEST(SubTotal, YoungAdultYoungAdultEdge1) {
  std::string user_input = "13\n20\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$26.00"))
    << "      Your program should display $26.00. Anyone whose age is 13 or 20 is still considered a young adult.";  
}

TEST(SubTotal, YoungAdultYoungAdultEdge2) {
  std::string user_input = "20\n13\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$26.00"))
    << "      Your program should display $26.00. Anyone whose age is 13 or 20 is still considered a young adult.";  
}

TEST(SubTotal, AdultAdult) {
  std::string user_input = "40\n52\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$30.00"))
    << "      Your program should display $30.00, the price of two tickets for adults.";  
}

TEST(SubTotal, AdultAdultEdge1) {
  std::string user_input = "21\n64\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$30.00"))
    << "      Your program should display $30.00. Anyone whose age is 21 or 64 is still considered an adult.";  
}

TEST(SubTotal, AdultAdultEdge2) {
  std::string user_input = "64\n21\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$30.00"))
    << "      Your program should display $30.00. Anyone whose age is 21 or 64 is still considered an adult.";  
}

TEST(SubTotal, SeniorSenior) {
  std::string user_input = "70\n85\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$20.00"))
    << "      Your program should display $20.00, the price of two tickets for seniors.";  
}

TEST(SubTotal, SeniorSeniorEdge1) {
  std::string user_input = "65\n100\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$20.00"))
    << "      Your program should display $20.00. Anyone whose age is 65 already considered a senior.";  
}

TEST(SubTotal, SeniorSeniorEdge2) {
  std::string user_input = "100\n65\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$20.00"))
    << "      Your program should display $20.00. Anyone whose age is 65 already considered a senior.";
}

TEST(SubTotal, ChildYoungAdult) {
  std::string user_input = "12\n20\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$23.00"))
    << "      Your program should display $23.00, the price of tickets for a child and a young adult.";  
}

TEST(SubTotal, ChildAdult) {
  std::string user_input = "12\n23\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$25.00"))
    << "      Your program should display $25.00, the price of tickets for a child and an adult.";  
}

TEST(SubTotal, ChildSenior) {
  std::string user_input = "12\n67\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$20.00"))
    << "      Your program should display $20.00, the price of tickets for a child and a senior.";  
}

TEST(SubTotal, YoungAdultAdult) {
  std::string user_input = "16\n23\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$28.00"))
    << "      Your program should display $28.00, the price of tickets for a young adult and an adult.";
}

TEST(SubTotal, YoungAdultSenior) {
  std::string user_input = "16\n68\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$23.00"))
    << "      Your program should display $23.00, the price of tickets for a young adult and a senior.";
}

TEST(SubTotal, AdultSenior) {
  std::string user_input = "25\n70\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("$25.00"))
    << "      Your program should display $25.00, the price of tickets for an adult and a senior.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
