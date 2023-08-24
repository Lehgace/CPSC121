#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../evens_array.hpp"

TEST(FindEvens, AllEven) {
  int even_array[] = {2, 4, 6, 8, 10, 12};
  bool your_boolean_array[6];
  ASSERT_DURATION_LE(3, {
    find_evens(even_array, your_boolean_array, 6);
  })
  ASSERT_TRUE(your_boolean_array[0])
    << "      Element 0 is even given the array {2, 4, 6, 8, 10, 12}";
  ASSERT_TRUE(your_boolean_array[1])
    << "      Element 1 is even given the array {2, 4, 6, 8, 10, 12}";
  ASSERT_TRUE(your_boolean_array[2])
    << "      Element 2 is even given the array {2, 4, 6, 8, 10, 12}";
  ASSERT_TRUE(your_boolean_array[3])
    << "      Element 3 is even given the array {2, 4, 6, 8, 10, 12}";
  ASSERT_TRUE(your_boolean_array[4])
    << "      Element 4 is even given the array {2, 4, 6, 8, 10, 12}";
  ASSERT_TRUE(your_boolean_array[5])
    << "      Element 5 is even given the array {2, 4, 6, 8, 10, 12}";
}

TEST(FindEvens, AllOdd) {
  int odd_array[] = {3, 5, 7, 9};
  bool your_boolean_array[4];
  ASSERT_DURATION_LE(3, {
    find_evens(odd_array, your_boolean_array, 4);
  })
  ASSERT_FALSE(your_boolean_array[0])
    << "      Element 0 is odd given the array {3, 5, 7, 9}";
  ASSERT_FALSE(your_boolean_array[1])
    << "      Element 1 is odd given the array {3, 5, 7, 9}";
  ASSERT_FALSE(your_boolean_array[2])
    << "      Element 2 is odd given the array {3, 5, 7, 9}";
  ASSERT_FALSE(your_boolean_array[3])
    << "      Element 3 is odd given the array {3, 5, 7, 9}";
}

TEST(FindEvens, MixedEvenOdd) {
  int mixed_array[] = {2, 3, 9, 11, 10};
  bool your_boolean_array[5];
  ASSERT_DURATION_LE(3, {
    find_evens(mixed_array, your_boolean_array, 5);
  })
  ASSERT_TRUE(your_boolean_array[0])
    << "      Element 0 is even given the array {2, 3, 9, 11, 10}";
  ASSERT_FALSE(your_boolean_array[1])
    << "      Element 1 is odd given the array {2, 3, 9, 11, 10}";
  ASSERT_FALSE(your_boolean_array[2])
    << "      Element 2 is odd given the array {2, 3, 9, 11, 10}";
  ASSERT_FALSE(your_boolean_array[3])
    << "      Element 3 is odd given the array {2, 3, 9, 11, 10}";
  ASSERT_TRUE(your_boolean_array[4])
    << "      Element 4 is even given the array {2, 3, 9, 11, 10}";
}

TEST(Driver, FindEvens) {
  ASSERT_EXECEQ("main", "", "01011\n");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
