// Copyright 2021 Your Name <your_email>

#include <boost_filesystem.hpp>

std::vector<std::string> parse_filename(std::string filename){
  std::vector<std::string> parsed;
  std::stringstream strs(filename);
  std::string word;
  while(std::getline(strs, word, '_'))
  {
    parsed.push_back(word);
  }
  return parsed;
}
