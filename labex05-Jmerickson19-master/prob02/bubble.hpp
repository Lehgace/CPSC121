// Declare class called Bubble to be used to store Bubble objects.
const double PI = 3.1415;
const double FOURTHIRDS = (4.0 / 3.0);

class Bubble
{
private:
  double radius_;

public:
  void set_radius(double radius);

  double radius() const;

  double volume();

  Bubble operator+(const Bubble & other);

  bool operator==(const Bubble & other);
};
