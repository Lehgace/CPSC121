#include "../counter_functions.hpp"
#include "gtest_ext.h"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>
using ::testing::ContainsRegex;
using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(CharacterCounter, OutputFormat) {
  std::ostringstream unittest_output;
  // Programming
  unittest_output << "Please input a single word: ";
  unittest_output << "The number of vowels in this string is: 3\n";
  unittest_output << "The number of consonants in this string is: 8\n";
  ASSERT_EXECIO_EQ("main", "Programming\n", unittest_output.str());
}

bool is_vowel(char c) {
  switch (c) {
  case 'a':
  case 'A':
  case 'e':
  case 'E':
  case 'i':
  case 'I':
  case 'o':
  case 'O':
  case 'u':
  case 'U':
    return true;
  default:
    return false;
  }
  return false;
}

TEST(CharacterCounter, VowelCounterTest) {
  for (int i = 0; i < 10; i++) {
    int unittest_output = 0;
    int length = rand() % 100;
    std::string unittest_random_string = generate_string(length);
    for (int j = 0; j < unittest_random_string.size(); j++) {
      if (is_vowel(unittest_random_string[j])) {
        unittest_output++;
      }
    }
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(count_vowels(unittest_random_string), unittest_output);
    });
  }
}
TEST(CharacterCounter, ConsonantCounterTest) {
  for (int i = 0; i < 10; i++) {
    int unittest_output = 0;
    int length = rand() % 100;
    std::string unittest_random_string = generate_string(length);
    for (int j = 0; j < unittest_random_string.size(); j++) {
      if (!(is_vowel(unittest_random_string[j]))) {
        unittest_output++;
      }
    }
    ASSERT_DURATION_LE(3, {
      ASSERT_EQ(count_consonants(unittest_random_string), unittest_output);
    });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
