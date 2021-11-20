// Copyright 2021 Your Name <your_email>

#include <boost_filesystem.hpp>

std::vector<std::string> parse_filename(std::string filename){
  std::vector<std::string> parsed;
  filename += "_";
  for (int i = 0; i < 3; ++i) {
    parsed.push_back(filename.substr(0, filename.find('_')));
    filename=filename.substr(filename.find('_') + 1);
  }
  if (parsed[2].find('.') != std::string::npos) {
    parsed.push_back(parsed[2].substr(parsed[2].find('.')+1));
    parsed[2] = parsed[2].substr(0, parsed[2].find('.'));
  }

  return parsed;
}

void parse_dir(const boost::filesystem::path& path_to_dir, std::ostream& outpt) {
  std::vector<AccountInfo> account_info;
  std::string dirname = path_to_dir.stem().string();

  for (const boost::filesystem::directory_entry& x :
       boost::filesystem::directory_iterator{path_to_dir}) {
    if (boost::filesystem::is_directory(x.path())) {
      parse_dir(x.path(), outpt);
    }

    if (boost::filesystem::is_regular_file(x.path())) {
      std::vector<std::string> parsed;
      parsed = parse_filename(x.path().stem().string());
      if (parsed.size() == 3 && parsed[0] == "balance" &&
          parsed[1].length() == 8 && parsed[2].length() == 8 &&
          std::stoi(parsed[2].substr(4, 2)) <= 12 &&
          std::stoi(parsed[2].substr(6, 2)) <= 31 &&
          x.path().extension().string() == ".txt")
      {
        size_t account = std::stoi(parsed[1]);
        size_t filedate = std::stoi(parsed[2]);

        int flag = -1;
        for (unsigned long i = 0; i < account_info.size(); ++i) {
          if (dirname == account_info[i].dirname && account == account_info[i].account) {
            flag = i;
          }
        }

        if (flag == -1) {
          AccountInfo new_struct;
          new_struct.account = account;
          new_struct.kol = 1;
          new_struct.lastdate = filedate;
          new_struct.dirname = dirname;
          account_info.push_back(new_struct);
          //flag = account_info.size() - 1;
        }else{
          account_info[flag].kol++;
          account_info[flag].lastdate =
              std::max(account_info[flag].lastdate, filedate);
        }
      }
    }
  }
  if (!account_info.empty()) {
    print_broker_info(account_info, outpt);
  }
}

void print_dir_info(const boost::filesystem::path& path_to_dir, std::ostream& outpt) {
  for (const boost::filesystem::directory_entry& x :
    boost::filesystem::directory_iterator{path_to_dir}) {
    if (boost::filesystem::is_directory(x.path())) {
      print_dir_info(x.path(), outpt);
    }
    if (boost::filesystem::is_regular_file(x.path())) {
      std::vector<std::string> parsed;
      parsed = parse_filename(x.path().stem().string());
      if (parsed.size() == 3 && parsed[0] == "balance" &&
          parsed[1].length() == 8 && parsed[2].length() == 8 &&
          std::stoi(parsed[2].substr(4, 2)) <= 12 &&
          std::stoi(parsed[2].substr(6, 2)) <= 31 &&
          x.path().extension().string() == ".txt") {

        outpt << path_to_dir.stem().string() << " "
                  << x.path().filename().string() << std::endl;
      }
    }
  }
}

void print_broker_info(const std::vector<AccountInfo>& account_info,
                       std::ostream& outpt) {
  for (auto & i : account_info){
    outpt << "broker:" << i.dirname
              << " account:" << i.account
              << " files:" << i.kol
              << " lastdate:" << i.lastdate
            << std::endl;
  }
}
