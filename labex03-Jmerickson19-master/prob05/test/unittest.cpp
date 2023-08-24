#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Operations, OutputFormat) {
  std::string unittest_output =
      "Please enter in the operation (+, -, *, /): Please "
      "input the first number: Please input the second "
      "number: You chose to multiply: 5 * 6 = 30\n";
  ASSERT_EXECIO_EQ("main", "* 5 6", unittest_output);
}

TEST(Operations, Addition) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "+";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);
    int sum = num_one + num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to add: ";
    unittest_output +=
        str_one + " + " + str_two + " = " + std::to_string(sum) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Operations, Subtraction) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "-";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);

    int dif = num_one - num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to subtract: ";
    unittest_output +=
        str_one + " - " + str_two + " = " + std::to_string(dif) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Operations, Multiplication) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "*";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);

    int multiply = num_one * num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to multiply: ";
    unittest_output +=
        str_one + " * " + str_two + " = " + std::to_string(multiply) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Operations, Division) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "/";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);

    int divide = num_one / num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to divide: ";
    unittest_output +=
        str_one + " / " + str_two + " = " + std::to_string(divide) + "\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Operations, FailCase) {
  for (int i = 0; i < 10; i++) {
    int fail_input = rand() % 10;
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = std::to_string(fail_input) + " " +
                        std::to_string(num_one) + " " + std::to_string(num_two);
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: Invalid operation type.\n";

    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
