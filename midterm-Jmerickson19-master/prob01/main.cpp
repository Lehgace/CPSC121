#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  const std::string FILENAME = "report.txt";
  const int NUMBER_OF_QUARTERS = 4;

  std::string line;
  double sale;
  double sum = 0;
  std::ifstream input_file;
  input_file.open(FILENAME);

  std::cout << "Annual sales\n";

  while (std::getline(input_file, line))
  {
    if (input_file >> sale)
    {
        sum += sale;
    }
    std::cout << line << ": $ " << sum << "\n";
  }

  return 0;
}
