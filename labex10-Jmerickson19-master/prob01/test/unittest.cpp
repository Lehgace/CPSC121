#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../car_comp.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(Car, PublicMethodPresent) {
  Identifier your_identifier;
  Date your_date;
  Car your_car1;
  Car your_car2(your_identifier);
  Car your_car3(your_date);
  Car your_car4(your_identifier, your_date);
  your_car1.identity();
  your_car1.set_identity(your_identifier);
  your_car1.release_date();
  your_car1.set_release_date(your_date);
}

TEST(CarClass, AccessorsAndMutators) {
  Identifier unittest_identity("Ford", 1, "123456");
  Date unittest_date(28, 3, 1984);
  Car your_car;
  your_car.set_identity(unittest_identity);
  your_car.set_release_date(unittest_date);

  ASSERT_EQ((your_car.identity()).name(), unittest_identity.name())
    << "The car's identity name should be Ford";
  ASSERT_EQ((your_car.identity()).id(), unittest_identity.id())
    << "The car's identity id should be 1";
  ASSERT_EQ((your_car.identity()).license_plate(),
            unittest_identity.license_plate())
    << "The car's identity license plate should be 123456";
  ASSERT_EQ((your_car.release_date()).day(), unittest_date.day())
    << "The car's release date day should be 28";
  ASSERT_EQ((your_car.release_date()).month(), unittest_date.month())
    << "The car's release date month should be 3";
  ASSERT_EQ((your_car.release_date()).year(), unittest_date.year())
    << "The car's release date year should be 1984";
}

TEST(CarClass, DefaultConstructor) {
  Car your_car;
  ASSERT_EQ((your_car.identity()).name(), "Ford")
    << "The car's identity name should be Ford";
  ASSERT_EQ((your_car.identity()).id(), 1)
    << "The car's identity id should be 1";
  ASSERT_EQ((your_car.identity()).license_plate(), "123456")
    << "The car's identity license plate should be 123456";
  ASSERT_EQ((your_car.release_date()).day(), 1)
    << "The car's release date day should be 1";
  ASSERT_EQ((your_car.release_date()).month(), 1)
    << "The car's release date month should be 1";
  ASSERT_EQ((your_car.release_date()).year(), 1885)
    << "The car's release date year should be 1885";
}

TEST(CarClass, NonDefaultIdentifierConstructor) {
  Identifier your_identifier("Honda", 3, "7B319X4");
  Car your_car(your_identifier);
  ASSERT_EQ((your_car.identity()).name(), "Honda")
    << "The car's identity name should be Honda";
  ASSERT_EQ((your_car.identity()).id(), 3)
    << "The car's identity id should be 3";
  ASSERT_EQ((your_car.identity()).license_plate(), "7B319X4")
    << "The car's identity license plate should be 7B319X4";
  ASSERT_EQ((your_car.release_date()).day(), 1)
    << "The car's release date day should be 1";
  ASSERT_EQ((your_car.release_date()).month(), 1)
    << "The car's release date month should be 1";
  ASSERT_EQ((your_car.release_date()).year(), 1885)
    << "The car's release date year should be 1885";
}

TEST(CarClass, NonDefaultReleaseDateConstructor) {
  Date your_date(28, 3, 1984);
  Car your_car(your_date);

  ASSERT_EQ((your_car.identity()).name(), "Ford")
    << "The car's identity name should be Ford";
  ASSERT_EQ((your_car.identity()).id(), 1)
    << "The car's identity id should be 1";
  ASSERT_EQ((your_car.identity()).license_plate(), "123456")
    << "The car's identity license plate should be 123456";
  ASSERT_EQ((your_car.release_date()).day(), 28)
    << "The car's release date day should be 28";
  ASSERT_EQ((your_car.release_date()).month(), 3)
    << "The car's release date month should be 3";
  ASSERT_EQ((your_car.release_date()).year(), 1984)
    << "The car's release date year should be 1984";
}

TEST(CarClass, NonDefaultIdentifierReleaseDateConstructor) {
  Identifier your_identifier("Honda", 3, "7B319X4");
  Date your_date(28, 3, 1984);
  Car your_car(your_identifier, your_date);
  ASSERT_EQ((your_car.identity()).name(), "Honda")
    << "The car's identity name should be Honda";
  ASSERT_EQ((your_car.identity()).id(), 3)
    << "The car's identity id should be 3";
  ASSERT_EQ((your_car.identity()).license_plate(), "7B319X4")
    << "The car's identity license plate should be 7B319X4";
  ASSERT_EQ((your_car.release_date()).day(), 28)
    << "The car's release date day should be 28";
  ASSERT_EQ((your_car.release_date()).month(), 3)
    << "The car's release date month should be 3";
  ASSERT_EQ((your_car.release_date()).year(), 1984)
    << "The car's release date year should be 1984";
}

TEST(CarClass, Print1) {
  SIMULATE_SIO("", {
    Car your_car(Identifier("Subaru", 3, "6VFH322"), Date(31, 7, 2019));
    your_car.print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Subaru"))
      << "The member function should print Subaru for the identifier name";
    ASSERT_THAT(your_output, HasSubstr("3"))
      << "The member function should print 3 for the identifier id";
    ASSERT_THAT(your_output, HasSubstr("6VFH322"))
      << "The member function should print 6VFH322 for the identifier license plate";
    ASSERT_THAT(your_output, HasSubstr("7/31/2019"))
      << "The member function should print 7/31/2019 for the release date";
  })
}

TEST(CarClass, Print2) {
  SIMULATE_SIO("", {
    Car your_car(Identifier("Jeep", 6, "6WRT885"), Date(21, 2, 2017));
    your_car.print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Jeep"))
      << "The member function should print Jeep for the identifier name";
    ASSERT_THAT(your_output, HasSubstr("6"))
      << "The member function should print 6 for the identifier id";
    ASSERT_THAT(your_output, HasSubstr("6WRT885"))
      << "The member function should print 6WRT885 for the identifier license plate";
    ASSERT_THAT(your_output, HasSubstr("2/21/2017"))
      << "The member function should print 2/21/2017 for the release date";
  })
}

TEST(Driver, Output) {
  std::string unittest_output =
      "The name of the car is: Ford\nThe id of the car is: 1\nThe license "
      "plate of the car is: 123456\nThe release date of the car is: "
      "1/1/1885\n\nThe name of the car is: Honda\nThe id of the car is: 3\nThe "
      "license plate of the car is: 7B319X4\nThe release date of the car is: "
      "1/1/1885\n\nThe name of the car is: Ford\nThe id of the car is: 1\nThe "
      "license plate of the car is: 123456\nThe release date of the car is: "
      "11/4/2018\n\nThe name of the car is: Honda\nThe id of the car is: "
      "3\nThe license plate of the car is: 7B319X4\nThe release date of the "
      "car is: 11/4/2018\n\nThe name of the car is: Ford\nThe id of the car "
      "is: 1\nThe license plate of the car is: 123456\nThe release date of the "
      "car is: 1/1/1885\n";
  ASSERT_EXECEQ("main", "", unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
