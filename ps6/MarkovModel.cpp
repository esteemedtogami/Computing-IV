// Copyright 2017 Sam Pickell
#include <cstdlib>
#include <vector>
#include <ctime>
#include <map>
#include <string>
#include "MarkovModel.hpp"

MarkovModel::MarkovModel(std::string text, int k) {
  unsigned int i;
  std::string kgram;

  for (i = 0; i < text.size() - k; i++) {
      kgram = text.substr(i, k);
      kgrams[kgram]++;
      // look for a new character. If found, add to our alphabet string
      std::size_t my_char = alphabet.find(text.at(i));
      if (my_char == std::string::npos) {
            alphabet.push_back(text.at(i));
      }
      kgram.push_back(text.at(i+k));
      kgrams[kgram]++;
  }
  for (unsigned int j = i; j <= text.size() - 1; j++) {
      int l;
      kgram = text.substr(j, text.size() - j);
      l = k - (text.size() - j);
      kgram.append(text.substr(0, l));
      kgrams[kgram]++;
      // look for a new character. If found, add to our alphabet string
      std::size_t my_char = alphabet.find(text.at(i));
      if (my_char == std::string::npos) {
            alphabet.push_back(text.at(i));
        }
      kgram.push_back(text.at(l));
      kgrams[kgram]++;
    }

  private_order = k;
}

MarkovModel::~MarkovModel() {
}

int MarkovModel::freq(std::string kgram) {
  if (kgram.size() != private_order) {
       throw std::runtime_error(
            "freq: kgram is not of length k!");
    } else {
    return kgrams[kgram];
    }
}

int MarkovModel::freq(std::string kgram, char c) {
  if (kgram.size() != private_order) {
       throw std::runtime_error(
            "freq: kgram is not of length k!");
    } else {
       if (private_order == 0) {
           std::string adv_c;
           adv_c.push_back(c);
           return kgrams[adv_c];
         } else {
           kgram.push_back(c);
           return kgrams[kgram];
         }
    }
}

char MarkovModel::randk(std::string kgram) {
  if (kgram.size() != private_order) {
       throw std::runtime_error(
            "randk: kgram is not of length k!");
  } else if (!kgrams[kgram]) {
       throw std::runtime_error(
            "randk: kgram does not exist!");
  } else {
    std::vector<char> my_vector;
    srand(time(NULL));
    unsigned int random_var = (rand() % freq(kgram)); // NOLINT
    for (unsigned int i = 0; i < alphabet.size(); i++) {
        int my_freq = freq(kgram, alphabet.at(i));
        if (my_freq >= 1) {
            for (int j = 0; j < my_freq; j++) {
              my_vector.push_back(alphabet.at(i));
              }
          }
      }
    return my_vector.at(random_var);
    }
}

std::string MarkovModel::gen(std::string kgram, int T) {
  std::string ret_string = kgram;
  int i = 0;
  while (ret_string.size() < (static_cast<unsigned int>(T))) {
      std::string temp;
      char c;
      temp = ret_string.substr(i, private_order);
      c = randk(temp);
      ret_string.push_back(c);
      i++;
    }
  return ret_string;
}

std::ostream& operator<< (std::ostream &out, MarkovModel &mm) {
  for (std::map<std::string, int>::iterator p = mm.kgrams.begin();
      p != mm.kgrams.end(); p++) {
      out << p->first << '-' << p->second << std::endl;
    }
  out << "Order: " << mm.private_order << std::endl;
  out << "Alphabet: " << mm.alphabet << std::endl;
  return out;
}
