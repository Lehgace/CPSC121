#include <iostream>

const int PLATINUM = 850;
const int GOLD = 799;
const int SILVER = 669;
const int INELIGIBLE = 579;
int main()
{
  int credit_score;
  std::cout << "Thank you for applying for the Tuffy Credit card.\n"
            << "Please enter your credit score.\n";
  std::cin >> credit_score;

  if (credit_score < 0 || credit_score > PLATINUM)
  {
    std::cout << "That is an invalid credit score.\n"
              << "Please run program again and provide a valid credit score.\n";
  }
  else if (credit_score > GOLD)
  {
    std::cout << "You are eligible for the Platinum Tuffy Card.\n"
              << "Thank you for using our program, please come again!\n";
  }
  else if (credit_score > SILVER)
  {
    std::cout << "You are eligible for the Gold Tuffy Card.\n"
              << "Thank you for using our program, please come again!\n";
  }
  else if (credit_score > INELIGIBLE)
  {
    std::cout << "You are eligible for the Silver Tuffy Card.\n"
              << "Thank you for using our program, please come again!\n";
  }
  else
  {
    std::cout << "You are ineligible for the Tuffy Card.\n"
              << "Thank you for using our program, please come again!\n";
  }

  return 0;
}
