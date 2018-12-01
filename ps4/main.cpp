#include "Editdistance.hpp"
#include <SFML/System.hpp>

int main(int argc, char* argv[])
{
  sf::Clock clock;
  sf::Time t;
  std::string test_1, test_2, align;

  std::cin >> test_1;
  std::cin >> test_2;

  EditDistance ED(test_1, test_2);
  
  int opt = ED.OptDistance();

  std::cout << "Edit distance = " << opt << std::endl;

  align = ED.Alignment();

  std::cout << align;

  t = clock.getElapsedTime();

  std::cout << "Execution time is: " << t.asSeconds() << std::endl;
  
  return 0;
}
