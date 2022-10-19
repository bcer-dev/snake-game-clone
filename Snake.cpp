#include "Snake.hpp"
#include "Helpers.hpp"

Snake::Snake(int gridSquareSize)
    : delta(gridSquareSize, 0), gridSquareSize {gridSquareSize}
{
    sf::Vector2f size(gridSquareSize, gridSquareSize);
    rect.setSize(size);
    rect.setFillColor(sf::Color::Blue);
}

void Snake::Update()
{
    constexpr auto msBetweenMoves = 300;
    auto timeSinceLastMove = movementTimer.getElapsedTime().asMilliseconds();

    if (timeSinceLastMove < msBetweenMoves)
        return;

    auto position = rect.getPosition();
    position += delta;
    rect.setPosition(position);

    movementTimer.restart();
}

void Snake::DrawTo(sf::RenderWindow& window) const
{
    window.draw(rect);
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