#include <iostream>

class Food
{
private:
  std::string name_;
  double mass_;

public:
  Food() : name_("Apple Pie"), mass_{1000} {}
  Food(std::string name, double mass) : name_(std::move(name)), mass_(mass) {}

  void set_name(std::string name) { name_ = std::move(name); }
  std::string name() { return name_; }
  void set_mass(double mass) { mass_ = mass; }
  double mass() { return mass_; }

  void eat(double eat);

  void print() { std::cout << name() << ' ' << mass() << "g\n"; }
};

class Utensil
{
private:
  double size_;
  std::string color_;

public:
  Utensil() : size_{8.5}, color_("silver") {}
  Utensil(double size, std::string color)
      : size_(size), color_(std::move(color))
  {
  }

  void set_size(double size) { size_ = size; }
  double size() { return size_; }
  void set_color(std::string color) { color_ = std::move(color); }
  std::string color() { return color_; }

  void use(Food & object);
};

class Spoon : public Utensil
{
private:
  double bite_size_;

public:
  Spoon() : Utensil(6, "silver"), bite_size_{25} {}
  Spoon(double size, std::string color, double bite_size)
      : Utensil(size, std::move(color)), bite_size_(bite_size)
  {
  }
  void set_bite_size(double bite_size) { bite_size_ = bite_size; }
  double bite_size() { return bite_size_; }

  void use(Food & object);
};
