#include <SFML/Graphics.hpp>

int main()
{

    /* sf::Texture texture;
    if (!texture.loadFromFile("assets/pyoro.png"))
    {
        // error
    } */

    const float circleRadius = 10.f;
    float circleR = 255.f;
    float circleG = 255.f;
    float circleB = 255.f;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window To Your Soul");

    sf::CircleShape shape(circleRadius);
    shape.setOrigin(circleRadius, circleRadius);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color if spacebar is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            window.clear(sf::Color::Black);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (circleR < 255.f))
        {
            circleR+=0.01;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (circleG < 255.f))
        {
            circleG+=0.01;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (circleB < 255.f))
        {
            circleB+=0.01;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (circleR > 0.f))
        {
            circleR-=0.01;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (circleG > 0.f))
        {
            circleG-=0.01;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (circleB > 0.f))
        {
            circleB-=0.01;
        }


        shape.setFillColor(sf::Color(circleR, circleG, circleB));

        // draw everything here...
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            window.draw(shape);
        }

        // end the current frame
        window.display();
    }

    return 0;
}