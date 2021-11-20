#include "boost_filesystem.hpp"

int main() {
  const boost::filesystem::path path_to_ftp{FTP_DIR};
  print_dir_info(path_to_ftp,std::cout);
  parse_dir(path_to_ftp,std::cout);
}