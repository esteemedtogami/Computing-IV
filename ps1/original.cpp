#include "original.hpp"
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

std::vector <sf::ConvexShape> square_vector;
int count = 0;

original::original(int size, int depth)
{
    float original_height = size/2;
    //    original_depth = depth;
    //   original_size = size;
    
    
    sf::Vector2f p1, p2, p3, p4;
    p1.x = size *.4;
    p1.y = size *.35;
    p2.x = size*.4;
    p2.y = size*.55;
    p3.x = size*.6;
    p3.y = size*.55;
    p4.x = size*.6;
    p4.y = size*.35;
    
    //Set Initial Triangle
    sf::ConvexShape initial_square;
    initial_square.setPointCount(4);
    initial_square.setPoint(0, p1);
    initial_square.setPoint(1, p2);
    initial_square.setPoint(2, p3);
    initial_square.setPoint(3, p4);
    initial_square.setFillColor(sf::Color::Yellow);
    
    square_vector.push_back(initial_square);
    
    original(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y, depth, size, original_height);
    
}


original::original(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,
                   int depth, float size, float height)
{
        /*if (depth not reached)
         {
         child (top, midleft (w/4) (h/2), midright (3w/4)(h/2))
         child (midleft, left, middle (top w/2) (h))
         child (midright, middle, right)
         }
         else
         {
         build triangle with current data
         }
         */
    
    
    
        if (depth > 0)
        {
            depth--;
    
            original(x1/4, y1/4, x2/4, y2/4, x3/4, y3/4, x4/4, y4/4, depth, size, height);
            
            original((x1+size*.5)/1.9, y1/4, (x2+size*.5)/1.9, y2/4, (x3+size*.5)/2.1, y3/4, (x4+size*.5)/2.1, y4/4, depth, size, height);
            
            original((x1 * 2.2), y1/4, (x2 * 2.2), y2/4, (x3 * 1.56), y3/4, (x4 * 1.56), y4/4,
                     depth, size, height);
            
            original(x1/4, y1/4 + size*.63, x2/4, y2/4 + size*.63, x3/4, y3/4 + size*.63, x4/4,
                     y4/4 + size*.63, depth, size, height);
            
            original((x1+size*.5)/1.9, y1/4 + size*.63, (x2+size*.5)/1.9, y2/4 + size*.63, (x3+size*.5)/2.1, y3/4 + size*.63, (x4+size*.5)/2.1, y4/4 + size*.63, depth, size, height);
            
            original((x1 * 2.2), y1/4 + size*.63, (x2 * 2.2), y2/4 + size*.63, (x3 * 1.56), y3/4 + size*.63, (x4 * 1.56), y4/4 + size*.63, depth, size, height);
            
            original(x1/4, y1/4 + size*.33, x2/4, y2/4 + size*.33, x3/4, y3/4 + size*.33, x4/4,
                     y4/4 + size*.33, depth, size, height);
            
            original((x1 * 2.2), y1/4 + size*.33, (x2 * 2.2), y2/4 + size*.33, (x3 * 1.56), y3/4 + size*.33, (x4 * 1.56), y4/4 + size*.33, depth, size, height);
            
    
        }
        else
        {
            sf::Vector2f p1, p2, p3, p4;
            p1.x = x1;
            p1.y = y1;
            p2.x = x2;
            p2.y = y2;
            p3.x = x3;
            p3.y = y3;
            p4.x = x4;
            p4.y = y4;
            
            //Set Initial Triangle
            sf::ConvexShape initial_square;
            initial_square.setPointCount(4);
            initial_square.setPoint(0, p1);
            initial_square.setPoint(1, p2);
            initial_square.setPoint(2, p3);
            initial_square.setPoint(3, p4);
            initial_square.setFillColor(sf::Color::Yellow);
            
            square_vector.push_back(initial_square);
        }
}


original::~original()
{
    
}


void original::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(unsigned int i = 0; i < square_vector.size(); i++)
    {
        target.draw(square_vector.at(i), states);
    }
}




