// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <boost_filesystem.hpp>
#include <stdexcept>

TEST(Example, EmptyTest) {
    EXPECT_THROW(example(), std::runtime_error);
}
