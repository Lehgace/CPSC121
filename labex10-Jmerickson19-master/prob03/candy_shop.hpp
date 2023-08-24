#include <iostream>

class Candy
{
private:
  std::string brand_;
  std::string flavor_;
  double cost_;

public:
  Candy() : Candy("Skittles", "Fruity", 1.00) {}

  Candy(const std::string & brand, const std::string & flavor, double cost)
      : brand_(brand), flavor_(flavor), cost_(cost)
  {
  }

  std::string brand() const { return brand_; }
  void set_brand(const std::string & brand) { brand_ = brand; }
  std::string flavor() const { return flavor_; }
  void set_flavor(const std::string & flavor) { flavor_ = flavor; }
  double cost() const { return cost_; }
  void set_cost(double cost) { cost_ = cost; }
};
