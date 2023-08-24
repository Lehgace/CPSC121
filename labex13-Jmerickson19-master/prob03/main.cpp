#include "statistics_calculator.hpp"
#include <iomanip>
#include <iostream>

int main()
{
  int choice = 0;
  // Create an instance of the `StatisticsCalculator` object

  do
  {
    std::cout << "Welcome to the Statistics Calculator!\n";
    std::cout << "Please select a menu option:\n";
    std::cout << "1 - Add to the data set\n";
    std::cout << "2 - Display the entire data set\n";
    std::cout << "3 - Get the mean of the data set\n";
    std::cout << "0 - Exit the program\n";
    std::cout << "Selection: ";
    std::cin >> choice;

    if (choice == 1)
    {
      double data_input;
      std::cout << "Input the number you want to add to the data set: ";
      std::cin >> data_input;
      // Call the function that adds the data passed in by the user
      // into the vector.

      std::cout << "\n";
    }
    else if (choice == 2)
    {
      std::cout << "The data set\n";
      for (int i = 0; i < /* get the size of the vector */; i++)
      {
        // Call the function to get the corresponding element from the
        // vector and store in the variable called data

        double data;
        std::cout << i << ": " << data << "\n";
      }
      std::cout << "\n";
    }
    else if (choice == 3)
    {
      // Call the function to get the mean of the data and store it in the
      // variable called mean

      double mean;
      std::cout << "The mean of the data is " << std::fixed
                << std::setprecision(2) << mean << "\n\n";
    }
    else if (choice == 0)
    {
      std::cout << "Exiting...\n";
    }
    else
    {
      std::cout << "Error - Invalid Choice!\n\n";
    }
  } while (choice != 0);

  return 0;
}
