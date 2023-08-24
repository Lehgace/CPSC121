#include "most_sig_digit.hpp"
#include <iostream>

const int neg_limit = -10;
const int pos_limit = 10;

int most_significant_digit(int input)
{
  while (!(input > neg_limit && input < pos_limit))
  {
    input = input / pos_limit;
  }
  return input;
}
