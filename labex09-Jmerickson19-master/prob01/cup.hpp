#include <iostream>

const double SIXTN = 16.0;

class Cup
{
private:
  std::string drink_type_;
  double fluid_oz_;

public:
  Cup() : drink_type_("Water"), fluid_oz_(SIXTN) {}

  Cup(std::string drink_name, double drink_amount)
      : drink_type_(drink_name), fluid_oz_(drink_amount)
  {
  }
  void set_drink_type(std::string drink_type) { drink_type_ = drink_type; }
  void set_fluid_oz(double fluid_oz) { fluid_oz_ = fluid_oz; }
  std::string drink_type() { return drink_type_; }
  double fluid_oz() { return fluid_oz_; }

  void drink(double amount)
  {
    fluid_oz_ -= amount;
    if (fluid_oz_ < 0.0)
    {
      fluid_oz_ = 0.0;
    }
  }
  void refill(double amount) { fluid_oz_ += amount; }
  void new_drink(std::string new_drink, double new_amount)
  {
    drink_type_ = new_drink;
    fluid_oz_ = new_amount;
  }
  void empty()
  {
    drink_type_ = "nothing";
    fluid_oz_ = 0.0;
  }
};
