#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

struct UserInput : public UnitTestFileManager {
    UserInput() : UnitTestFileManager("donations.txt") { }
};

struct FileCreation : public UnitTestFileManager {
  FileCreation() : UnitTestFileManager("create_file_donations.txt") { }
};

TEST_F(UserInput, DonorNumbersAndDonations) {
  std::string user_input = "1\ndonations.txt\n35\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number of donors, the file name to store information, and the donations.";
}

TEST_F(FileCreation, CreatedFile) {
  std::ifstream user_file;
  std::string user_input = "1\ncreate_file_donations.txt\n35.00\n";
  ASSERT_DURATION_LE(3, {
    exec_program("main", user_input);  
  })
  
  user_file.open("create_file_donations.txt");
  ASSERT_TRUE(user_file.good()) << "      Your program should create a file using the filename provided by the user. In this case, create_file_donations.txt.";
}

TEST_F(FileCreation, OneDonor) {
  std::ifstream user_file;
  std::string user_input = "1\ncreate_file_donations.txt\n35.00\n";
  ASSERT_DURATION_LE(3, {
    exec_program("main", user_input);  
  })
  
  user_file.open("create_file_donations.txt");
  ASSERT_TRUE(user_file.good()) << "      Your program should create a file using the filename provided by the user. In this case, create_file_donations.txt.";
  
  int num_donors = 0;
  double donation = 0;

  user_file >> num_donors;
  user_file >> donation;

  user_file.close();

  ASSERT_EQ(num_donors, 1) << "      Your program should store 1, indicating there is only one donor.";
  ASSERT_EQ(donation, 35.00) << "      Your program should store 35.00 as the donation amount.";
}

TEST_F(FileCreation, MultipleDonations) {
  std::ifstream user_file;
  std::string user_input = "3\ncreate_file_donations.txt\n35.00\n500.00\n235.10";
  ASSERT_DURATION_LE(3, {
    exec_program("main", user_input);  
  })
  
  user_file.open("create_file_donations.txt");
  ASSERT_TRUE(user_file.good()) << "      Your program should create a file using the filename provided by the user. In this case, create_file_donations.txt.";

  int num_donors = 0;
  double donation1 = 0, donation2 = 0, donation3 = 0;

  user_file >> num_donors;
  user_file >> donation1;
  user_file >> donation2;
  user_file >> donation3;

  user_file.close();

  ASSERT_EQ(num_donors, 3) << "      Your program should store 3, indicating there are three donors.";
  ASSERT_EQ(donation1, 35.00) << "      Your program should store 35.00 as the first donation amount.";
  ASSERT_EQ(donation2, 500.00) << "      Your program should store 500.00 as the second donation amount.";
  ASSERT_EQ(donation3, 235.10) << "      Your program should store 235.10 as the third donation amount.";
}

TEST_F(FileCreation, NoDonation) {
  std::ifstream user_file;
  std::string user_input = "0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((at least one)|error|(more than)|(greater than)).*)"))
      << "      Your program should show an error message when the phonebook file does not contain any contacts.";
  })
  
  user_file.open("create_file_donations.txt");
  ASSERT_FALSE(user_file.good()) << "      Your program should not create a file nor ask for the filename from the user because there are no reported donors.";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
