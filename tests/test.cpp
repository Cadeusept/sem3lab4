// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <boost_filesystem.hpp>
#include <stdexcept>

TEST(Equality, parse_filename_1) {
    const boost::filesystem::path x{"balance_00122223_20180903.old"};
    std::vector<std::string> parsed;
    parsed = parse_filename(x.filename().string());

    EXPECT_EQ(parsed.size(),4);
    EXPECT_EQ(parsed[0],"balance");
    EXPECT_EQ(parsed[1],"00122223");
    EXPECT_EQ(parsed[2],"20180903");
    EXPECT_EQ(parsed[3],"old");
}

TEST(Equality, parse_filename_2) {
    const boost::filesystem::path x{"balance_00122223_20180903"};
    std::vector<std::string> parsed;
    parsed = parse_filename(x.filename().string());

    EXPECT_EQ(parsed.size(),3);
    EXPECT_EQ(parsed[0],"balance");
    EXPECT_EQ(parsed[1],"00122223");
    EXPECT_EQ(parsed[2],"20180903");
}
