#include "Controls.hpp"

bool Controls::left = false;
bool Controls::right = false;
bool Controls::up = false;
bool Controls::down = false;

void Controls::HandleKeyDown(const sf::Event& event)
{
    if (event.key.code == sf::Keyboard::A)
    {
        left = true;
        return;
    }

    if (event.key.code == sf::Keyboard::W)
    {
        up = true;
        return;
    }

    if (event.key.code == sf::Keyboard::D)
    {
        right = true;
        return;
    }

    if (event.key.code == sf::Keyboard::S)
    {
        down = true;
        return;
    }
}

void Controls::HandleKeyUp(const sf::Event& event)
{
    if (event.key.code == sf::Keyboard::A)
    {
        left = false;
        return;
    }

    if (event.key.code == sf::Keyboard::W)
    {
        up = false;
        return;
    }

    if (event.key.code == sf::Keyboard::D)
    {
        right = false;
        return;
    }

    if (event.key.code == sf::Keyboard::S)
    {
        down = false;
        return;
    }
}