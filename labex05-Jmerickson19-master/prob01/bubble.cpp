#include "bubble.hpp"
// Implement functions from bubble.hpp.
void Bubble::set_radius(double radius) { radius_ = radius; }

double Bubble::radius() { return radius_; }

double Bubble::volume()
{
  return (FOURTHIRDS * PI * (radius_ * radius_ * radius_));
}

Bubble combine_bubble(Bubble b1, Bubble b2)
{
  Bubble bubble;
  bubble.set_radius(b1.radius() + b2.radius());
  return bubble;
}
