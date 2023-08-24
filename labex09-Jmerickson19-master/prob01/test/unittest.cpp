#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../cup.hpp"

using ::testing::HasSubstr;

TEST(Cup, DefaultConstructor) {
  Cup your_cup;
  ASSERT_EQ(your_cup.drink_type(),"Water") << "   The default value of drink_type_ should be Water";
  ASSERT_DOUBLE_EQ(your_cup.fluid_oz(), 16.0)<< "   The default value of fluid_oz_ should be 16.0";
}
TEST(Cup, NonDefaultConstructor) {
  Cup your_cup("Aquafina", 32);
  ASSERT_EQ(your_cup.drink_type(),"Aquafina")<< "   The value of drink_type_ should be Aquafina";
  ASSERT_DOUBLE_EQ(your_cup.fluid_oz(), 32.0)<< "   The value of fluid_oz_ should be 32.0";
}
TEST(Cup, Drink){
  Cup your_cup;
  your_cup.drink(10);
  ASSERT_EQ(your_cup.fluid_oz(),6)<< "   The cup should have 6oz left after drinking 10oz";
  your_cup.drink(4);
  ASSERT_EQ(your_cup.fluid_oz(),2)<< "   The cup should have 2oz left after drinking 4oz";
  your_cup.drink(6);
  ASSERT_EQ(your_cup.fluid_oz(),0)<< "   The cup should have 0oz left after trying to drink 6oz";
}

TEST(Cup, refill_test){
  Cup your_cup;
  your_cup.refill(8);
  ASSERT_EQ(your_cup.fluid_oz(),24)<< "   The cup should now have 24oz after refilling 8oz";
  your_cup.refill(4);
  ASSERT_EQ(your_cup.fluid_oz(),28)<< "   The cup should now have 28oz after refilling 4oz";;
}

TEST(Cup, new_drink_test)
{
  Cup your_cup;
  your_cup.new_drink("Pepsi", 44.0);
  ASSERT_EQ(your_cup.drink_type(),"Pepsi")<< "   The cup should now have Pepsi as the new drink type";
  ASSERT_EQ(your_cup.fluid_oz(),44.0)<< "   The cup should now have 44oz as the new amount";
}
TEST(Cup, empty_test)
{
  Cup your_cup;
  your_cup.empty();
  ASSERT_EQ(your_cup.drink_type(),"nothing")<< "   The cup should now have nothing as the drink type after emptying";
  ASSERT_EQ(your_cup.fluid_oz(),0.0)<< "   The cup should now contain 0oz after emptying";
}

TEST(Driver, Drink) {
  std::string input = "Orange Juice\n8\nD\n2oz\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Your cup currently has 6 oz. of Orange Juice"));
  });
}

TEST(Driver, Refill) {
  std::string input = "Orange Juice\n8\nR\n1oz\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Your cup currently has 9 oz. of Orange Juice"));
  });
}

TEST(Driver, NewDrink) {
  std::string input = "Orange Juice\n8\nN\nMilk\n32\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Your cup currently has 32 oz. of Milk"));
  });
}

TEST(Driver, Empty) {
  std::string input = "Orange Juice\n8\nE\nX\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", input, HasSubstr("Your cup currently has 0 oz. of nothing"));
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}