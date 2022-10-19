#include "Helpers.hpp"

void operator+=(sf::Vector2f& v1, const sf::Vector2f& v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
}