#include <fstream>
#include <iostream>
#include <vector>

const int state_course = 0;
const int state_location = 1;
const int state_day = 2;
const int state_start = 3;
const int state_end = 4;
const int max_time_length = 5;
const int max_hr_lim = 23;
const int max_min_lim = 59;
const int hr_to_min = 60;

// Function that checks if an inputed schedule has legal weekly symbols.
bool IsScheduleValid(const std::string & schedule,
                     const std::vector<std::string> & schedule_symbols)
{
  bool valid = false;
  for (const auto & schedule_symbol : schedule_symbols)
  {
    if (schedule == schedule_symbol)
    {
      valid = true;
      break;
    }
  }
  return valid;
}
// Function that checks if start/end time is inputed as XX:YY
bool IsTimeFormatValid(const std::string & schedule_time)
{
  bool valid = true;
  int colon_pos = schedule_time.find(':');
  if (colon_pos == std::string::npos || colon_pos == 0)
  {
    valid = false;
  }
  return valid;
}
// Function that checks if time XX:YY is correct military time.
bool IsTimeValid(const std::string & schedule_time)
{
  bool valid = true;
  std::string hours;
  std::string minutes;
  int colon_pos = schedule_time.find(':');
  hours = schedule_time.substr(0, colon_pos);
  minutes = schedule_time.substr(colon_pos + 1, 2);
  int hr = stoi(hours);
  int min = stoi(minutes);
  if (hr < 0 || hr > max_hr_lim)
  {
    valid = false;
  }
  else if (min < 0 || min > max_min_lim)
  {
    valid = false;
  }
  return valid;
}
// Function that converts inputed XX:YY time into minutes for comparison.
int ConvertToMinutes(const std::string & schedule_time)
{
  int colon_pos = schedule_time.find(':');
  std::string hours = schedule_time.substr(0, colon_pos);
  std::string minutes = schedule_time.substr(colon_pos + 1, 2);
  int hr = stoi(hours);
  int min = stoi(minutes);
  int min_convert = hr * hr_to_min + min;
  return min_convert;
}
// Function that checks if the start time happens before the end time.
bool IsStartEndValid(const std::string & start_time,
                     const std::string & end_time)
{
  int start_min = ConvertToMinutes(start_time);
  int end_min = ConvertToMinutes(end_time);
  return (end_min > start_min);
}

int main()
{
  std::string line;
  std::string filename;
  std::string start_time;
  bool is_valid = true;
  std::vector<std::string> schedule_symbols;
  schedule_symbols.emplace_back("M");
  schedule_symbols.emplace_back("T");
  schedule_symbols.emplace_back("W");
  schedule_symbols.emplace_back("H");
  schedule_symbols.emplace_back("F");
  schedule_symbols.emplace_back("S");
  schedule_symbols.emplace_back("MW");
  schedule_symbols.emplace_back("MF");
  schedule_symbols.emplace_back("TH");

  // Prompt for filename.
  std::cout << "Welcome to Titan Scheduler!\n"
            << "Please enter the file name containing the list of classes: ";
  std::cin >> filename;

  // Prepare to open inputed file.
  std::ifstream in_file;
  in_file.open(filename);
  // Check if the inputed file exists, if it does open the file.
  if (in_file.is_open())
  {
    int state = state_course;
    bool valid_line = true;
    // Loop to check if schedule contents are valid.
    while (is_valid)
    {
      valid_line = true;
      if (in_file.eof())
      {
        valid_line = false;
      }
      else
      {
        std::getline(in_file, line);
        if (line.length() == 0)
        {
          valid_line = false;
        }
      }
      if (!valid_line && state == state_course)
      {
        break;
      }
      switch (state)
      {
        case state_course:
          state++;
          break;
        case state_location:
          if (!valid_line)
          {
            std::cout << "Error: Unable to retrieve location.\n";
            is_valid = false;
          }
          state++;
          break;
        case state_day:
          if (!valid_line)
          {
            std::cout << "Error: Unable to get a weekly schedule.\n";
            is_valid = false;
          }
          else if (!IsScheduleValid(line, schedule_symbols))
          {
            std::cout << "Error: Invalid weekly schedule symbol " << line
                      << ".\n";
            is_valid = false;
          }
          state++;
          break;
        case state_start:
          if (!valid_line)
          {
            std::cout << "Error: Unable to get a valid start time.\n";
            is_valid = false;
          }
          else if (!IsTimeFormatValid(line))
          {
            std::cout << "Error: Unable to get a valid start time.\n";
            is_valid = false;
          }
          else if (!IsTimeValid(line))
          {
            std::cout << "Error: " << line << " is an invalid start time.\n";
            is_valid = false;
          }
          else
          {
            start_time = line;
          }
          state++;
          break;
        case state_end:
          if (!valid_line)
          {
            std::cout << "Error: Unable to get a valid end time.\n";
            is_valid = false;
          }
          else if (!IsTimeFormatValid(line))
          {
            std::cout << "Error: Unable to get a valid end time.\n";
            is_valid = false;
          }
          else if (!IsTimeValid(line))
          {
            std::cout << "Error: " << line << " is an invalid end time.\n";
            is_valid = false;
          }
          else if (!IsStartEndValid(start_time, line))
          // line is equal to end time.
          {
            std::cout << "Error: The start time " << start_time
                      << " should happen before the end time " << line << ".\n";
            is_valid = false;
          }
          state = state_course;
          break;
        default:
          break;
      }
    }
    in_file.close();
  }
  else
  {
    std::cout << "Error: File does not exist.\n";
    is_valid = false;
  }
  if (is_valid)
  {
    std::cout << "Valid file\n";
  }
  else
  {
    std::cout << "Invalid file" << std::endl;
  }
  std::cout << "Thank you for using Titan Scheduler.\n";
  return 0;
}
