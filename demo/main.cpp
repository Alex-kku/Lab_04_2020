// Copyright 2020 Kushpelev Alexei leha.kushpelev@mail.ru

#include "ViewDirectory.hpp"

int main() {
  ViewDirectory vd("/home/baha/Alex-kku/workspace/projects/C++/lab-04-boost-filesystem/misc/ftp");
  std::cout<<vd.PrintFiles().str();
  std::cout<<vd.PrintAccounts().str();
  return 0;
}