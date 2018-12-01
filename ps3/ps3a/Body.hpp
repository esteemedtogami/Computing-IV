#ifndef BODY_HPP
#define BODY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

class Body : public sf::Drawable
{
public:

  Body();
  Body(double x, double y, double vel_x, double vel_y, double user_mass,
       std::string u_filename);
  ~Body();

  //Accessors
  double get_xpos();
  double get_ypos();

  //Mutators
  void set_radius(double rad);
  void set_window(int size);

  void update_pixel_pos();

  friend std::istream& operator >> (std::istream &input, Body &B);
  
private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  
  double xpos, ypos, velocity_x, velocity_y, mass, univ_rad;
  sf::Texture texture;
  sf::Sprite sprite;
  int window_size;
  std::string filename;
  
};



#endif
