#include "boost_filesystem.hpp"

int main() {
  const boost::filesystem::path path_to_ftp{FTP_DIR};
  print_dir(path_to_ftp);
  parse_dir(path_to_ftp);
}