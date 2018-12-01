#include "sierpinski.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    /*
    if (argc < 3 || argc > 4)
    {
        std::cout << "Sierpinski [recursion-depth] [side-length]" << std::endl;
        return -1;
    }
    
    int depth = atoi(argv[1]);
    int side = atoi(argv[2]);
     */
    
    int depth;
    int side;
    
    std::cout << "Enter depth: ";
    std::cin >> depth;
    std::cout << "Enter side: ";
    std::cin >> side;
    
    if (argc < 3 || argc > 4)
    {
        std::cout << "Sierpinski [side-length] [recursion-depth]" << std::endl;
        return -1;
    }
    
    std::cout << "Depth: " << depth << std::endl;
    std::cout << "Side: " << side << std::endl;
    
    if (depth < 0)
    {
        std::cout << "Depth should be greater than 0" << std::endl;
    }
    
    Sierpinski obj(side, depth);
    
    
    int window_height = (int)(.5*sqrt(3.)*(float)side);
    
    sf::RenderWindow window(sf::VideoMode(side, window_height), "Sierpinski");
    
    window.setFramerateLimit(1);
    
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
        window.draw(obj);
        window.display();
    }
    
    return 0;
}
