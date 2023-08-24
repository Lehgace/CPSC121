#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../print_array_reverse.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

class PrintArrayReverse : public ::testing::Test {
protected:
  int unittest_array[5] = {4, 1, 6, 2, 3};
};


TEST_F(PrintArrayReverse, EmptyArray) {
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", print_array_reverse(unittest_array, 0), {
      ASSERT_THAT(your_output, HasSubstr("no contents"))
        << "Hint: The member function should tell the user that the array does not have any contents.";  
    })  
  })
}

TEST_F(PrintArrayReverse, OneElement) {
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", print_array_reverse(unittest_array, 1), {
      ASSERT_THAT(your_output, HasSubstr("4"))
        << "Hint: The member function should display 4 as the reverse of the array.";  
    })  
  })
}

TEST_F(PrintArrayReverse, MultipleElements) {
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", print_array_reverse(unittest_array, 5), {
      ASSERT_THAT(your_output, HasSubstr("3 2 6 1 4"))
        << "Hint: The member function should display 3 2 6 1 4 as the reversed array.";  
    })  
  })
}

TEST(UserInput, AskInput) {
  std::string user_input = "3\n3.8\n2.5\n4.0\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number of elements, in this case 3, and then the 3 values.";
}

TEST(Driver, NoContents) {
  std::string user_input = "0\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("no contents"))
    << "      Your program should show an error message when the user sets the number of elements to 0.";
}

TEST(Driver, PrintArrayReverse) {
  std::string user_input = "5\n3\n2\n4\n1\n8\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("8 1 4 2 3"))
    << "      Your program should display the array in reverse, namely 8 1 4 2 3 5.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
