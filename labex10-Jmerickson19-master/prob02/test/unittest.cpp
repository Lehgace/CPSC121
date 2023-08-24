#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"
#include "../pet.hpp"

using ::testing::HasSubstr;

TEST(Breed, PublicMethodsPresent) {
  Breed your_breed;
  your_breed.species();
  your_breed.name();
  your_breed.color();
  your_breed.set_species("Dog");
  your_breed.set_name("Pug");
  your_breed.set_color("Fawn");  
}

TEST(Breed, DefaultConstructor) {
  Breed your_breed;
  ASSERT_EQ(your_breed.species(), "Dog") << "The default species should be Dog";
  ASSERT_EQ(your_breed.name(), "Pug") << "The default name should be Pug";
  ASSERT_EQ(your_breed.color(), "Fawn") << "The default color should be Fawn";
}

TEST(Breed, NonDefaultConstructor) {
  Breed your_breed("Cat", "Siamese", "Seal and white");
  ASSERT_EQ(your_breed.species(), "Cat") << "The species should be Cat";
  ASSERT_EQ(your_breed.name(), "Siamese") << "The name should be Siamese";
  ASSERT_EQ(your_breed.color(), "Seal and white") << "The color should be Seal and white";
}

TEST(Breed, AccessorsAndMutators) {
  Breed your_breed;
  your_breed.set_species("Cat");
  your_breed.set_name("Siamese");
  your_breed.set_color("Seal and white");

  ASSERT_EQ(your_breed.species(), "Cat") << "The default species should be Cat";
  ASSERT_EQ(your_breed.name(), "Siamese") << "The default name should be Siamese";
  ASSERT_EQ(your_breed.color(), "Seal and white") << "The default color should be Seal and white";
}

TEST(Pet, PublicMethodsPresent) {
  Pet your_pet;
  Breed your_breed;
  your_pet.name();
  your_pet.breed();
  your_pet.weight();
  your_pet.set_name("Doug");
  your_pet.set_breed(your_breed);
  your_pet.set_breed("Dog", "Pug", "Fawn");
  your_pet.set_weight(15.6);
}

TEST(Pet, DefaultConstructor) {
  Pet your_pet;
  ASSERT_EQ(your_pet.breed().species(), "Dog") << "The default species should be Dog";
  ASSERT_EQ(your_pet.breed().name(), "Pug")  << "The default Breed name should be Pug";
  ASSERT_EQ(your_pet.breed().color(), "Fawn")  << "The default color should be Fawn";
  ASSERT_EQ(your_pet.name(), "Doug") << "The default name should be Doug";
  ASSERT_EQ(your_pet.weight(), 15.6) << "The default weight should be 15.6";
}

TEST(Pet, NonDefaultConstructorBreedParameter) {
  Breed your_breed("Cat", "Tabby", "Orange");
  Pet your_pet("Pumpkin", your_breed, 16.8);
  ASSERT_EQ(your_pet.breed().species(), "Cat") << "The species should be Cat";
  ASSERT_EQ(your_pet.breed().name(), "Tabby")  << "The Breed name should be Tabby";
  ASSERT_EQ(your_pet.breed().color(), "Orange") << "The color should be Orange";
  ASSERT_EQ(your_pet.name(), "Pumpkin") << "The name should be Pumpkin";  
  ASSERT_EQ(your_pet.weight(), 16.8) << "The weight should be 16.8";
}

TEST(Pet, NonDefaultConstructorExpandedBreedParameter) {
  Pet your_pet("Pumpkin", "Cat", "Tabby", "Orange", 16.8);
  ASSERT_EQ(your_pet.breed().species(), "Cat") << "The species should be Cat";
  ASSERT_EQ(your_pet.breed().name(), "Tabby")  << "The Breed name should be Tabby";
  ASSERT_EQ(your_pet.breed().color(), "Orange") << "The color should be Orange";
  ASSERT_EQ(your_pet.name(), "Pumpkin") << "The name should be Pumpkin";  
  ASSERT_EQ(your_pet.weight(), 16.8) << "The weight should be 16.8";
}

TEST(Pet, AccessorsAndMutators) {
  Pet your_pet;
  Breed your_breed("Dog", "American Pitbull Terrier", "Blonde");
  your_pet.set_breed(your_breed);
  your_pet.set_name("Mimi");
  your_pet.set_weight(38.4);
  ASSERT_EQ(your_pet.name(), "Mimi");  
  ASSERT_EQ(your_pet.weight(), 38.4);
  ASSERT_EQ(your_pet.breed().species(), "Dog");
  ASSERT_EQ(your_pet.breed().name(), "American Pitbull Terrier");
  ASSERT_EQ(your_pet.breed().color(), "Blonde");
}

TEST(Pet, SetBreedOverload) {
  Pet your_pet;
  your_pet.set_breed("Dog", "Pug", "Fawn");
  ASSERT_EQ(your_pet.breed().species(), "Dog") << "The species should be Dog";
  ASSERT_EQ(your_pet.breed().name(), "Pug") << "The name should be Pug";
  ASSERT_EQ(your_pet.breed().color(), "Fawn") << "The color should be Fawn";
}

TEST(Pet, Print) {
  SIMULATE_SIO("", {
    Pet your_pet("Pumpkin", "Cat", "Tabby", "Orange", 16.8);
    your_pet.print();
  }, {
    ASSERT_THAT(your_output, HasSubstr("Name: Pumpkin")) << "The name should be Pumpkin";  
    ASSERT_THAT(your_output, HasSubstr("Species: Cat")) << "The species should be Cat";
    ASSERT_THAT(your_output, HasSubstr("Breed: Tabby"))  << "The Breed name should be Tabby";  
    ASSERT_THAT(your_output, HasSubstr("Orange")) << "The color should be Orange";  
    ASSERT_THAT(your_output, HasSubstr("16.8")) << "The weight should be 16.8";
  })
}

TEST(Driver, Input) {
  std::string unittest_input = "AirBud\nDog\nGolden Retriever\nBlonde\n44.5\nCookie\nDog\nEnglish Bulldog\nBrown & White\n31.2\nq\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output) {
  std::string unittest_input = "AirBud\nDog\nGolden Retriever\nBlonde\n44.5\nCookie\nDog\nEnglish Bulldog\nBrown & White\n31.2\nq\n";

  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Name: AirBud")) << "The name should be AirBud";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Species: Dog")) << "The species should be Dog";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Breed: Golden Retriever"))  << "The Breed name should be Golden Retriever";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Color: Blonde")) << "The color should be Blonde";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Weight: 44.5")) << "The weight should be 44.5";

  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Name: Cookie")) << "The name should be Cookie";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Species: Dog")) << "The species should be Dog";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Breed: English Bulldog"))  << "The Breed name should be English Bulldog";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Color: Brown & White")) << "The color should be Brown & White";  
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("Weight: 31.2")) << "The weight should be 31.2";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
