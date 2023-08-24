#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../add_array.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

class AddArray : public ::testing::Test {
protected:
  int first_unittest_array[5] = {1, 2, 4, 6, 8};
  int second_unittest_array[5] = {3, 5, 7, 8, 10};
};

TEST_F(AddArray, EmptyArrays) {
  ASSERT_DURATION_LE(3, {
    add_array(first_unittest_array, second_unittest_array, 0);  
  })  
  ASSERT_EQ(first_unittest_array[0], 1)
    << "   The first array should not change, [1, 2, 4, 6, 8]";
  ASSERT_EQ(first_unittest_array[1], 2)
    << "   The first array should not change, [1, 2, 4, 6, 8]";
  ASSERT_EQ(first_unittest_array[2], 4)
    << "   The first array should not change, [1, 2, 4, 6, 8]";
  ASSERT_EQ(first_unittest_array[3], 6)
    << "   The first array should not change, [1, 2, 4, 6, 8]";
  ASSERT_EQ(first_unittest_array[4], 8)
    << "   The first array should not change, [1, 2, 4, 6, 8]";  
}

TEST_F(AddArray, OneElement) {
  ASSERT_DURATION_LE(3, {
    add_array(first_unittest_array, second_unittest_array, 1);
  })
  ASSERT_EQ(first_unittest_array[0], 4)
    << "   The first element of the first array should now be 4, given the first array as [1] and the second as [3].";
}

TEST_F(AddArray, MultipleElements) {
  ASSERT_DURATION_LE(3, {
    add_array(first_unittest_array, second_unittest_array, 5);
  })
  ASSERT_EQ(first_unittest_array[0], 4)
    << "   The first element of the array should now be 4, given the first array as [1, 2, 4, 6, 8] and the second as [3, 5, 7, 8, 10]";
  ASSERT_EQ(first_unittest_array[1], 7)
    << "   The second element of the array should now be 7, given the first array as [1, 2, 4, 6, 8] and the second as [3, 5, 7, 8, 10]";
  ASSERT_EQ(first_unittest_array[2], 11)
    << "   The third element of the array should now be 11, given the first array as [1, 2, 4, 6, 8] and the second as [3, 5, 7, 8, 10]";
  ASSERT_EQ(first_unittest_array[3], 14)
    << "   The fourth element of the array should now be 14, given the first array as [1, 2, 4, 6, 8] and the second as [3, 5, 7, 8, 10]";
  ASSERT_EQ(first_unittest_array[4], 18)
    << "   The fifth element of the array should now be 18, given the first array as [1, 2, 4, 6, 8] and the second as [3, 5, 7, 8, 10]";
}

TEST(UserInput, AskInput) {
  std::string user_input = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for 10 numbers for the first array and another 10 numbers for thhe second array.";
}

TEST(Driver, AddGrade) {
  std::string user_input = "5\n8\n2\n7\n21\n67\n12\n0\n1\n6\n5\n2\n7\n2\n3\n12\n7\n15\n16\n100";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("10 10 9 9 24 79 19 15 17 106"))
    << "      Your program should show the updated values of the first array that contains the sum of each element added to the second array index-wise.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}