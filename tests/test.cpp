// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include "ViewDirectory.hpp"

std::string CurrentDir(const std::string& name) {
  std::string s(__FILE__);
  for (size_t i = 0; i < 8; ++i) {
    s.pop_back();
  }
  return s + name;
}
TEST(ViewDirectory, CorrectPrintFilesAndAccountsEmptyPath) {
  ViewDirectory vd("");
  std::stringstream ss1 = vd.PrintFiles();
  std::stringstream ss2 = vd.PrintAccounts();
  EXPECT_EQ(ss1.str(), "");
  EXPECT_EQ(ss2.str(), "");
}
TEST(ViewDirectory, CorrectPrintFilesAndAccountsFirstTest) {
  std::string path(CurrentDir("FirstTest"));
  ViewDirectory vd(path);
  std::stringstream ss1 = vd.PrintFiles();
  std::stringstream ss2 = vd.PrintAccounts();
  EXPECT_EQ(ss1.str(), "ib balance_00122223_20180902.txt\n");
  EXPECT_EQ(ss2.str(),
            "broker:ib account:00122223 files:1 lastdate:20180902\n");
}
TEST(ViewDirectory, CorrectPrintFilesAndAccountsSecondTest) {
  std::string path(CurrentDir("SecondTest"));
  ViewDirectory vd(path);
  std::stringstream ss1 = vd.PrintFiles();
  std::stringstream ss2 = vd.PrintAccounts();
  EXPECT_EQ(ss1.str(),
            "bcs balance_00122223_20180901.txt\n"
            "otkr balance_03934535_20180901.txt\n"
            "otkr balance_03934535_20180903.txt\n");
  EXPECT_EQ(ss2.str(),
            "broker:bcs account:00122223 files:1 lastdate:20180901\n"
            "broker:otkr account:03934535 files:2 lastdate:20180903\n");
}
TEST(ViewDirectory, CorrectPrintFilesAndAccountsThirdTest) {
  std::string path(CurrentDir("ThirdTest"));
  ViewDirectory vd(path);
  std::stringstream ss1 = vd.PrintFiles();
  std::stringstream ss2 = vd.PrintAccounts();
  EXPECT_EQ(ss1.str(), "ib balance_00122223_20180902.txt\n");
  EXPECT_EQ(ss2.str(),
            "broker:ib account:00122223 files:1 lastdate:20180902\n");
}
