#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Snake
{
private:
    const int gridSquareSize;
    const sf::Color snakeColour;

    sf::Clock movementTimer;
    sf::RectangleShape rect;
    sf::Vector2f delta;

    std::vector<sf::RectangleShape> bodySegments;

public:
    explicit Snake(int gridSquareSize);
    void Update();
    void DrawTo(sf::RenderWindow& window) const;
    void PointLeft();
    void PointRight();
    void PointUp();
    void PointDown();
    bool Touching(const sf::RectangleShape& other) const;
    bool TouchingEdge(const sf::Vector2u& windowSize) const;
    bool SelfCollision() const;
    void AddSegment();
};

#endif