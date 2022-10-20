#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class GameOverScreen
{
private:
    static sf::Text alert;
    static std::unique_ptr<sf::RenderWindow> window;

public:
    static void Init(sf::RenderWindow& windowRef, const sf::Font& font);
    static void Show();
};

#endif