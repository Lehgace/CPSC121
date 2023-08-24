#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../rectangle.hpp"
using ::testing::HasSubstr;

TEST(Rectangle, PublicMethodsPresent) {
  Rectangle r;
  ASSERT_NO_THROW({
    r.length();
    r.width();
    r.set_length(5);
    r.set_width(5);
    r.area();
  });
}

TEST(Rectangle, MutatorsAndAccessors) {
  Rectangle your_rectangle;
  int length = 10, width = 5;
  ASSERT_NO_THROW({
    your_rectangle.set_length(length);
    your_rectangle.set_width(width);
  });
  ASSERT_EQ(your_rectangle.length(), 10);
  ASSERT_EQ(your_rectangle.width(), 5);
}

TEST(Rectangle, Area1) {
    Rectangle your_rectangle;
    your_rectangle.set_length(3);
    your_rectangle.set_width(6);
    ASSERT_EQ(your_rectangle.area(), 18);
}

TEST(Rectangle, Area2) {
    Rectangle your_rectangle;
    your_rectangle.set_length(17);
    your_rectangle.set_width(12);
    ASSERT_EQ(your_rectangle.area(), 204);
}

TEST(Rectangle, FirstArgumentBigger) {
  Rectangle bigger_rectangle, smaller_rectangle;
  bigger_rectangle.set_length(36);
  bigger_rectangle.set_width(5);
  smaller_rectangle.set_length(5);
  smaller_rectangle.set_width(4);
  ASSERT_TRUE(longest_rectangle(bigger_rectangle, smaller_rectangle).length() == bigger_rectangle.length());
}

TEST(Rectangle, SecondArgumentBigger) {
  Rectangle bigger_rectangle, smaller_rectangle;
  bigger_rectangle.set_length(28);
  bigger_rectangle.set_width(9);
  smaller_rectangle.set_length(3);
  smaller_rectangle.set_width(9);
  ASSERT_TRUE(longest_rectangle(smaller_rectangle, bigger_rectangle).length() == bigger_rectangle.length());
}

TEST(UserInput, AskRectangleInput) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the length and width values for two rectangles.";
}

TEST(Driver, ShowAreaFirstRectangle) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The area of Rectangle 1 is: 6"))
      << "      Your program should show the area of the first rectangle, 6.";
}

TEST(Driver, ShowAreaSecondRectangle) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The area of Rectangle 2 is: 20"))
      << "      Your program should show the area of the second rectangle, 20.";
}

TEST(Driver, ShowLongestRectangle) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The longest rectangle has a length of 4, a width of 5, and an area of 20."))
      << "      Your program should show the length, width, and area of the longest rectangle.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
