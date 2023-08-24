#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"
#include "../car.hpp"

using testing::HasSubstr;

class LowestPrice : public ::testing::Test {
protected:
  void SetUp() override {
    car1.set_name("Car 1");
    car1.set_price(80000);
    car1.set_mileage(80000);

    car2.set_name("Car 2");
    car2.set_price(70000);
    car2.set_mileage(80000);

    car3.set_name("Car 3");
    car3.set_price(60000);
    car3.set_mileage(80000);

    car4.set_name("Car 4");
    car4.set_price(50000);
    car4.set_mileage(80000);

    lowest_price_car.set_name("Car 5");
    lowest_price_car.set_price(40000);
    lowest_price_car.set_mileage(80000);
  }

  Car car1, car2, car3, car4, lowest_price_car;
};

TEST(Car, PublicMethodsPresent) {
  Car c;
  ASSERT_NO_THROW({
    c.name();
    c.price();
    c.mileage();
    c.set_name("");
    c.set_price(5.00);
    c.set_mileage(5);
  });
}

TEST(Car, MutatorsAndAccessors) {
  Car your_car;
  ASSERT_NO_THROW({
    your_car.set_name("Test car");
    your_car.set_price(15.00);
    your_car.set_mileage(100);
  });
  ASSERT_EQ(your_car.name(), "Test car") << "      The class' mutator should set the name to Test car and your accessor should return the same value.";
  ASSERT_EQ(your_car.price(), 15.00) << "      The class' mutator should set the price to 15.00 and your accessor should return the same value.";
  ASSERT_EQ(your_car.mileage(), 100) << "      The class' mutator should set the mileage to 100 and your accessor should return the same value.";
}

TEST_F(LowestPrice, LowestFirst) {
  Car cars[] = {lowest_price_car, car4, car3, car2, car1};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(lowest_price(cars, 5).price(), lowest_price_car.price()) << "      The function should return the Car with the lowest price.";  
    ASSERT_EQ(lowest_price(cars, 5).name(), lowest_price_car.name()) << "      The function should return the Car with the lowest price, and keep track of its name.";  
    ASSERT_EQ(lowest_price(cars, 5).mileage(), lowest_price_car.mileage()) << "      The function should return the Car with the lowest price, and keep track of its mileage."; 
  })
}

TEST_F(LowestPrice, LowestMiddle) {
  Car cars[] = {car2, car4, lowest_price_car, car1};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(lowest_price(cars, 4).price(), lowest_price_car.price()) << "      The function should return the Car with the lowest price.";    
    ASSERT_EQ(lowest_price(cars, 4).name(), lowest_price_car.name()) << "      The function should return the Car with the lowest price, and keep track of its name.";   
    ASSERT_EQ(lowest_price(cars, 4).mileage(), lowest_price_car.mileage()) << "      The function should return the Car with the lowest price, and keep track of its mileage."; 
  })
}

TEST_F(LowestPrice, LowestLast) {
  Car cars[] = {car2, car4, car3, car1, car4, lowest_price_car};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(lowest_price(cars, 6).price(), lowest_price_car.price()) << "      The function should return the Car with the lowest price.";    
    ASSERT_EQ(lowest_price(cars, 6).name(), lowest_price_car.name()) << "      The function should return the Car with the lowest price, and keep track of its name.";   
    ASSERT_EQ(lowest_price(cars, 6).mileage(), lowest_price_car.mileage()) << "      The function should return the Car with the lowest price, and keep track of its mileage.";   
  })
}

TEST(UserInput, AskCarInput) {
  std::string user_input = "Car1\n1432\n5000.45\nCar2\n200\n60000.00\nCar3\n34000\n15000.23\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for information for three Car objects.";
}

TEST(Driver, ShowLowestPrice) {
  std::string user_input = "Car1\n1432\n5000.45\nCar2\n200\n60000.00\nCar3\n34000\n15000.23\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The car with the lowest price is Car1 with a mileage of 1432 and a price of $5000.45"))
    << "      Your program should show Car1 as the Car object with the lowest price.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
