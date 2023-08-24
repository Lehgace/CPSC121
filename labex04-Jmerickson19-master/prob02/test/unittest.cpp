#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::Not;
using ::testing::MatchesRegex;

struct UserInput : public UnitTestFileManager {
    UserInput() : UnitTestFileManager("report.txt") { }
};

struct FileLoading : public UnitTestFileManager {
  FileLoading() : UnitTestFileManager("load_report.txt") { }
  void SetUp() override {
    UnitTestFileManager::SetUp();
    std::ofstream report_file;
    report_file.open("load_report.txt");
    report_file << 999.99 << "\n" << 705.67 << "\n" << 803.23 << "\n" 
                << 400.54 << "\n";
    report_file.close();
  }
};

TEST_F(UserInput, FileNameAndNumberOfMonths) {
  std::string user_input = "report.txt\n1\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the file name of the phonebook file and the number of months to consolidate.";
}

TEST_F(FileLoading, ConsolidateOne) {
  std::string user_input = "load_report.txt\n1\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("999.99"))
      << "      Your program should show the total sales of the first month, 999.99.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("705.67"))
      << "      Your program should show the total sales of the second month, 705.67.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("803.23"))
      << "      Your program should show the total sales of the third month, 803.23.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("400.54"))
      << "      Your program should show the total sales of the fourth month, 400.54.";      
  })
}

TEST_F(FileLoading, ConsolidateTwo) {
  std::string user_input = "load_report.txt\n2\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("1705.66"))
      << "      Your program should show the total sales of the first and second month, 1705.66.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("1203.77"))
      << "      Your program should show the total sales of the third and fourth month, 1203.77.";
  })
}

TEST_F(FileLoading, ConsolidateThree) {
  std::string user_input = "load_report.txt\n3\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("2508.89"))
      << "      Your program should show the total sales of the first, second, and third month, 2508.89.";
    ASSERT_EXECTHAT("main", user_input, Not(HasSubstr("400.54")))
      << "      Your program should should not show the total sales of the fourth month as it is outside of the three consolidated reports.";
  })
}

TEST(MissingFile, MissingFile) {
  std::ifstream user_file;
  std::string user_input = "missing_file.txt\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(Invalid|invalid|error|missing).*)"))
      << "      Your program should show an error message when it is asked to load a missing phonebook file.";
  })
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
