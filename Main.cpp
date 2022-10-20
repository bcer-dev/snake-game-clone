#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

#include "Snake.hpp"
#include "GameOverScreen.hpp"
#include "Controls.hpp"

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

    // Set up window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake Game", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Load font from ./Fonts
    sf::Font fuzzyBubbles;
    if (!fuzzyBubbles.loadFromFile("Fonts/FuzzyBubbles-Bold.ttf"))
    {
        window.close();
        return -1;
    }

    bool gameOver = false;
    GameOverScreen::Init(window, fuzzyBubbles);

    const int gridSquareSize = window.getSize().x / 30;
    Snake snake(gridSquareSize);

    // Spawn food in a random grid square and set score to 0.
    sf::RectangleShape food = CreateFood(gridSquareSize, window.getSize());
    bool moveLeft = false, moveUp = false, moveRight = false, moveDown = false;
    int score = 0;

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
                Controls::HandleKeyDown(event);
                break;

            case sf::Event::KeyReleased:
                Controls::HandleKeyUp(event);
                break;
            }
        }

        // Show the game over screen if the player has lost.
        if (gameOver)
        {
            GameOverScreen::Show();
            continue;
        }

        if (Controls::Left())
            snake.PointLeft();

        if (Controls::Up())
            snake.PointUp();

        if (Controls::Down())
            snake.PointDown();

        if (Controls::Right())
            snake.PointRight();

        // When the snake eats the food, increase score and size, and respawn the food elsewhere.
        if (snake.Touching(food))
        {
            food = CreateFood(gridSquareSize, window.getSize());
            snake.AddSegment();
            score += 25;
        } 

        if (snake.TouchingEdge(window.getSize()) || snake.SelfCollision())
            gameOver = true;

        snake.Update();
        window.clear(backgroundColour);
        snake.DrawTo(window);
        window.draw(food);
        window.display();
    }

    return 0;
}