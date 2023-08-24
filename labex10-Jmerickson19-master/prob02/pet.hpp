#include <iostream>

class Breed
{
private:
  std::string species_;
  std::string name_;
  std::string color_;

public:
  Breed() : species_("Dog"), name_("Pug"), color_("Fawn") {}
  Breed(std::string species, std::string name, std::string color)
      : species_(std::move(species)), name_(std::move(name)),
        color_(std::move(color))
  {
  }

  void set_species(std::string species) { species_ = std::move(species); }
  std::string species() { return species_; }
  void set_name(std::string name) { name_ = std::move(name); }
  std::string name() { return name_; }
  void set_color(std::string color) { color_ = std::move(color); }
  std::string color() { return color_; }
};

class Pet
{
private:
  std::string name_;
  Breed breed_;
  double weight_;

public:
  Pet() : name_("Doug"), weight_(15.6) {}
  Pet(std::string name, Breed breed, double weight)
      : name_(std::move(name)), breed_(std::move(breed)), weight_(weight)
  {
  }
  Pet(std::string pet_name, std::string species, std::string breed_name,
      std::string color, double weight)
      : name_(std::move(pet_name)),
        breed_(std::move(species), std::move(breed_name), std::move(color)),
        weight_(weight)
  {
  }

  void set_name(std::string name) { name_ = std::move(name); }
  std::string name() { return name_; }
  void set_breed(Breed breed) { breed_ = std::move(breed); }
  Breed breed() { return breed_; }
  void set_weight(double weight) { weight_ = weight; }
  double weight() { return weight_; }

  void set_breed(std::string species, std::string name, std::string color_)
  {
    Breed breed_overload =
        Breed(std::move(species), std::move(name), std::move(color_));
    breed_ = breed_overload;
  }

  void print();
};
