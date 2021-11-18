#include <string>
#include <iostream>
#include <vector>

#include <boost/filesystem.hpp>
#include "boost_filesystem.hpp"

int main() {
  boost::filesystem::path path_to_ftp;
  std::vector<size_t> kols;
  std::vector<size_t> lastdates;
  std::string dirname;
  std::vector<size_t> accounts;
  for (const boost::filesystem::directory_entry& x :
       boost::filesystem::directory_iterator{path_to_ftp})
  {

    if (boost::filesystem::is_directory(x.path()))
    {
      if (!dirname.empty())
      {
        for (size_t i = 0; i < accounts.size(); i++)
        {
          std::cout << "broker:" << dirname << " account:" << accounts[i]
                    << " files:" << kols[i] << " lastdate:" << lastdates[i];
        }

      }
    }

    dirname=x.path().stem().string();

    if (is_regular_file(x.path()))
    {
      std::vector<std::string> parsed;
      parsed = parse_filename(x.path().filename().string());
      size_t account = std::stoi(parsed[1]);
      bool flag=false;
      for (size_t saved_account : accounts)
      {
        if (account==saved_account)
        {
          flag=true;
        }
      }

      if (!flag)
      {
        accounts.push_back(account);
      }

      size_t filedate = std::stoi(parsed[2]);

      if (x.path().extension().string() == "txt" && parsed[0] == "balance" &&
          parsed[1].length() == 8 && parsed[2].length() == 8)
      {
        kols[accounts.size() - 1]++;
        if (lastdates[accounts.size() - 1] < filedate)
          lastdates[accounts.size() - 1] = filedate;
      }
    }
  }
}