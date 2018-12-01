#ifndef ORIGINAL_H
#define ORIGINAL_H
#include <SFML/Graphics.hpp>
#include <vector>


class original : public sf::Drawable
{
public:
    //Constructors
    
    //define with side length and depth
    original(int size, int depth);
    
    //set up a shape
    original(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,
             int depth, float size, float height);
    
    //Destructor
    ~original();
    
    //Functions
    
    
    
private:
    
    void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const;
    //    float original_depth;
    //    float original_size;
    //    float original_height;
    
};
#endif
