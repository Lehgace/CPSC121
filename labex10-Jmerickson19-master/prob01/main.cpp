#include "car_comp.hpp"
#include <iostream>

int main()
{
  Car c1;
  
  Identifier identifier_object = Identifier("Honda", 3, "7B319X4");
  
  Car c2(identifier_object);
  
  Date date_object = Date(4, 11, 2018);
  
  Car c3(date_object);
  
  Car c4(identifier_object, date_object);
  
  c1.print();
  std::cout << "\n";

  
  c2.print();
  std::cout << "\n";

  `
  c3.print();
  std::cout << "\n";

  
  c4.print();
  std::cout << "\n";

  Identifier iden_def;
  
  Date date_def;
  
  c4.set_identity(iden_def);
  
  c4.set_release_date(date_def);
  
  c4.print();
  return 0;
}
