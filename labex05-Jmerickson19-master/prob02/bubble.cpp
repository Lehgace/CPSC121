#include "bubble.hpp"
// Implement functions from bubble.hpp.
void Bubble::set_radius(double radius) { radius_ = radius; }

double Bubble::radius() const { return radius_; }

Bubble Bubble::operator+(const Bubble & other)
{
  Bubble bubble;
  bubble.set_radius(radius() + other.radius());
  return bubble;
}

bool Bubble::operator==(const Bubble & other)
{
  return (radius() == other.radius());
}

double Bubble::volume()
{
  return (FOURTHIRDS * PI * (radius_ * radius_ * radius_));
}
