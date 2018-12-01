#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    int x = 0, y = 0;
    float size_x = 1, size_y = 1, x_barrier = 500, y_barrier = 158;
    Font font;
    Text text("Use arrows to move. Press 'S' to shrink and 'G' to grow!", font, 30);
    Texture texture;
    
    font.loadFromFile("sansation.ttf");
    text.setPosition(270, 630);
    RenderWindow window(VideoMode(1000, 1000), "SFML works!");
    window.setPosition(Vector2i(0,0));
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);
    
    //Load a sprite
    if (!texture.loadFromFile("sprite.png"))
    {
        return EXIT_FAILURE;
    }
    Sprite sprite(texture);
    
    while (window.isOpen())
    {
        sprite.setPosition(x, y);
        sprite.setScale(size_x, size_y);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if(Keyboard::isKeyPressed(Keyboard::Left) && x > 0)
        {
            x--;
        }
        if(Keyboard::isKeyPressed(Keyboard::Right) && x < x_barrier)
        {
            x++;
        }
        if(Keyboard::isKeyPressed(Keyboard::Up) && y > 0)
        {
            y--;
        }
        if(Keyboard::isKeyPressed(Keyboard::Down) && y < y_barrier)
        {
            y++;
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            size_x -= .001;
            size_y -= .001;
            x_barrier += .5;
            y_barrier += .5;
        }
        if(Keyboard::isKeyPressed(Keyboard::G))
        {
            size_x += .001;
            size_y += .001;
            x_barrier -= .5;
            y_barrier -= .5;
        }
        
        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }
    
    return 0;
}
