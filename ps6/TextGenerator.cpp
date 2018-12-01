// Copyright 2017 Sam Pickell
#include <cstdlib>
#include <string>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
  int k, T;
  std::string my_string;

  k = atoi(argv[1]);
  T = atoi(argv[2]);
  std::cin >> my_string;

  MarkovModel MM(my_string, k);

  std::cout << MM.gen(my_string.substr(0, k), T) << std::endl;
  return 0;
}
