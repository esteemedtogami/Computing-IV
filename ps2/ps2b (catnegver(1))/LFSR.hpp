#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <string>

class LFSR
{
  
public:
  LFSR(std::string user_seed, int user_tap);
  ~LFSR();
  int step();
  int generate(int k);

  friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);

private:
  std::string seed;
  int tap;
  
};


#endif
