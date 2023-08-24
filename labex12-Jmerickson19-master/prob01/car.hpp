#include <iostream>

// Car history references:
// https://www.loc.gov/rr/scitech/mysteries/auto.html
// https://www.mercedes-benz.com/en/mercedes-benz/classic/history/benz-patent-motor-car/

class Car
{
private:
  std::string name_;
  int year_;
  double speed_;

public:
  Car() : Car("Steam automobile", 1769) {}
  Car(const std::string & name, int year) : name_(name), year_(year), speed_(0)
  {
  }
  void set_name(const std::string & name) { name_ = name; }
  void set_year(int year) { year_ = year; }
  std::string name() const { return name_; }
  int year() const { return year_; }
  double speed() const { return speed_; }

  virtual void drive(double speed) { speed_ = speed; }

  virtual bool is_empty() { return false; }
};

class ElectricCar : public Car
{
private:
  double battery_percentage_;

public:
  ElectricCar() : Car("Electric carriage", 1832), battery_percentage_{100.0} {}
  ElectricCar(const std::string & name, int year)
      : Car(name, year), battery_percentage_{100}
  {
  }

  void set_battery_percentage(double battery_percentage)
  {
    battery_percentage_ = battery_percentage;
  }
  double battery_percentage() { return battery_percentage_; }

  bool is_empty() override { return (battery_percentage_ <= 0.0); }

  void drive(double speed) override;
};

class GasolineCar : public Car
{
private:
  double tank_;
  double mpg_;

public:
  GasolineCar() : Car("Gasoline car", 1885), tank_{12}, mpg_{24} {}
  GasolineCar(const std::string & name, int year, double tank, double mpg)
      : Car(name, year), tank_(tank), mpg_(mpg)
  {
  }

  void set_tank(double tank) { tank_ = tank; }
  double tank() { return tank_; }
  void set_mpg(double mpg) { mpg_ = mpg; }
  double mpg() { return mpg_; }

  bool is_empty() override { return (tank_ <= 0.0); }

  void drive(double speed) override;
};
