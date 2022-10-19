#include <SFML/Graphics.hpp>
#include "Snake.hpp"

int main()
{
    sf::Color backgroundColour(139, 212, 232);

    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake Game", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    const int gridSquareSize = 600 / 30;
    Snake snake(gridSquareSize);

    bool moveLeft = false, moveUp = false, moveRight = false, moveDown = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A)
                {
                    moveLeft = true;
                    break;
                }

                if (event.key.code == sf::Keyboard::W)
                {
                    moveUp = true;
                    break;
                }

                if (event.key.code == sf::Keyboard::D)
                {
                    moveRight = true;
                    break;
                }

                if (event.key.code == sf::Keyboard::S)
                {
                    moveDown = true;
                    break;
                }

                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::A)
                {
                    moveLeft = false;
                    break;
                }

                if (event.key.code == sf::Keyboard::W)
                {
                    moveUp = false;
                    break;
                }

                if (event.key.code == sf::Keyboard::D)
                {
                    moveRight = false;
                    break;
                }

                if (event.key.code == sf::Keyboard::S)
                {
                    moveDown = false;
                    break;
                }

                break;
            }
        }

        if (moveLeft)
            snake.PointLeft();

        if (moveUp)
            snake.PointUp();

        if (moveDown)
            snake.PointDown();

        if (moveRight)
            snake.PointRight();

        snake.Update();

        window.clear(backgroundColour);
        snake.DrawTo(window);
        window.display();
    }

    return 0;
}