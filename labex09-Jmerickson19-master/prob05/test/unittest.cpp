#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../list.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(ShoppingList, DefaultConstructor) {
  ShoppingList your_shopping_list;
  ASSERT_EQ(your_shopping_list.num_items(), 0);
  ASSERT_EQ(your_shopping_list.list_size(), 10);
}

TEST(ShoppingList, NonDefaultConstructor) {
  ShoppingList your_shopping_list(100);
  ASSERT_EQ(your_shopping_list.num_items(), 0);
  ASSERT_EQ(your_shopping_list.list_size(), 100);
}

TEST(ShoppingList, AddItem) {
  ShoppingList your_shopping_list;
  your_shopping_list.add_item("A");
  your_shopping_list.add_item("B");
  your_shopping_list.add_item("C");
  your_shopping_list.add_item("D");
  your_shopping_list.add_item("E");
  ASSERT_EQ(your_shopping_list.num_items(), 5) << "    num_items() did not correctly track the 5 items that were added to the shopping list.";
}

TEST(ShoppingList, AddItemFullList) {
  ShoppingList your_shopping_list;
  your_shopping_list.add_item("A");
  your_shopping_list.add_item("B");
  your_shopping_list.add_item("C");
  your_shopping_list.add_item("D");
  your_shopping_list.add_item("E");
  your_shopping_list.add_item("F");
  your_shopping_list.add_item("G");
  your_shopping_list.add_item("H");
  your_shopping_list.add_item("I");
  your_shopping_list.add_item("J");

  SIMULATE_SIO("", {
    your_shopping_list.add_item("K");
  }, {
    ASSERT_EQ(your_output, "Error! Shopping List full!\n");
  })
}

TEST(ShoppingList, RemoveItem) {
  ShoppingList your_shopping_list;
  your_shopping_list.add_item("A");
  your_shopping_list.add_item("B");
  your_shopping_list.add_item("C");
  your_shopping_list.remove_last();
  ASSERT_EQ(your_shopping_list.num_items(), 2) << "num_items() did not correctly track that 1 item was removed using remove_last().";
}

TEST(ShoppingList, PrintList) {
  ShoppingList your_shopping_list;
  your_shopping_list.add_item("Dumplings");
  your_shopping_list.add_item("Samosas");
  your_shopping_list.add_item("Isaw");
  your_shopping_list.add_item("Nachos");
  your_shopping_list.add_item("Crostini");
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", {
      your_shopping_list.print_list();
    }, {
      ASSERT_THAT(your_output, HasSubstr("1) Dumplings")) << "print_list() should have displayed Dumplings.";
      ASSERT_THAT(your_output, HasSubstr("2) Samosas")) << "print_list() should have displayed Samosas.";
      ASSERT_THAT(your_output, HasSubstr("3) Isaw")) << "print_list() should have displayed Isaw.";
      ASSERT_THAT(your_output, HasSubstr("4) Nachos")) << "print_list() should have displayed Nachos.";
      ASSERT_THAT(your_output, HasSubstr("5) Crostini")) << "print_list() should have displayed Crostini.";
    })
  });
}

TEST(Driver, Output) {
  std::string unittest_output = "Shopping List:\n1) Milk\n2) Eggs\n3) Flour\n"
                                "4) Sugar\n5) Cocoa Powder\n6) Vanilla\n";
  ASSERT_DURATION_LE(3, { 
    ASSERT_EXECEQ("main", "", unittest_output);
  });
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();}
