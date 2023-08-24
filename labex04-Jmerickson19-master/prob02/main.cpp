#include <fstream>
#include <iomanip>
#include <iostream>

int main()
{
  std::ifstream input_file;
  std::string file_name;
  int consolidate_months = 0;

  // Prompt for name of file.
  std::cout << "Please provide the file name for your report file: ";
  std::cin >> file_name;

  // Open inputed file.
  input_file.open(file_name);

  // Check if the specified file exists.
  if (input_file.is_open())
  {
    // Prompt for number of months to consolidate.
    std::cout << "Please provide the number of months to consolidate: ";
    std::cin >> consolidate_months;

    std::string line;
    int line_count = 0;
    float sum = 0;
    int month_count = 1;
    std::string month_track;

    // Loop to read and sum each line to the appropriate consolidate values
    // specified.

    while (std::getline(input_file, line))
    {
      float sales = stof(line);
      sum += sales;
      line_count++;
      month_track.append(std::to_string(month_count));
      month_track.append(" ");
      month_count++;
      if (line_count == consolidate_months)
      {
        std::cout << "Month " << month_track << "sales: $" << std::fixed
                  << std::setprecision(2) << sum << "\n";
        month_track = "";
        line_count = 0;
        sum = 0;
      }
    }
    input_file.close();
  }
  else
  {
    std::cout << "Invalid report file!\n";
  }
  return 0;
}
