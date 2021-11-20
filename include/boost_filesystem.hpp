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

void parse_dir(const boost::filesystem::path& path_to_dir,
               std::ostream& outpt);

std::vector<std::string> parse_filename(std::string filename);

void print_dir_info(const boost::filesystem::path& path_to_dir,
                    std::ostream& outpt);

void print_broker_info(const std::vector<AccountInfo>& account_info,
                       std::ostream& outpt);

#endif  // INCLUDE_BOOST_FILESYSTEM_HPP_
