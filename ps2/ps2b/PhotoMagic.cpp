#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include "LFSR.hpp"

void transform_method(sf::Image& image, sf::Color p, sf::Vector2u size, LFSR l);

int main(int argc, char* argv[])
{ 
        //Read in Command Line Arguments
        std::string user_image1 = argv[1];
        std::string user_image2 = argv[2];
	int tap = atoi(argv[4]);
	LFSR l(argv[3], tap);

        //Load Images
	sf::Image image;
        sf::Image image1;
	if (!image.loadFromFile(user_image1))
	  {
	    return -1;
	  }
	if (!image1.loadFromFile(user_image1))
	  {
	    return -1;
	  }

	//Create pixel variable
	sf::Color p;

	//Set Size
	sf::Vector2u size = image1.getSize();

	//Transform the Images
	transform_method(image1, p, size, l);

	//Save Image
	if (!image1.saveToFile(user_image2))
	  {
	    return -1;
	  }

	//After transform
	sf::Image image2;
	if (!image2.loadFromFile(user_image2))
	  {
	    return -1;
	  }

	//Generate Windows
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");

	//Load Textures
	sf::Texture texture1;
	texture1.loadFromImage(image);
	sf::Texture texture2;
	texture2.loadFromImage(image2);

	//Set Sprites
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
	
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

	

	//Generate Windows
	while (window1.isOpen() && window2.isOpen())
	{
		sf::Event event;
		while (window1.pollEvent(event))
		{
		    if (event.type == sf::Event::Closed)
		      {
			window1.close();
		      }
		}

		while (window2.pollEvent(event))
		{
		    if (event.type == sf::Event::Closed)
		      {
			window2.close();
		      }
		}

		window1.clear(sf::Color::White);
		window1.draw(sprite1);
		window1.display();

		window2.clear(sf::Color::White);
		window2.draw(sprite2);
		window2.display();
	}

	return 0;
}

void transform_method(sf::Image& image, sf::Color p, sf::Vector2u size, LFSR l)
{
  for (unsigned int x = 0; x<size.x; x++)
  {
    for (unsigned int y = 0; y< size.y; y++)
      {
	int new_bit1, new_bit2, new_bit3;

	new_bit1 = l.generate(8);
	new_bit2 = l.generate(8);
	new_bit3 = l.generate(8);
	
	p = image.getPixel(x, y);
       	p.r = p.r ^ new_bit1;
	p.g = p.g ^ new_bit2;
       	p.b = p.b ^ new_bit3;
	image.setPixel(x, y, p);
      }
  }
}
