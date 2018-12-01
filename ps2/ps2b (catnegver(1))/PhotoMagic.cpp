#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "LFSR.hpp"

int main(int argc, char* argv[])
{
  std::string user_image1 = argv[1];
  std::string user_image2 = argv[2];
  
  
	sf::Image image1;
	if (!image1.loadFromFile(user_image1))
	  {
	    return -1;
	  }

	sf::Image image2;
	if (!image2.loadFromFile(user_image2))
	  {
	    return -1;
	  }

	// p is a pixel
	sf::Color p;
	sf::Color q;

	// create photographic negative image of upper-left 200 px square
       for (int x = 0; x<200; x++)
       {
       	for (int y = 0; y< 200; y++)
	  {
       		p = image1.getPixel(x, y);
       		p.r = 255 - p.r;
	       	p.g = 255 - p.g;
       		p.b = 255 - p.b;
	       	image1.setPixel(x, y, p);
	  }
	}

       for (int x = 0; x<200; x++)
       {
       	for (int y = 0; y< 200; y++)
	  {
       		q = image2.getPixel(x, y);
       		q.r = 255 - q.r;
	       	q.g = 255 - q.g;
       		q.b = 255 - q.b;
	       	image2.setPixel(x, y, q);
	  }
	}

	sf::Vector2u size = image1.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Encoded Image");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Decoded Image");

	sf::Texture texture1;
	texture1.loadFromImage(image1);
	
	sf::Texture texture2;
	texture2.loadFromImage(image2);

	
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
	
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);

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
	
	//   write the file
	if (!image1.saveToFile("encode.png"))
	  {
	    return -1;
	  }

	if (!image2.saveToFile("decode.png"))
	  {
	    return -1;
	  }

	return 0;
}
