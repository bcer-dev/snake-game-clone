#include "Snake.hpp"

Snake::Snake(int gridSquareSize)
    : delta(gridSquareSize, 0), gridSquareSize { gridSquareSize }, snakeColour{ sf::Color::Blue }
{
    sf::Vector2f size(gridSquareSize, gridSquareSize);
    rect.setSize(size);
    rect.setFillColor(sf::Color::Blue);
}

void Snake::Update()
{
    constexpr auto msBetweenMoves = 200;
    auto timeSinceLastMove = movementTimer.getElapsedTime().asMilliseconds();

    if (timeSinceLastMove < msBetweenMoves)
        return;

    for (int i = bodySegments.size() - 1; i > 0; i--)
    {
        auto nextPos = bodySegments[i - 1].getPosition();
        bodySegments[i].setPosition(nextPos);
    }

    if (bodySegments.size() > 0)
        bodySegments[0].setPosition(rect.getPosition());

    auto position = rect.getPosition();
    position += delta;
    rect.setPosition(position);

    movementTimer.restart();
}

// Draw the snake onto the window.
void Snake::DrawTo(sf::RenderWindow& window) const
{
    window.draw(rect);
    for (const auto& segment : bodySegments)
        window.draw(segment);
}

void Snake::PointLeft()
{
    delta.x = -gridSquareSize;
    delta.y = 0;
}

void Snake::PointUp()
{
    delta.x = 0;
    delta.y = -gridSquareSize;
}

void Snake::PointRight()
{
    delta.x = gridSquareSize;
    delta.y = 0;
}

void Snake::PointDown()
{
    delta.x = 0;
    delta.y = gridSquareSize;
}

bool Snake::Touching(const sf::RectangleShape& other) const
{
    return rect.getGlobalBounds().intersects(other.getGlobalBounds());
}

// Add a new body segment to the end of the snake.
void Snake::AddSegment()
{
    sf::Vector2f size(gridSquareSize, gridSquareSize);
    sf::RectangleShape segment(size);
    segment.setFillColor(snakeColour);

    if (bodySegments.size() == 0)
    {
        auto position = rect.getPosition();

        position -= delta;
        segment.setPosition(position);

        bodySegments.push_back(segment);
        return;
    }

    auto position = bodySegments[bodySegments.size() - 1].getPosition();
    position -= delta;
    segment.setPosition(position);

    bodySegments.push_back(segment);
}

// Check if the snake is off the window.
bool Snake::TouchingEdge(const sf::Vector2u& windowSize) const
{
    auto pos = rect.getPosition();
    auto size = rect.getSize();

    bool touchingLeft = pos.x < 0;
    bool touchingTop = pos.y < 0;
    bool touchingRight = pos.x + size.x > windowSize.x;
    bool touchingBottom = pos.y + size.y > windowSize.y;

    return touchingLeft || touchingRight || touchingTop || touchingBottom;
}

// Check if the snakes head has collided with its body.
bool Snake::SelfCollision() const
{
    for (const auto& segment : bodySegments)
    {
        if (Touching(segment))
            return true;
    }

    return false;
}