// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <boost_filesystem.hpp>
#include <stdexcept>

TEST(Equality, parse_filename_1) {
    std::vector<std::string> parsed;
    parsed = parse_filename("balance_00122223_20180903.old");

    EXPECT_EQ(parsed.size(),4);
    EXPECT_EQ(parsed[0],"balance");
    EXPECT_EQ(parsed[1],"00122223");
    EXPECT_EQ(parsed[2],"20180903");
    EXPECT_EQ(parsed[3],"old");
}

TEST(Equality, parse_filename_2) {
    std::vector<std::string> parsed;
    parsed = parse_filename("balance_00122223_20180903");

    EXPECT_EQ(parsed.size(),3);
    EXPECT_EQ(parsed[0],"balance");
    EXPECT_EQ(parsed[1],"00122223");
    EXPECT_EQ(parsed[2],"20180903");
}

TEST(Eqiality, print_broker_info) {
    std::vector<AccountInfo> account_info;
    std::stringstream ss;

    AccountInfo new_struct;
    new_struct.account=14882281;
    new_struct.kol=1;
    new_struct.lastdate=20181110;
    new_struct.dirname="test";
    account_info.push_back(new_struct);

    new_struct.account=18228841;
    new_struct.kol=3;
    new_struct.lastdate=20140911;
    new_struct.dirname="test";
    account_info.push_back(new_struct);

    print_broker_info(account_info, ss);
    EXPECT_EQ(ss.str(),
              "broker:test account:14882281 files:1 lastdate:20181110\n"
              "broker:test account:18228841 files:3 lastdate:20140911\n");

}

TEST(Equality, parse_dir) {
    const boost::filesystem::path testpath{TEST_DIRS"test_1"};
    std::stringstream ss;
    print_dir_info(testpath,ss);
    parse_dir(testpath,ss);
    EXPECT_EQ(ss.str(),
              "bcs balance_00122223_20181003.txt\n"
              "bcs balance_00123456_20180902.txt\n"
              "bcs balance_00122223_20181001.txt\n"
              "bcs balance_00123456_20181003.txt\n"
              "bcs balance_00123456_20180903.txt\n"
              "bcs balance_00123456_20181002.txt\n"
              "bcs balance_00122223_20181002.txt\n"
              "bcs balance_00123456_20181001.txt\n"
              "bcs balance_00123456_20180901.txt\n"
              "bcs balance_00122223_20180901.txt\n"
              "broker:bcs account:122223 files:4 lastdate:20181003\n"
              "broker:bcs account:123456 files:6 lastdate:20181003\n");
}
