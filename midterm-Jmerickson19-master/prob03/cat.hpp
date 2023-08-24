#ifndef _CAT_HPP_
#define _CAT_HPP_

#include <iomanip>
#include <iostream>
#include <string>

class Cat
{
private:
  std::string name_;
  std::string breed_;
  double weight_;
public:
  void set_name(std::string name) { name_ = name; }
  void set_breed(std::string breed) { breed_ = breed; }
  void set_weight(double weight) { weight_ = weight; }
  std::string name() { return name_; }
  std::string breed() { return breed_; }
  double weight() { return weight_; }

  void display()
  {
    std::cout << "Hello! My name is " << name() << ", a " << breed() << ".\n";
    std::cout << "I currently weigh " << weight() << " pounds.\n";
  }
};

#endif
