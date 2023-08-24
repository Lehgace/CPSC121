#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../car.hpp"

using ::testing::HasSubstr;

TEST(Car, accessor_mutator)
{
  Car your_car;
  your_car.set_year(1996);
  your_car.set_name("Honda CRV");
  your_car.drive(64.5);
  ASSERT_EQ(your_car.name(),"Honda CRV") << "your accessor name() was not returning correctly, or your mutators set_name() did not set the name correctly";
  ASSERT_EQ(your_car.year(), 1996) << "your accessor year() was not working correctly, or your mutator set_year() did not set the year correctly";
  ASSERT_EQ(your_car.speed(), 64.5) << "your accessor speed() was not working correctly, or your mutator set_speed() did not set the year correctly";

}

TEST(Car, default_constructor) {
  Car your_car;
  ASSERT_EQ(your_car.name(),"Steam automobile") <<"Either your constructor did not set name_ to Steam automobile or your accessor name() was not working correctly";
  ASSERT_EQ(your_car.year(), 1769) << "Either your constructor did not set year_ to 1769, or your accessor year() was not working correctly";
  ASSERT_EQ(your_car.speed(), 0) << "Either your constructor did not set speed_ to 0, or your accessor speed() was not working correctly";
}

TEST(Car, non_default_constructor)
{
  Car your_car("Subaru Impreza", 2019);
  ASSERT_EQ(your_car.name(), "Subaru Impreza") <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_car.year(), 2019) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_car.speed(), 0) << "Either your constructor did not set speed_ to 0, or your accessor speed() was not working correctly";
}

TEST(Car, drive)
{
  Car your_car("Subaru Impreza", 2019);

  double unittest_speed = 65;
  your_car.drive(65);
  ASSERT_EQ(your_car.speed(), 65) << "Either drive() did not set the speed correctly, or your accessor speed() was not returning the speed value generated";
  ASSERT_EQ(your_car.is_empty(), false) << "In the car class, is_empty should ALWAYS RETURN FALSE";
}

TEST(Car, is_empty) {
  Car your_car;
  ASSERT_FALSE(your_car.is_empty()) << "This function should be virtual and always returns false.";
}

TEST(ElectricCar, accessor_mutator)
{
  ElectricCar your_electric_car;
  your_electric_car.set_year(2019);
  your_electric_car.set_name("Chevrolet Bolt");
  ASSERT_EQ(your_electric_car.name(),"Chevrolet Bolt") << "your accessor name() was not returning correctly, or your mutators set_name() did not set the name correctly";
  ASSERT_EQ(your_electric_car.year(), 2019) << "your accessor year() was not working correctly, or your mutator set_year() did not set the year correctly";
}

TEST(ElectricCar, default_constructor){
  ElectricCar your_electric_car;
  ASSERT_EQ(your_electric_car.name(),"Electric carriage") <<"Either your constructor did not set name_ to Electric carriage, or your accessor name() was not working correctly";
  ASSERT_EQ(your_electric_car.year(), 1832) << "Either your constructor did not set year_ to 1832, or your accessor year() was not working correctly";
  ASSERT_EQ(your_electric_car.speed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
}

TEST(ElectricCar, non_default_constructor){
  ElectricCar your_electric_car("Nissan Leaf", 2019);
  ASSERT_EQ(your_electric_car.name(),"Nissan Leaf") <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_electric_car.year(), 2019) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_electric_car.speed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
}

TEST(ElectricCar, drive){
  ElectricCar your_electric_car;
  your_electric_car.drive(80);
  your_electric_car.drive(80);
  ASSERT_EQ(your_electric_car.speed(), 80) << "The test drove the car to 80 mph.";
  ASSERT_FALSE(your_electric_car.is_empty()) << "The test drove the car to 80mph when the battery was full so it shouldn't be empty";
}

TEST(ElectricCar, drive_and_is_empty){
  ElectricCar your_electric_car;
  your_electric_car.drive(80);
  your_electric_car.drive(80);
  your_electric_car.drive(80);
  your_electric_car.drive(80);
  your_electric_car.drive(80);
  ASSERT_EQ(your_electric_car.speed(), 0) << "The test rand and drove the car until the battery was empty so the speed should be 0";
  ASSERT_TRUE(your_electric_car.is_empty()) << "The test ran and drove the car until it was empty. is_empty should have returned true";
}

TEST(GasolineCar, accessor_mutator)
{
  GasolineCar your_gasoline_car;
  your_gasoline_car.set_year(2019);
  your_gasoline_car.set_name("Honda Civic");
  ASSERT_EQ(your_gasoline_car.name(),"Honda Civic") << "your accessor name() was not returning correctly, or your mutators set_name() did not set the name correctly";
  ASSERT_EQ(your_gasoline_car.year(), 2019) << "your accessor year() was not working correctly, or your mutator set_year() did not set the year correctly";
}

TEST(GasolineCar, default_constructor){
  GasolineCar your_gasoline_car;
  ASSERT_EQ(your_gasoline_car.name(),"Gasoline car") << "Either your constructor did not set name_ to Gasoline car, or your accessorr name() was not working correctly";
  ASSERT_EQ(your_gasoline_car.year(), 1885) << "Either your constructor did not set year_ to 1885, or your accessor year() was not working correctly";
  ASSERT_EQ(your_gasoline_car.speed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
}

TEST(GasolineCar, non_default_constructor){
  GasolineCar your_gasoline_car("Honda Civic", 2019, 100, 25);
  ASSERT_EQ(your_gasoline_car.name(),"Honda Civic") << "Either your constructor did not set name_ to the first parameter, or your accessorr name() was not working correctly";
  ASSERT_EQ(your_gasoline_car.year(), 2019) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_gasoline_car.speed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
}

TEST(GasolineCar, drive) {
  GasolineCar your_gasoline_car;
  your_gasoline_car.drive(80);
  your_gasoline_car.drive(80);
  ASSERT_EQ(your_gasoline_car.speed(), 80) << "The test drove the car to 80 mph.";
  ASSERT_FALSE(your_gasoline_car.is_empty()) << "The test drove the car to 80mph when the tank was full so it shouldn't be empty";
}

TEST(GasolineCar, drive_and_is_empty){
  GasolineCar your_gasoline_car;
  your_gasoline_car.drive(80);
  your_gasoline_car.drive(80);
  your_gasoline_car.drive(80);
  your_gasoline_car.drive(80);
  ASSERT_EQ(your_gasoline_car.speed(), 0) << "The test drove the car until the tank was empty so the speed should be 0";
  ASSERT_TRUE(your_gasoline_car.is_empty()) << "The test drove the car until it was empty. is_empty should have returned true";
}

TEST(Driver, Input1) {
  std::string unittest_input = "1\nHonda Civic\n1984\n12\n23\n50\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Input2) {
  std::string unittest_input = "2\nChevrolet Bolt\n2019\n50\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output1) {
  std::string unittest_input = "1\nHonda Civic\n1984\n12\n23\n50\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Honda Civic")) << "The name of the car based on user input should be Honda Civic";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("6 hour")) << "It should take the car that runs 50mph about 6 hours to empty the 12 gallon tank at 23mpg.";
}

TEST(Driver, Outpu2) {
  std::string unittest_input = "2\nTesla\n2019\n65\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Tesla"))  << "The name of the car based on user input should be Tesla";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("7 hour")) << "It should take the car about 7 hours to use up the battery at 65 mph.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
