#include "Body.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  sf::Image backdrop;

  if(!backdrop.loadFromFile("starfield.jpg"))
    {
      return -1;
    }
  
  //Set up the universe
  std::vector<Body*> v_bodies;
  int number_of_bodies;
  double universe_size;
  sf::Vector2u size = backdrop.getSize();

  std::cin >> number_of_bodies;
  std::cin >> universe_size;


  //Create the celestial bodies and put them into the vector
  for(int i = 0; i < number_of_bodies; i++)
    {
      Body* body = new Body();
      v_bodies.push_back(body);
    }
  
  for(int i = 0; i < number_of_bodies; i++)
    {
      std::cin >> (*(v_bodies.at(i)));
      v_bodies.at(i)->set_radius(universe_size);
      v_bodies.at(i)->set_window(size.x);
      v_bodies.at(i)->update_pixel_pos();
    }
  
  sf::Texture texture_drop;
  texture_drop.loadFromImage(backdrop);

  sf::Sprite sprite_drop;
  sprite_drop.setTexture(texture_drop);
  
  
  sf::RenderWindow window(sf::VideoMode(size.x, size.y),
			  "NBody Program");
  
  while(window.isOpen())
    {
      sf::Event event;
      while(window.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	    {
	      window.close();
	    }
	}

      window.clear();
      window.draw(sprite_drop);
      for(int i = 0; i < number_of_bodies; i++)
	{
	  window.draw(*(v_bodies.at(i)));
	}
      window.display();
    }
  
  return 0;
}
