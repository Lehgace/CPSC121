#include "cash_debit_card.hpp"
#include <iostream>
#include <string>
const double FEE = 30.00;

void CashCard::charge_balance(double charged) { balance_ -= charged; }

void CashCard::charge(double charged)
{
  if (charged <= balance_)
  {
    charge_balance(charged);
  }
  else
  {
    std::cout << "Insufficient funds\n";
  }
}

void DebitCard::charge(double charged)
{
  if (charged > balance())
  {
    charge_balance(FEE);
    std::cout << "Overdraft Fee of $30.00 Incurred\n";
  }
  charge_balance(charged);
}
