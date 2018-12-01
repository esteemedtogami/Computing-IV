#include "Body.hpp"
#include <cstdlib>

Body::Body()
{

}

Body::Body(double x, double y, double vel_x, double vel_y,
	   double user_mass, std::string u_filename)
{
  //initialize variables
  xpos = x;
  ypos = y;
  velocity_x = vel_x;
  velocity_y = vel_y;
  mass = user_mass;
  filename = u_filename;

  //Load image
  sf::Image image;
  if(!image.loadFromFile(filename))
    {
      exit(1);
    }

  texture.loadFromImage(image);
  sprite.setTexture(texture);
}

Body::~Body()
{


}

double Body::get_xpos()
{
  return xpos;
}

double Body::get_ypos()
{
  return ypos;
}

void Body::set_radius(double rad)
{
  univ_rad = rad;
}

void Body::set_window(int size)
{
  window_size = size;
}

void Body::update_pixel_pos()
{
  double percent_x, percent_y;

  percent_x = (xpos + univ_rad) / (2 * univ_rad);
  percent_y = (ypos + univ_rad) / (2 * univ_rad);

  sprite.setPosition((window_size * percent_x),
		     ((window_size * percent_y)));
}

std::istream& operator >> (std::istream &input, Body &B)
{
  input >> B.xpos >> B.ypos >> B.velocity_x >> B.velocity_y >>
    B.mass >> B.filename;

  //Load image
  sf::Image image;
  if(!image.loadFromFile(B.filename))
    {
      exit(1);
    }

  B.texture.loadFromImage(image);
  B.sprite.setTexture(B.texture);


  
  return input;
}

void Body::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(sprite, states);
}
