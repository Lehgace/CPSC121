#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../statistics_calculator.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(StatisticsCalculator, Initialization) {
  StatisticsCalculator your_statistics_calculator;
  ASSERT_EQ(your_statistics_calculator.size_of_data(), 0) << "The vector should not have any elements the first time it is created.";
}

TEST(StatisticsCalculator, Add1Data) {
  StatisticsCalculator your_statistics_calculator;
  your_statistics_calculator.add_data(25);
  ASSERT_EQ(your_statistics_calculator.data_at(0), 25) << "The first element of the vector should be 25.";
}

TEST(StatisticsCalculator, Add2Data) {
  StatisticsCalculator your_statistics_calculator;
  your_statistics_calculator.add_data(39);
  your_statistics_calculator.add_data(64);
  ASSERT_EQ(your_statistics_calculator.data_at(0), 39) << "The first element of the vector should be 39.";
  ASSERT_EQ(your_statistics_calculator.data_at(1), 64) << "The first element of the vector should be 64.";
}
TEST(StatisticsCalculator, MeanNoData) {
  StatisticsCalculator your_statistics_calculator;
  ASSERT_EQ(your_statistics_calculator.mean(), 0) << "The mean should be 0 if no data was added to the calculator.";
}

TEST(StatisticsCalculator, Mean) {
  StatisticsCalculator your_statistics_calculator;
  your_statistics_calculator.add_data(34);
  your_statistics_calculator.add_data(69);
  your_statistics_calculator.add_data(25);
  your_statistics_calculator.add_data(35);
  your_statistics_calculator.add_data(86);

  ASSERT_EQ(your_statistics_calculator.size_of_data(), 5) << "The calculator should have added 5 elements.";
  ASSERT_DOUBLE_EQ(your_statistics_calculator.mean(), 49.8);
}

TEST(Driver, Input) {
  std::string unittest_input = "1\n3\n1\n4\n1\n5\n2\n3\n0\n";
  ASSERT_EXECEXIT("main", unittest_input, 3);
}

TEST(Driver, Output) {
  std::string unittest_input = "1\n3\n1\n4\n1\n5\n2\n3\n0\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("0: 3")) << "The first element of the data should be 3.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("1: 4")) << "The second element of the data should be 4.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("2: 5")) << "The third element of the data should be 5.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr("4.00")) << "The mean should be 4.00.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
