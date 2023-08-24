#include <iostream>
#include <string>

class Identifier
{
private:
  std::string name_;
  int id_;
  std::string license_plate_;

public:
  Identifier() : Identifier("Ford", 1, "123456") {}

  Identifier(const std::string & name, int id,
             const std::string & license_plate)
      : name_(name), id_(id), license_plate_(license_plate)
  {
  }

  std::string name() const { return name_; }
  void set_name(const std::string & name) { name_ = name; }
  int id() const { return id_; }
  void set_id(int id) { id_ = id; }
  std::string license_plate() const { return license_plate_; }
  void set_license_plate(const std::string & license_plate)
  {
    license_plate_ = license_plate;
  }
};

// Class that represents dates
class Date
{
private:
  int day_;
  int month_;
  int year_;

public:
  Date() : Date(1, 1, 1885) {}

  Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}

  int day() const { return day_; }
  void set_day(int day) { day_ = day; }
  int month() const { return month_; }
  void set_month(int month) { month_ = month; }
  int year() const { return year_; }
  void set_year(int year) { year_ = year; }
};

class Car
{
private:
  Identifier identity_;
  Date release_date_;

public:
  Car() {}
  Car(Identifier iden) : identity_(std::move(iden)) {}
  Car(Date obj) : release_date_(obj) {}
  Car(Identifier iden, Date obj)
      : identity_(std::move(iden)), release_date_(obj)
  {
  }

  void set_identity(Identifier identity) { identity_ = std::move(identity); }
  Identifier identity() const { return identity_; }
  void set_release_date(Date date) { release_date_ = date; }
  Date release_date() const { return release_date_; }

  void print();
};
