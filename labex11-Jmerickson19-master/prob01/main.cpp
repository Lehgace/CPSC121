#include "cash_debit_card.hpp"
#include <iomanip>

int main()
{
  std::string name;
  int choice;
  double amount_due;
  double balance;
  std::cout << "Enter the total price: $";
  std::cin >> amount_due;
  std::cin.ignore();
  std::cout << "Enter your name: ";
  std::getline(std::cin, name);
  std::cout << "Choose the card you will be paying with:\n";
  std::cout << "1 - Cash Card\n";
  std::cout << "2 - Debit Card\n";
  std::cout << "Choice: ";
  std::cin >> choice;
  std::cout << "Enter the balance on your card: $";
  std::cin >> balance;
  if (choice == 1)
  {
    CashCard myCashCard(balance, name);
    myCashCard.charge(amount_due);
    std::cout << "The amount left on your card is $" << std::setprecision(2)
              << std::fixed << myCashCard.balance() << "\n";
  }
  else if (choice == 2)
  {
    DebitCard myDebitCard(balance, name);
    myDebitCard.charge(amount_due);
    std::cout << "The amount left on your card is $" << std::setprecision(2)
              << std::fixed << myDebitCard.balance() << "\n";
  }
  else
  {
    std::cout << "Error - Invalid Option, please try again.\n";
  }
  return 0;
}
