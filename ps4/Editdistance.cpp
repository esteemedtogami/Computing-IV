#include "Editdistance.hpp"

EditDistance::EditDistance(std::string string_1, std::string string_2)
{
  x = string_1;
  y = string_2;
  x.append("-");
  y.append("-");
  
  std::vector< std::vector< int > > my_data(string_2.size() + 1,
		 std::vector<int> (string_1.size() + 1, -1));
  data = my_data;
}

EditDistance::~EditDistance()
{

}

int EditDistance::penalty(char a, char b)
{
  if(a == b)
    {
      return 0;
    }
  else if ((a != b) && (a == '-' || b == '-'))
    {
      return 2;
    }
  else
    {
      return 1;
    }
}

int EditDistance::min(int a, int b, int c)
{
  if(a <= b)
    {
      if(a <= c)
	{
	  return a;
	}
      else
	{
	  return c;
	}
    }
  else
    {
      if(b <= c)
	{
	  return b;
	}
      else
	{
	  return c;
	}
    }
}

int EditDistance::OptDistance()
{
  // This handles the outsides
  int count = 0;
  for(int i = x.size() - 1; i >= 0; i--)
    {
      
      data.at(y.size() - 1).at(i) = count;
      count += 2;
    }
  count = 0;
  for(int i = y.size() - 1; i >= 0; i--)
    {
      data.at(i).at(x.size() - 1) = count;
      count += 2;
    }

  //this handles the inside
  for(int i = x.size() - 2; i >= 0; i--)
    {
     
      for(int j = y.size() - 2; j >= 0; j--)
	{
	  data.at(j).at(i) = min(
	      data.at(j+1).at(i+1) + penalty(x.at(i), y.at(j)),
	      data.at(j).at(i+1) + 2,
	      data.at(j+1).at(i) + 2);
	}
    }
  
 
  return data.at(0).at(0);
}

std::string EditDistance::Alignment()
{
  std::string z;
  unsigned int i = 0;
  unsigned int j = 0;
  
  while(i < y.size() -1 && j < x.size() - 1)
  {
    if(data.at(i).at(j) == data.at(i+1).at(j+1) + penalty(x.at(j),y.at(i)))
    {
      z.push_back(x.at(j));
      z.push_back(' ');
      z.push_back(y.at(i));
      z.push_back(' ');
      z.push_back(penalty(x.at(j),y.at(i)) + '0');
      z.push_back('\n');
      i++;
      j++;
    }
    else if(data.at(i).at(j) ==  data.at(i).at(j+1) +2)
    {
      z.push_back(x.at(j));
      z.push_back(' ');
      z.push_back('-');
      z.push_back(' ');
      z.push_back('2');
      z.push_back('\n');
      j++;
    }
    else if(data.at(i).at(j) ==  data.at(i+1).at(j) +2)
    {
      z.push_back('-');
      z.push_back(' ');
      z.push_back(y.at(i));
      z.push_back(' ');
      z.push_back('2');
      z.push_back('\n');
      i++;
    }
  }
  
  if(j <x.size())
  {
      z.push_back(x.at(j));
      z.push_back(' ');
      z.push_back('-');
      z.push_back(' ');
      z.push_back('2');
      z.push_back('\n');
      j++;
  }
  else if(i < y.size())
  {
      z.push_back('-');
      z.push_back(' ');
      z.push_back(y.at(i));
      z.push_back(' ');
      z.push_back('2');
      z.push_back('\n');
      i++;
   }
  
  return z;
}
