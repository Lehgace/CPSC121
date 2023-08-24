#include <iostream>
#include <string>

class CashCard
{
private:
  double balance_;
  std::string name_;

protected:
  void charge_balance(double charged);

public:
  CashCard() : balance_{100.00}, name_("Alex Amarnani") {}
  CashCard(double balance, std::string name)
      : balance_(balance), name_(std::move(name))
  {
  }

  void set_balance(double balance) { balance_ = balance; }
  double balance() { return balance_; }
  void set_name(std::string name) { name_ = std::move(name); }
  std::string name() { return name_; }

  void charge(double charged);
};

class DebitCard : public CashCard
{
public:
  DebitCard() : DebitCard(100.00, "Sidney Lee") {}
  DebitCard(double balance, std::string name)
      : CashCard(balance, std::move(name))
  {
  }

  void charge(double charged);
};
