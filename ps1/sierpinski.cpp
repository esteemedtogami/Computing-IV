#include "sierpinski.hpp"
#include <cmath>
#include <iostream>

std::vector <sf::ConvexShape> triangle_vector;
int count = 0;

Sierpinski::Sierpinski(int size, int depth)
{
    float sierpinski_height = size * sqrt(3)/2;
//    sierpinski_depth = depth;
 //   sierpinski_size = size;
    
    
    sf::Vector2f p1, p2, p3;
    p1.x = size/2;
    p1.y = 0;
    p2.x = 0;
    p2.y = sierpinski_height;
    p3.x = size;
    p3.y = sierpinski_height;
    
    //Set Initial Triangle
    sf::ConvexShape initial_triangle;
    initial_triangle.setPointCount(3);
    initial_triangle.setPoint(0, p1);
    initial_triangle.setPoint(1, p2);
    initial_triangle.setPoint(2, p3);
    initial_triangle.setFillColor(sf::Color::Yellow);
    
    triangle_vector.push_back(initial_triangle);
    
    if (depth > 0)
    {
        triangle_vector.pop_back();
        Sierpinski(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, depth, size, sierpinski_height);
    }
    
    
    
}


Sierpinski::Sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int depth,
                       float size, float height)
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
         
        Sierpinski(x1, y1, size/4, height/2, ((3 * size)/4), height/2, depth, size/4, height/2);
        Sierpinski(size/4, height/2, x2, y2, x1, height, depth, size/4, height/2);
        Sierpinski(((3 * size)/4), height/2, x1, height, x3, y3, depth, size/4, height/2);
         
     }
     else
     {
         sf::Vector2f p1, p2, p3;
         p1.x = x1;
         p1.y = y1;
         p2.x = x2;
         p2.y = y2;
         p3.x = x3;
         p3.y = y3;
         
        sf::ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, p1);
        triangle.setPoint(1, p2);
        triangle.setPoint(2, p3);
        triangle.setFillColor(sf::Color::Yellow);
         triangle.setOutlineColor(sf::Color::Red);
         triangle.setOutlineThickness(2);
     
        triangle_vector.push_back(triangle);
         count++;
     }
}


Sierpinski::~Sierpinski()
{
    
}


void Sierpinski::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(unsigned int i = 0; i < triangle_vector.size(); i++)
    {
        target.draw(triangle_vector.at(i), states);
    }
}




