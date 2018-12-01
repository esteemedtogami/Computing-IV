// Copyright 2017 Sam Pickell
#ifndef MARKOVMODEL_HPP
#define MARKOVMODEL_HPP

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

class MarkovModel {
 public:
  MarkovModel(std::string text, int k);
  ~MarkovModel();
  int order() {return private_order;}
  int freq(std::string kgram);
  int freq(std::string kgram, char c);
  char randk(std::string kgram);
  std::string gen(std::string kgram, int T);

  friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm);

 private:
  unsigned int private_order;
  std::map <std::string, int> kgrams;
  std::string alphabet;
};
#endif
