#include <iomanip>
#include <iostream>

const float TAX = 0.075;
const float PERCENT = 100.0;

int main()
{
  float bill;
  float tip_percent;
  float taxes;
  float tip;
  float total;

  std::cout << "Please input meal cost: ";
  std::cin >> bill;
  std::cout << "Please input tip percentage: \n";
  std::cin >> tip_percent;

  taxes = bill * TAX;
  tip = bill * (tip_percent / PERCENT);
  total = bill + taxes + tip;

  std::cout << "Restaurant Bill\n";
  std::cout << "====================\n";
  std::cout << "Subtotal: $" << std::fixed << std::setprecision(2) << bill
            << std::endl;
  std::cout << "Taxes: $" << std::fixed << std::setprecision(2) << taxes
            << std::endl;
  std::cout << "Tip: $" << std::fixed << std::setprecision(2) << tip
            << std::endl;
  std::cout << "====================\n";
  std::cout << "Total: $" << std::fixed << std::setprecision(2) << total
            << std::endl;
  return 0;
}
