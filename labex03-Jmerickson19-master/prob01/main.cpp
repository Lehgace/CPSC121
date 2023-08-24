#include <iostream>

int main()
{
  int num = 0;
  int repetitions = 0;
  int sum = num;

  std::cout << "Please enter a number: ";
  std::cin >> num;

  std::cout << "Number of times to be added: ";
  std::cin >> repetitions;

  if (repetitions < 0)
  {
    std::cout << "Repetitions cannot be negative.\n";
  }
  else
  {
    for (int i = 0; i < repetitions; i++)
    {
      sum = sum + num;
    }
    std::cout << "The sum is " << sum << std::endl;
  }

  return 0;
}
