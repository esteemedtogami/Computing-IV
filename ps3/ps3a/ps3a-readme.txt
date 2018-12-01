/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Sam Pickell
OS: Ubuntu 16.04
Machine (e.g., Dell Latitude, MacBook Pro): MacBook Pro
Text editor: emacs
Hours to complete assignment (optional): 7 hours 23 minutes

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
**********************************************************************/

In main.cpp:

//This is where the body object's data is set up. For each body object,
//   a line of data is read in via the overloaded insertion operator,
//   the object then gains the neccessary universe and screen sizes,
//   and then the object is moved to the correct location on the
//   screen based on scaled coordinates

  for(int i = 0; i < number_of_bodies; i++)
    {
      std::cin >> (*(v_bodies.at(i)));
      v_bodies.at(i)->set_radius(universe_size);
      v_bodies.at(i)->set_window(size.x);
      v_bodies.at(i)->update_pixel_pos();
    }



In Body.cpp:

//This is how the sprite is placed in the correct location. The x and
//   y coordinates are based on the percentage of the celestial body's
//   coordinates divided by the diameter of the universe. Then that
//   percentage is used to place the sprite based on that percentage
//   of the window's size.

void Body::update_pixel_pos()
{
  double percent_x, percent_y;

  percent_x = (xpos + univ_rad) / (2 * univ_rad);
  percent_y = (ypos + univ_rad) / (2 * univ_rad);

  sprite.setPosition((window_size * percent_x),
		     ((window_size * percent_y)));
}

//This is how the insertion operater was overloaded. The data is
//   placed into the private variables and, since the object did
//   not utilize the constructor that accepts this data when it
//   was made, the sprite is made based on the input data.

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



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

I worked with Zixin Wang on this homework.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

No serious problems occurred.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
