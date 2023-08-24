#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../candy_shop.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(Candy, PublicMethodPresent) {
  Candy your_candy;
  your_candy.set_brand("Skittles");
  your_candy.set_flavor("Fruity");
  your_candy.set_cost(1.00);
  your_candy.brand();
  your_candy.flavor();
  your_candy.cost();
}

TEST(Candy, AccessorsMutators) {
  Candy your_candy;
  your_candy.set_brand("Skittles");
  your_candy.set_flavor("Fruity");
  your_candy.set_cost(1.00);
  ASSERT_EQ(your_candy.brand(), "Skittles")
    << "The brand of the candy should be Skittles";
  ASSERT_EQ(your_candy.flavor(), "Fruity")
    << "The flavor of the candy should be Fruity";
  ASSERT_DOUBLE_EQ(your_candy.cost(), 1.00)
    << "The cost of the candy should be 1.00";
}

TEST(Candy, DefaultConstructor) {
  Candy your_candy;
  ASSERT_EQ(your_candy.brand(), "Skittles")
    << "The default brand of the candy should be Skittles";
  ASSERT_EQ(your_candy.flavor(), "Fruity")
    << "The default flavor of the candy should be Fruity";
  ASSERT_EQ(your_candy.cost(), 1.00)
    << "The default cost of the candy should be 1.00";
}

TEST(Candy, NonDefaultConstructor) {
  Candy your_candy("Kisses", "Peppermint", 1.50);
  ASSERT_EQ(your_candy.brand(), "Kisses")
    << "The brand of the candy should be Kisses";
  ASSERT_EQ(your_candy.flavor(), "Peppermint")
    << "The flavor of the candy should be Peppermint";
  ASSERT_DOUBLE_EQ(your_candy.cost(), 1.50)
    << "The cost of the candy should be 1.50";
}

TEST(CandyShop, PublicMethodPresent) {
  Candy your_candy;
  CandyShop your_candy_shop;

  your_candy_shop.size();
  your_candy_shop.add(your_candy);
  your_candy_shop.total_price();
  SIMULATE_SIO("", {
    your_candy_shop.print();
  }, {})
}

TEST(CandyShop, DefaultConstructor) {
  CandyShop your_candy_shop;
  ASSERT_EQ(your_candy_shop.size(), 0)
    << "The starting size of the candy shop should be 0";
}

TEST(CandyShop, AddCandySize) {
  CandyShop your_candy_shop;
  Candy your_candy;
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  ASSERT_EQ(your_candy_shop.size(), 2) << "The size of the candy shop should be 2 after adding two candies";
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  ASSERT_EQ(your_candy_shop.size(), 4) << "The size of the candy shop should be 2 after adding two more candies";
}

TEST(CandyShop, AddCandyLessThanTen) {
  CandyShop your_candy_shop;
  Candy your_candy;
  SIMULATE_SIO("", {
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
    your_candy_shop.add(your_candy);
  }, {
    ASSERT_EQ(your_output, "") << "The member function should not display any error messages.";    
  })
}

TEST(CandyShop, AddCandyOverTen) {
  CandyShop your_candy_shop;
  Candy your_candy;
  
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);
  your_candy_shop.add(your_candy);

  std::string unittest_output = "Error, bag is full!\n";
  SIMULATE_SIO("", {
    your_candy_shop.add(your_candy);
  }, {
    ASSERT_THAT(your_output, HasSubstr("Error, bag is full!"))
      << "The member function should display an error message when it exceeds the capacity, 10.";
  })
}

TEST(CandyShop, Print) {
  CandyShop your_candy_shop;
  
  SIMULATE_SIO("", {
    your_candy_shop.add(Candy ("Kisses", "Peppermint", 1.50));
    your_candy_shop.add(Candy ("Sour Patch Kids", "Sour-Fruity", 10.12));
    your_candy_shop.add(Candy ("Snickers", "Chocolate", 5.13));
    your_candy_shop.print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Kisses"))
      << "The member function's output should contain the brand Kisses.";
    ASSERT_THAT(your_output, HasSubstr("Peppermint"))
      << "The member function's output should contain the flavor Peppermint.";
    ASSERT_THAT(your_output, HasSubstr("1.50"))
      << "The member function's output should contain the cost 1.50.";
    ASSERT_THAT(your_output, HasSubstr("Sour Patch Kids"))
      << "The member function's output should contain the brand Sour Patch Kids.";
    ASSERT_THAT(your_output, HasSubstr("Sour-Fruity"))
      << "The member function's output should contain the flavor Sour-Fruity.";
    ASSERT_THAT(your_output, HasSubstr("10.12"))
      << "The member function's output should contain the cost 10.12.";
    ASSERT_THAT(your_output, HasSubstr("Snickers"))
      << "The member function's output should contain the brand Snickers.";
    ASSERT_THAT(your_output, HasSubstr("Chocolate"))
      << "The member function's output should contain the flavor Chocolate.";
    ASSERT_THAT(your_output, HasSubstr("5.13"))
      << "The member function's output should contain the cost 5.13.";
  })

}

TEST(CandyShop, TotalPrice) {  
  CandyShop your_candy_shop;
  your_candy_shop.add(Candy("","", 5.0));
  your_candy_shop.add(Candy("","", 2.25));
  your_candy_shop.add(Candy("","", 3.15));
  your_candy_shop.add(Candy("","", 10.19));
  ASSERT_DOUBLE_EQ(your_candy_shop.total_price(), 20.59)
    << "The total price for the following costs should be 20.59: 5.0, 2.25, 3.15, 10.19.";
}

TEST(Input, Candies) {
  std::string unittest_input = "Skittles\nFruity\n4.25\nSnickers\nChocolate\n5.13\nSour Patch Kids\nSour-Fruity\n10.12\nQ\n";
  ASSERT_EXECEXIT("main", unittest_input, 3) << "The program should accept a brand, followed by the flavor and then the cost of the candy.";
}

TEST(Driver, Output) {
  std::string unittest_input = "Skittles\nFruity\n4.25\nSnickers\nChocolate\n5.13\nSour Patch Kids\nSour-Fruity\n10.12\nQ\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Skittles"))
    << "The program's output should contain the brand Skittles.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Fruity"))
    << "The program's output should contain the flavor Fruity.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("4.25"))
    << "The program's output should contain the cost 4.25.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Snickers"))
    << "The program's output should contain the brand Snickers.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Chocolate"))
    << "The program's output should contain the flavor Chocolate.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("5.13"))
    << "The program's output should contain the cost 5.13.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Sour Patch Kids"))
    << "The program's output should contain the brand Sour Patch Kids.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Sour-Fruity"))
    << "The program's output should contain the flavor Sour-Fruity.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("10.12"))
    << "The program's output should contain the cost 10.12.";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
