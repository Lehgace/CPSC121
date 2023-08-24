#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"
#include "../find_number.hpp"

using ::testing::HasSubstr;

TEST(Numbers, PublicMethodPresent) {
  Numbers your_numbers;
  SIMULATE_SIO("", {
    your_numbers.capacity();
    your_numbers.display_array();
    your_numbers.find_number(1);
  }, {})
}

TEST(Numbers, DefaultConstructor) {
  Numbers your_numbers;
  ASSERT_EQ(your_numbers.capacity(), 10) << "The capacity set by the default constructor should be 10.";
}

TEST(Numbers, NonDefaultConstructor) {
  Numbers your_numbers(5);
  ASSERT_EQ(your_numbers.capacity(), 5) << "The capacity set by the nondefault constructor should be 5.";  
}

TEST(Numbers, DisplayArrayDefaultConstructor) {
  Numbers your_numbers;
  SIMULATE_SIO("", {
    your_numbers.display_array();
  }, {
    ASSERT_THAT(your_output, HasSubstr("2 4 6 8 10 12 14 16 18 20"))
      << "The constructor should have called the init function to set the initial values of the 10 array elements.";
  })
}

TEST(Numbers, DisplayArrayNonDefaultConstructor) {
  Numbers your_numbers(12);
  SIMULATE_SIO("", {
    your_numbers.display_array();
  }, {
    ASSERT_THAT(your_output, HasSubstr("2 4 6 8 10 12 14 16 18 20 22 24"))
      << "The constructor should have called the init function to set the initial values of the 12 array elements.";
  })
}

TEST(Numbers, FindNumberPresent1) {
  Numbers your_numbers;
  SIMULATE_SIO("", {
    your_numbers.find_number(2);
  }, {
    ASSERT_THAT(your_output, HasSubstr("2 is in the array"));
  })

}

TEST(Numbers, FindNumberPresent2) {
  Numbers your_numbers(12);
  SIMULATE_SIO("", {
    your_numbers.find_number(24);
  }, {
    ASSERT_THAT(your_output, HasSubstr("24 is in the array"));
  })
}

TEST(Numbers, FindNumberNotPresent1) {
  Numbers your_numbers;
  SIMULATE_SIO("", {
    your_numbers.find_number(3);
  }, {
    ASSERT_THAT(your_output, Not(HasSubstr("3 is in the array")));
  })
}

TEST(Numbers, FindNumberNotPresent2) {
  Numbers your_numbers;
  SIMULATE_SIO("", {
    your_numbers.find_number(9);
  }, {
    ASSERT_THAT(your_output, Not(HasSubstr("9 is in the array")));
  })
}

TEST(Numbers, FindNumberNotPresentExceed) {
  Numbers your_numbers;
  SIMULATE_SIO("", {
    your_numbers.find_number(48);
  }, {
    ASSERT_THAT(your_output, Not(HasSubstr("48 is in the array")));
  })
}

TEST(Driver, Output) {
  std::string unittest_output = "2 4 6 8 10 12 14 16 18 20 \n"
                                "2 is in the array\n"
                                "10 is in the array\n"
                                "16 is in the array\n";
  ASSERT_DURATION_LE(3, { 
    ASSERT_EXECEQ("main", "", unittest_output); 
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
