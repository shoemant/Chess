
#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Types.h"

enum class GameState
{
    Playing,
    GameOver
};

class UIManager
{
public:
    UIManager();

    void draw(sf::RenderWindow &window, GameState gameState);

    void displayGameOver(const std::string &message);

    void handleGameOverClick(sf::Vector2i mousePos,
                             std::function<void()> onPlayAgain,
                             std::function<void()> onExit);

private:
    sf::Font font;
    sf::Text gameOverText;
    sf::RectangleShape gameOverOverlay;
    sf::RectangleShape playAgainButton;
    sf::Text playAgainText;
    sf::RectangleShape exitButton;
    sf::Text exitText;
};
