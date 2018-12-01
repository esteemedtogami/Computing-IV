#ifndef EDITDISTANCE_HPP
#define EDITDISTANCE_HPP

#include <string>
#include <vector>
#include <iostream>

class EditDistance
{
 public:
  EditDistance(std::string string_1, std::string string_2);
  ~EditDistance();
  int penalty(char a, char b);
  int min(int a, int b, int c);
  int OptDistance();
  std::string Alignment();

 private:
  std::vector< std::vector< int > > data;
  std::string x, y;
};
#endif
