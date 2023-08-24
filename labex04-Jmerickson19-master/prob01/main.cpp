#include <fstream>
#include <iomanip>
#include <iostream>

int main()
{
  int donors;
  std::string donate_file;
  float donation = 0;
  std::ofstream output_file;
  // Prompt for # of donors.
  std::cout << "Please provide the number of donors: ";
  std::cin >> donors;
  // Check that # of donors is invalid.
  if (donors <= 0)
  {
    std::cout << "You need to have at least one donor for your cause to save "
              << "donation information.\n";
    return 0;
  }
  // Prompt for name of donations file.
  std::cout << "Please provide the name of the donations file: ";
  std::cin >> donate_file;

  // Open the inputed file
  output_file.open(donate_file);
  output_file << donors << "\n";
  // Prompt user for donation amounts for each donor; save each donation to
  // file.
  for (int i = 0; i < donors; i++)
  {
    std::cout << "Donor " << i + 1 << ": $";
    std::cin >> donation;
    output_file << std::fixed << std::setprecision(2) << donation << std::endl;
  }
  // Close file and thank for donating.
  output_file.close();
  std::cout << "Thank you for donating!\n";

  return 0;
}
