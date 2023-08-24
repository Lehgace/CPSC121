#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../get_longest_string.hpp"
#include "gtest_ext.h"

using testing::HasSubstr;

class GetLongestString : public ::testing::Test {
protected:
  void SetUp() override {
    string1 = "California";
    string2 = "State";
    string3 = "University";
    string4 = "Fullerton";
    string5 = "Tuffy";
  }

  std::string string1, string2, string3, string4, string5;
};

TEST_F(GetLongestString, OneString) {
  std::string strings[] = {string1};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(get_longest_string(strings, 1), "California") 
      << "      The function should return the only string in the array.";
  })
}

TEST_F(GetLongestString, LongestStringFirst) {
  std::string strings[] = {string3, string5, string2};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(get_longest_string(strings, 3), "University") 
      << "      The function should return the longest string, University, out of three strings: University, Tuffy, State.";
  })
}

TEST_F(GetLongestString, LongestStringSecond) {
  std::string strings[] = {string5, string3, string2};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(get_longest_string(strings, 3), "University") 
      << "      The function should return the longest string, University, out of three strings: Tuffy, University, State.";
  })
}

TEST_F(GetLongestString, LongestStringLast) {
  std::string strings[] = {string5, string2, string3};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(get_longest_string(strings, 3), "University") 
      << "      The function should return the longest string, University, out of three string Tuffy, State, University.";
  })
}

TEST_F(GetLongestString, LongestStringTie) {
  std::string strings[] = {string1, string2, string3, string4, string5};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(get_longest_string(strings, 5), "California") 
      << "      The function should return the longest string, California, out of five striings: California State University Fullerton Tuffy. California is returned despite the tie with University because it comes first.";
  })
}

TEST(UserInput, AskFiveStrings) {
  std::string user_input = "California\nState\nUniversity\nFullerton\nTuffy\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for five strings.";
}

TEST(Driver, ShowLowestPrice) {
  std::string user_input = "California\nState\nUniversity\nFullerton\nTuffy\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The longest string is: California"))
    << "      Your program should California as the longest string.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
