#include "LFSR.hpp"

LFSR::LFSR(std::string user_seed, int user_tap)
{
  tap = user_tap;
  seed = user_seed;
}

LFSR::~LFSR()
{

}

int LFSR::step()
{

  int bit;
  char c_bit;
  
  if (seed.at(0) == seed.at((seed.size()-1) - tap))
    {
      bit = 0;
      c_bit = '0';
    }
  else
    {
      bit = 1;
      c_bit = '1';
    }

  for(unsigned int i = 0; i < (seed.size()-1); i++)
    {
      seed.at(i) = seed.at(i+1);
    }
  seed.at(seed.size()-1) = c_bit;
  
  return bit;
}

int LFSR::generate(int k)
{
  int gen = 0;

  for (int i =0; i < k; i++)
    {
      gen = gen*2 + LFSR::step();
    }

  return gen;
}

std::ostream& operator<<(std::ostream &out,LFSR &lfsr)
{
  out << lfsr.seed;

  return out;
}
