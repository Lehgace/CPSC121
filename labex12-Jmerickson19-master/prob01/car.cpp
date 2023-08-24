#include "car.hpp"
#include <iostream>

void ElectricCar::drive(double speed)
{
  if (battery_percentage_ > 0.0)
  {
    Car::drive(speed);
    battery_percentage_ -= (speed / 4.0);
    if (battery_percentage_ <= 0.0)
    {
      Car::drive(0.0);
      battery_percentage_ = 0.0;
    }
  }
}

void GasolineCar::drive(double speed)
{
  if (tank_ > 0.0)
  {
    Car::drive(speed);
    tank_ -= (speed / mpg());
    if (tank_ <= 0.0)
    {
      Car::drive(0.0);
      tank_ = 0.0;
    };
  }
}
