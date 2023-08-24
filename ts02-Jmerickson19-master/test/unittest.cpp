#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "gtest_ext.h"
#include "../scheduler.hpp"

using ::testing::HasSubstr;
using ::testing::AnyOf;
using ::testing::AllOf;
using ::testing::Not;

class LoadSchedule : public UnitTestFileManager
{
protected:
  LoadSchedule() : UnitTestFileManager("sched.txt") {}
};

TEST(Course, CourseNameAccessorMutator)
{
  Course your_course;
  your_course.set_course_name("CPSC 121");
  ASSERT_EQ(your_course.course_name(), "CPSC 121");
}

TEST(Course, LocationAccessorMutator)
{
  Course your_course;
  your_course.set_location("E202");
  ASSERT_EQ(your_course.location(), "E202");
}

TEST(Course, WeeklyScheduleAccessorMutator)
{
  Course your_course;
  your_course.set_weekly_schedule("MW");
  ASSERT_EQ(your_course.weekly_schedule(), "MW");
}

TEST(Course, StartTimeAccessorMutator)
{
  Course your_course;
  your_course.set_start_time(800);
  ASSERT_EQ(your_course.start_time(), 800);
}

TEST(Course, EndTimeAccessorMutator)
{
  Course your_course;
  your_course.set_end_time(920);
  ASSERT_EQ(your_course.end_time(), 920);
}

TEST(Course, Display)
{
  std::string expected_output =
      "Course name: CPSC 362\nLocation: CS 101\nWeekly schedule: MW\nStart "
      "time: 8:00\nEnd time: 9:50\n";
  Course your_course;
  your_course.set_course_name("CPSC 362");
  your_course.set_location("CS 101");
  your_course.set_weekly_schedule("MW");
  your_course.set_start_time(800);
  your_course.set_end_time(950);

  SIMULATE_SIO("", your_course.display(), {
    std::string your_function_output = your_output;
    ASSERT_EQ(your_function_output, expected_output);
  })
}

TEST_F(LoadSchedule, FileDoesntExist)
{
  std::string user_input = "nonexistent.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("does not exist"),
                                  HasSubstr("doesn't exist")),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file doesn't exist.";
          // Ensure no other errors are show
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("end time"), HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, NoLocation)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("location"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "location. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("weekly schedule"), HasSubstr("symbol"),
                        HasSubstr("start time"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, NoWeeklySchedule)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("weekly schedule"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "weekly schedule. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(your_function_output,
                      Not(AnyOf(HasSubstr("location"), HasSubstr("symbol"),
                                HasSubstr("start time"), HasSubstr("end time"),
                                HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, InvalidDay1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nX";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("weekly schedule symbol"), HasSubstr("X"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the weekly schedule "
                 "uses an "
                 "invalid symbol. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("start time"),
                        HasSubstr("end time"), HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, InvalidDay2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMWX";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("weekly schedule symbol"),
                            HasSubstr("MWX"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the weekly schedule "
                 "uses an "
                 "invalid symbol. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("start time"),
                        HasSubstr("end time"), HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, NoStartTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n1124";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("start time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, NoStartTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\nabcd";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("start time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, NoEndTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n11:30\n1124";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("end time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain an "
                 "end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, NoEndTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n8:35\nabcd";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("end time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain an "
                 "end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, InvalidStartTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n25:30";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("25:30"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("start time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, InvalidStartTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n15:88";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("15:88"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("start time")))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, InvalidEndTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n11:30\n100:25";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("100:25"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("end time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, InvalidEndTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n8:35\n12:999";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("12:999"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("end time")))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, StartLaterThanEnd)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSCC 121\nE202\nMW\n18:35\n11:30\n";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("18:35"), HasSubstr("11:30"),
                            HasSubstr("happen before"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file contains a "
                 "start time "
                 "that happens after the end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown

          ASSERT_THAT(
              your_function_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

// Test cases for schedule files with multiple schedules
TEST_F(LoadSchedule, MultSchedNoLocation)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 121\nE202\nMW\n11:30\n13:20\nCPSC 131";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("location"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "location. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("weekly schedule"), HasSubstr("symbol"),
                        HasSubstr("start time"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedNoWeeklySchedule)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("weekly schedule"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "weekly schedule. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(your_function_output,
                      Not(AnyOf(HasSubstr("location"), HasSubstr("symbol"),
                                HasSubstr("start time"), HasSubstr("end time"),
                                HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedInvalidDay1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nX";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("weekly schedule symbol"), HasSubstr("X"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the weekly schedule "
                 "uses an "
                 "invalid symbol. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("start time"),
                        HasSubstr("end time"), HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedInvalidDay2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMWX";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("weekly schedule symbol"),
                            HasSubstr("MWX"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the weekly schedule "
                 "uses an "
                 "invalid symbol. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("start time"),
                        HasSubstr("end time"), HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedNoStartTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n1124";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("start time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedNoStartTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\nabcd";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("start time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedNoEndTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n11:30\n1124";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("end time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain an "
                 "end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedNoEndTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n8:35\nabcd";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(AnyOf(HasSubstr("Unable"), HasSubstr("unable")),
                            HasSubstr("end time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain an "
                 "end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedInvalidStartTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n25:30";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();

  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("25:30"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("start time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedInvalidStartTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n15:88";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("15:88"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("start time")))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid start time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("end time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedInvalidEndTime1)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n11:30\n100:25";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("100:25"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("end time"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedInvalidEndTime2)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSC 121\nE202\nMW\n8:35\n12:999";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("12:999"),
                            AnyOf(HasSubstr("Invalid"), HasSubstr("invalid")),
                            HasSubstr("end time")))
              << "The function should show an error if the file does not "
                 "contain a "
                 "valid end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown
          ASSERT_THAT(
              your_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"), HasSubstr("start time"),
                        HasSubstr("happen before"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, MultSchedStartLaterThanEnd)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPS 131\nE101\nMW\n8:30\n11:20\nCPSCC 121\nE202\nMW\n18:35\n11:30\n";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO(
        "", function_result = load_schedule(user_input, courses, size), {
          std::string your_function_output = your_output;
          ASSERT_THAT(your_function_output,
                      AllOf(HasSubstr("18:35"), HasSubstr("11:30"),
                            HasSubstr("happen before"),
                            AnyOf(HasSubstr("Invalid file"),
                                  HasSubstr("invalid file"))))
              << "The function should show an error if the file contains a "
                 "start time "
                 "that happens after the end time. File contents:\n"
              << file_contents;
          // Ensure no other errors are shown

          ASSERT_THAT(
              your_function_output,
              Not(AnyOf(HasSubstr("location"), HasSubstr("weekly schedule"),
                        HasSubstr("symbol"))))
              << "The function should not show other errors";
        })
    ASSERT_FALSE(function_result)
        << "The function should return false because there are errors in the "
           "schedule file format.";
  })
}

TEST_F(LoadSchedule, ValidOneCourse)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents = "CPSC 131\nE101\nMW\n8:30\n11:20\n";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    function_result = load_schedule(user_input, courses, size);
    ASSERT_TRUE(function_result) << "The function should return true because "
                                    "the file is valid. File contents:\n"
                                 << file_contents;
    ASSERT_EQ(size, 1) << "The function should set size to 1, because there is "
                          "one course in the schedule. File contents:\n"
                       << file_contents;
    ASSERT_EQ(courses[0].course_name(), "CPSC 131")
        << "The course name of the first course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].location(), "E101")
        << "The location of the first course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].weekly_schedule(), "MW")
        << "The weekly schedule of the first course is incorrect. File "
           "contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].start_time(), 830)
        << "The start time of the first course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].end_time(), 1120)
        << "The end time of the first course is incorrect. File contents:\n"
        << file_contents;
  })
}

TEST_F(LoadSchedule, ValidMultiCourse)
{
  std::string user_input = "sched.txt";
  Course courses[100];
  int size = 0;
  bool function_result = true;

  std::string file_contents =
      "CPSC 131\nE101\nMW\n8:30\n11:20\nCPSC 481\nCS "
      "408\nMW\n16:00\n17:15\nCPSC 362\nCS 101\nMW\n8:00\n9:50";
  std::ofstream outfile("sched.txt");
  outfile << file_contents;
  outfile.close();
  ASSERT_DURATION_LE(3, {
    function_result = load_schedule(user_input, courses, size);
    ASSERT_TRUE(function_result) << "The function should return true because "
                                    "the file is valid. File contents:\n"
                                 << file_contents;
    ASSERT_EQ(size, 3)
        << "The function should set size to 3, because there are "
           "three courses in the schedule. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].course_name(), "CPSC 131")
        << "The course name of the first course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].location(), "E101")
        << "The location of the first course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].weekly_schedule(), "MW")
        << "The weekly schedule of the first course is incorrect. File "
           "contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].start_time(), 830)
        << "The start time of the first course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[0].end_time(), 1120)
        << "The end time of the first course is incorrect. File contents:\n"
        << file_contents;

    ASSERT_EQ(courses[1].course_name(), "CPSC 481")
        << "The course name of the second course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[1].location(), "CS 408")
        << "The location of the second course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[1].weekly_schedule(), "MW")
        << "The weekly schedule of the second course is incorrect. File "
           "contents:\n"
        << file_contents;
    ASSERT_EQ(courses[1].start_time(), 1600)
        << "The start time of the second course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[1].end_time(), 1715)
        << "The end time of the second course is incorrect. File contents:\n"
        << file_contents;

    ASSERT_EQ(courses[2].course_name(), "CPSC 362")
        << "The course name of the third course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[2].location(), "CS 101")
        << "The location of the third course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[2].weekly_schedule(), "MW")
        << "The weekly schedule of the third course is incorrect. File "
           "contents:\n"
        << file_contents;
    ASSERT_EQ(courses[2].start_time(), 800)
        << "The start time of the third course is incorrect. File contents:\n"
        << file_contents;
    ASSERT_EQ(courses[2].end_time(), 950)
        << "The end time of the third course is incorrect. File contents:\n"
        << file_contents;
  })
}

TEST(DisplayCourses, OneCourse)
{
  Course your_course;
  your_course.set_course_name("CPSC 362");
  your_course.set_location("CS 101");
  your_course.set_weekly_schedule("MW");
  your_course.set_start_time(800);
  your_course.set_end_time(950);

  Course course_array[1] = {your_course};

  std::string expected_output =
      "Course name: CPSC 362\nLocation: CS 101\nWeekly schedule: MW\nStart "
      "time: 8:00\nEnd time: 9:50\n\n";

  SIMULATE_SIO("", display_courses(course_array, 1), {
    std::string your_function_output = your_output;
    ASSERT_EQ(your_function_output, expected_output);
  })
}

TEST(DisplayCourses, MultiCourse)
{
  Course your_1st_course;
  your_1st_course.set_course_name("CPSC 131");
  your_1st_course.set_location("EC 109");
  your_1st_course.set_weekly_schedule("MW");
  your_1st_course.set_start_time(1600);
  your_1st_course.set_end_time(1715);

  Course your_2nd_course;
  your_2nd_course.set_course_name("CPSC 481");
  your_2nd_course.set_location("CS 408");
  your_2nd_course.set_weekly_schedule("MW");
  your_2nd_course.set_start_time(1600);
  your_2nd_course.set_end_time(1715);

  Course your_3rd_course;
  your_3rd_course.set_course_name("CPSC 362");
  your_3rd_course.set_location("CS 101");
  your_3rd_course.set_weekly_schedule("MW");
  your_3rd_course.set_start_time(800);
  your_3rd_course.set_end_time(950);

  Course course_array[3] = {your_1st_course, your_2nd_course, your_3rd_course};

  std::string expected_output =
      "Course name: CPSC 131\nLocation: EC 109\nWeekly schedule: MW\nStart "
      "time: 16:00\nEnd time: 17:15\n\nCourse name: CPSC 481\nLocation: CS "
      "408\nWeekly schedule: MW\nStart time: 16:00\nEnd time: 17:15\n\nCourse "
      "name: CPSC 362\nLocation: CS 101\nWeekly schedule: MW\nStart time: "
      "8:00\nEnd time: 9:50\n\n";

  SIMULATE_SIO("", display_courses(course_array, 3), {
    std::string your_function_output = your_output;
    ASSERT_EQ(your_function_output, expected_output);
  })
}


int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
