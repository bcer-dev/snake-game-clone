#include "GameOverScreen.hpp"

sf::Text GameOverScreen::alert {};
std::unique_ptr<sf::RenderWindow> GameOverScreen::window = nullptr;

// Initialize the game over screen.
void GameOverScreen::Init(sf::RenderWindow& windowRef, const sf::Font& font)
{
    GameOverScreen::window = std::unique_ptr<sf::RenderWindow>(&windowRef);
    alert.setFont(font);
    alert.setString("Game Over!");
    alert.setCharacterSize(32);

    auto alertSize = alert.getLocalBounds();
    alert.setOrigin(alertSize.width / 2, alertSize.height / 2);
    alert.setPosition(windowRef.getSize().x / 2, windowRef.getSize().y / 2);
}

// Show the game over screen
void GameOverScreen::Show()
{
    if (window == nullptr)
        throw std::system_error();
        
    window->clear(sf::Color(38, 255, 215));
    window->draw(alert);
    window->display();
}