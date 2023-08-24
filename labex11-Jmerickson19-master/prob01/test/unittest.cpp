#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cash_debit_card.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(CashCard, AccessorsAndMutators) {
  CashCard your_cash_card;
  your_cash_card.set_balance(100.00);
  your_cash_card.set_name("Default");

  ASSERT_EQ(your_cash_card.balance(), 100.00) << "The balance should be 100.00";
  ASSERT_EQ(your_cash_card.name(), "Default") << "The name should be Default";
}

TEST(CashCard, DefaultConstructor) {
  CashCard your_cash_card;
  ASSERT_EQ(your_cash_card.balance(), 100.00) << "The default balance should be 100.00";
  ASSERT_EQ(your_cash_card.name(), "Alex Amarnani") << "The default name should be Alex Amarnani";
}

TEST(CashCard, NonDefaultConstructor) {
  CashCard your_cash_card(120.00, "Linda Bobinda");
  ASSERT_DOUBLE_EQ(your_cash_card.balance(), 120.00);
  ASSERT_EQ(your_cash_card.name(), "Linda Bobinda");
}

TEST(CashCard, NormalCharge) {
  CashCard your_cash_card;
  your_cash_card.charge(30);

  ASSERT_EQ(your_cash_card.balance(), 70.00) << "The balance remaining after charging $30.00 should be $70.00";
}

TEST(CashCard, OverCharge) {
  CashCard your_cash_card;  
  SIMULATE_SIO("", {
    your_cash_card.charge(130);
  }, {
    ASSERT_EQ(your_output, "Insufficient funds\n") << "The member function should show an error because charging $130.00 is over the $100.00 balance.";
  })
  ASSERT_EQ(your_cash_card.balance(), 100.00) << "The balance should not change because the amount charged is over the balance.";
}

TEST(DebitCard, CheckInheritance) {
  DebitCard your_debit_card;
  CashCard* your_cash_card = dynamic_cast< CashCard* >( &your_debit_card );
  ASSERT_NE(your_cash_card, nullptr) << "The DebitCard class should inherit from the CashCard class.";
}

TEST(DebitCard, AccessorsAndMutators) {
  DebitCard your_debit_card;
  your_debit_card.set_balance(100.00);
  your_debit_card.set_name("Default");

  ASSERT_EQ(your_debit_card.balance(), 100.00) << "The balance should be 100.00";
  ASSERT_EQ(your_debit_card.name(), "Default") << "The name should be Default";
}

TEST(DebitCard, DefaultConstructor) {
  DebitCard your_debit_card;

  ASSERT_EQ(your_debit_card.balance(), 100.00) << "The balance should be 100.00";
  ASSERT_EQ(your_debit_card.name(), "Sidney Lee") << "The name should be Sidney Lee";
}

TEST(DebitCard, NonDefaultConstructor) {
  DebitCard your_debit_card(120, "Jody Bobudy");

  ASSERT_EQ(your_debit_card.balance(), 120.00) << "The default balance should be 120.00";
  ASSERT_EQ(your_debit_card.name(), "Jody Bobudy") << "The default name should be Jody Bobudy";
}

TEST(DebitCard, NormalCharge) {
  DebitCard your_debit_card;
  your_debit_card.charge(30);

  ASSERT_EQ(your_debit_card.balance(), 70.00) << "The balance remaining after charging $30.00 should be $70.00";
}

TEST(DebitCard, OverCharge) {
  DebitCard your_debit_card;
  

  SIMULATE_SIO("", {
    your_debit_card.charge(130);
  }, {
    ASSERT_EQ(your_output, "Overdraft Fee of $30.00 Incurred\n") << "The member function should inform the user of the overdraft fee of $30.00 because charging $130.00 is over the $100.00 balance.";
  })  
  ASSERT_EQ(your_debit_card.balance(), -60.00) << "The member function should show a balance of $-60.00 because charging $130.00 + $30.00 is subtracted from the $100.00 balance.";
}

TEST(Driver, Input) {
  std::string unittest_input = "30.00\nLeslie Moreau\n1\n50.00\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output) {
  std::string unittest_input = "30.00\nLeslie Moreau\n1\n50.00\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("The amount left on your card is $20.00"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
