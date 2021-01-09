// Copyright 2020 Kushpelev Alexei leha.kushpelev@mail.ru

#ifndef INCLUDE_VIEWDIRECTORY_HPP_
#define INCLUDE_VIEWDIRECTORY_HPP_

#include <boost/filesystem.hpp>
#include <iomanip>
#include <iostream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace fs = boost::filesystem;

class ViewDirectory {
 public:
  explicit ViewDirectory(const std::string& path);
  std::stringstream PrintFiles();
  std::stringstream PrintAccounts() const;

 private:
  fs::path pathFTP;
  std::set<std::string> accounts;
  std::vector<fs::path> paths;
};

#endif  // INCLUDE_VIEWDIRECTORY_HPP_
