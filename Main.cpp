#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Snake.hpp"

sf::RectangleShape CreateFood(int gridSquareSize, sf::Vector2u windowSize)
{
    sf::RectangleShape food;
    sf::Vector2f size(gridSquareSize, gridSquareSize);

    food.setFillColor(sf::Color::Red);
    food.setSize(size);
    
    auto xPos = (rand() % (windowSize.x / gridSquareSize)) * gridSquareSize;
    auto yPos = (rand() % (windowSize.y / gridSquareSize)) * gridSquareSize;

    food.setPosition(xPos, yPos);

    return food;
}

int main()
{
    srand(time(NULL));
    sf::Color backgroundColour(139, 212, 232);

    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake Game", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    const int gridSquareSize = 600 / 30;
    Snake snake(gridSquareSize);

    sf::RectangleShape food = CreateFood(gridSquareSize, window.getSize());
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

        if (snake.Touching(food))
        {
            food = CreateFood(gridSquareSize, window.getSize());
            snake.AddSegment();
        } 

        if (snake.TouchingEdge(window.getSize()) || snake.SelfCollision())
        {
            return -1;
        }

        window.clear(backgroundColour);
        snake.DrawTo(window);
        window.draw(food);
        window.display();
    }

    return 0;
}