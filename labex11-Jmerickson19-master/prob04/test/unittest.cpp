#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../shapes.hpp"
#include "gtest_ext.h"

TEST(Shape, DefaultConstructor) {
  Shape your_shape;
  ASSERT_EQ(your_shape.width(), 1)
      << "The default width of the shape should be 1.";
  ASSERT_EQ(your_shape.height(), 1)
      << "The default height of the shape should be 1.";
}

TEST(Shape, NonDefaultConstructor) {
  Shape your_shape(10, 15);
  ASSERT_EQ(your_shape.width(), 10)
      << "The default width of the shape should be 10.";
  ASSERT_EQ(your_shape.height(), 15)
      << "The default height of the shape should be 15.";
}

TEST(Shape, AccessorAndMutator) {
  Shape your_shape;
  your_shape.set_width(6);
  your_shape.set_height(8);
  ASSERT_EQ(your_shape.width(), 6) << "The width of the shape should be 6.";
  ASSERT_EQ(your_shape.height(), 8) << "The height of the shape should be 8.";
}

TEST(Rectangle, DefaultConstructor) {
  Rectangle your_rectangle;
  ASSERT_EQ(your_rectangle.width(), 1)
      << "The default width of the rectangle should be 1.";
  ASSERT_EQ(your_rectangle.height(), 1)
      << "The default height of the rectangle should be 1.";
}

TEST(Rectangle, NonDefaultConstructor) {
  Rectangle your_rectangle(10, 15);
  ASSERT_EQ(your_rectangle.width(), 10)
      << "The default width of the rectangle should be 10.";
  ASSERT_EQ(your_rectangle.height(), 15)
      << "The default height of the rectangle should be 15.";
}

TEST(Rectangle, AccessorAndMutator) {
  Rectangle your_rectangle;
  your_rectangle.set_width(6);
  your_rectangle.set_height(7);
  ASSERT_EQ(your_rectangle.width(), 6)
      << "The width of the rectangle should be 6.";
  ASSERT_EQ(your_rectangle.height(), 7)
      << "The height of the rectangle should be 7.";
}

TEST(Rectanglle, Area) {
  Rectangle your_rectangle(10, 5);
  ASSERT_EQ(your_rectangle.calc_area(), 50)
      << "The area of a rectangle with witdth 10 and height 5 should be 50.";
}

TEST(Triangle, DefaultConstructor) {
  Triangle your_triangle;
  ASSERT_EQ(your_triangle.width(), 1)
      << "The default width of the triangle should be 1.";
  ASSERT_EQ(your_triangle.height(), 1)
      << "The default height of the triangle should be 1.";
}

TEST(Triangle, NonDefaultConstructor) {
  Triangle your_triangle(10, 15);
  ASSERT_EQ(your_triangle.width(), 10)
      << "The default width of the triangle should be 10.";
  ASSERT_EQ(your_triangle.height(), 15)
      << "The default height of the triangle should be 15.";
}

TEST(Triangle, AccessorAndMutator) {
  Triangle your_triangle;
  your_triangle.set_width(6);
  your_triangle.set_height(7);
  ASSERT_EQ(your_triangle.width(), 6)
      << "The width of the triangle should be 6.";
  ASSERT_EQ(your_triangle.height(), 7)
      << "The height of the triangle should be 7.";
}

TEST(Triangle, Area) {
  Triangle your_triangle(10, 5);
  ASSERT_EQ(your_triangle.calc_area(), 25)
      << "The area of a triangle with width 10 and height 5 should be 25.";
}

TEST(Driver, Input) {
  std::string unittest_input = "4\n5\n7\n8\n6\n8\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output) {
  std::string unittest_input = "4\n5\n7\n8\n6\n8\n";
  std::string unittest_output = "Please enter the width for shape: "
                                "Please enter the height for shape: "
                                "Please enter the width for rectangle: "
                                "Please enter the height for rectangle: "
                                "Please enter the width for triangle: "
                                "Please enter the height for triangle: "
                                "Printing shape:\n"
                                "Width: 4  Height: 5\n"
                                "Printing rectangle:\n"
                                "Width: 7  Height: 8  Area: 56\n"
                                "Printing triangle:\n"
                                "Width: 6  Height: 8  Area: 24\n";

  ASSERT_EXECEQ("main", unittest_input, unittest_output);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
