#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../pair_class_template.hpp"

TEST(Pair, PublicMethodsPresent) {
  MyPair<int> your_pair(5, 3);
  your_pair.swap_value();
  your_pair.max_value();
  your_pair.min_value();
  SIMULATE_SIO("", {
    your_pair.display();
    your_pair.display_reverse();
  }, {})
}

TEST(Pair, Constructor) {
  MyPair<char> your_pair_char('a', 'c');
  MyPair<int> your_pair_int(2, 6);
  MyPair<std::string> your_pair_string("Hello", "Goodbye");
}

TEST(Pair, AccessorsChar) {
  MyPair<char> your_pair('a', 'c');
  ASSERT_EQ(your_pair.value1(), 'a') << "The accessor should return the value of value1, 'a'.";
  ASSERT_EQ(your_pair.value2(), 'c') << "The accessor should return the value of value2, 'c'.";
}

TEST(Pair, AccessorsInt) {
  MyPair<int> your_pair(2, 6);
  ASSERT_EQ(your_pair.value1(), 2) << "The accessor should return the value of value1, 2.";
  ASSERT_EQ(your_pair.value2(), 6) << "The accessor should return the value of value2, 6.";
}

TEST(Pair, AccessorsString) {
  MyPair<std::string> your_pair("Hello", "Goodbye");
  ASSERT_EQ(your_pair.value1(), "Hello") << "The accessor should return the value of value1, Hello.";
  ASSERT_EQ(your_pair.value2(), "Goodbye") << "The accessor should return the value of value2, Goodbye.";
}

TEST(Pair, Display) {
  MyPair<double> your_pair(5.5, 4.4);
  SIMULATE_SIO("", {
    your_pair.display();
  }, {
    ASSERT_EQ(your_output, "[5.5, 4.4]");
  })
}

TEST(Pair, DisplayReverse) {
  MyPair<std::string> your_pair("Hello", "Goodbye");
  SIMULATE_SIO("", {
    your_pair.display_reverse();
  }, {
    ASSERT_EQ(your_output, "[Goodbye, Hello]");
  })
}

TEST(Pair, MaxValueInt1) {
  MyPair<int> your_pair(1, 9);
  ASSERT_EQ(your_pair.max_value(), 9) << "The function should return 9 given the pair [1, 9]";
}

TEST(Pair, MaxValueInt2) {
  MyPair<int> your_pair(9, 1);
  ASSERT_EQ(your_pair.max_value(), 9) << "The function should return 9 given the pair [9, 1]";
}

TEST(Pair, MaxValueString1) {
  MyPair<std::string> your_pair("Sea", "Sew");
  ASSERT_EQ(your_pair.max_value(), "Sew") << "The function should return Sew given the pair [Sea, Sew]";
}

TEST(Pair, MaxValueString2) {
  MyPair<std::string> your_pair("Sew", "Sea");
  ASSERT_EQ(your_pair.max_value(), "Sew") << "The function should return Sew given the pair [Sew, Sea]";
}

TEST(Pair, SwapInts) {
  MyPair<int> your_pair(26, 53);
  your_pair.swap_value();
  ASSERT_EQ(your_pair.value1(), 53) << "The function should return 53 given the pair [26, 53] after swapping";
  ASSERT_EQ(your_pair.value2(), 26) << "The function should return 26 given the pair [26, 53] after swapping";
}

TEST(Driver, Output) {
  std::string unittest_output =
  "[3, 5]\n"
  "[5, 3]\n"
  "5\n"
  "3\n"
  "[5, 3]\n"
  "[3, 5]\n"
  "[9.7, 6.4]\n"
  "[6.4, 9.7]\n"
  "9.7\n"
  "6.4\n"
  "[6.4, 9.7]\n"
  "[9.7, 6.4]\n"
  "[a, z]\n"
  "[z, a]\n"
  "z\n"
  "a\n"
  "[z, a]\n"
  "[a, z]\n";

  ASSERT_EXECEQ("main", "", unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
