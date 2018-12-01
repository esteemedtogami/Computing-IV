#ifndef SIERPINSKI_H
#define SIERPINSKI_H
#include <SFML/Graphics.hpp>
#include <vector>


class Sierpinski : public sf::Drawable
{
public:
    //Constructors
    
    //define with side length and depth
    Sierpinski(int size, int depth);
    
    //set up a triangle
    Sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int depth, float size, float height);
    
    //Destructor
    ~Sierpinski();
    
    //Functions
   
   
    
private:
    
    void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const;
//    float sierpinski_depth;
//    float sierpinski_size;
//    float sierpinski_height;
    
};
#endif
