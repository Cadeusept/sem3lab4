// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_BOOST_FILESYSTEM_HPP_
#define INCLUDE_BOOST_FILESYSTEM_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include <boost/filesystem.hpp>

struct AccountInfo
{
  size_t kol;
  size_t lastdate;
  std::string dirname;
  size_t account;
};

void parse_dir(boost::filesystem::path path_to_dir);

std::vector<std::string> parse_filename(std::string filename);

void print_dir(boost::filesystem::path path_to_dir);

void print_broker_info(std::vector<AccountInfo> account_info);

#endif // INCLUDE_EXAMPLE_HPP_
