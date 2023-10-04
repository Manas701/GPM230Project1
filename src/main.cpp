#include <SFML/Graphics.hpp>

int main()
{

    /* sf::Texture texture;
    if (!texture.loadFromFile("assets/pyoro.png"))
    {
        // error
    } */

    const float circleRadius = 10.f;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window To Your Soul");

    sf::CircleShape shape(circleRadius);
    shape.setFillColor(sf::Color(100, 250, 50));
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

        // clear the window with black color
        // window.clear(sf::Color::Black);

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