#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <SFML/Graphics.hpp>

class Controls
{
private:
    static bool left, right, up, down;

public:
    static void HandleKeyDown(const sf::Event& event);
    static void HandleKeyUp(const sf::Event& event);

    static inline bool Left() { return left; }
    static inline bool Right() { return right; }
    static inline bool Up() { return up; }
    static inline bool Down() { return down; }
};

#endif